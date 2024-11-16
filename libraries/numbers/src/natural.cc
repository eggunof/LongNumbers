
#include "natural.h"

#include <algorithm>
#include <ranges>
#include <sstream>
#include <stdexcept>

Natural::Natural() : digits_(1, 0) {}

Natural::Natural(const std::vector<Digit> &digits) {
  digits_.reserve(digits.size());
  for (Digit digit : digits) {
    if (digit >= kBase) {
      throw std::invalid_argument(
          "Invalid input: digit must be less than base");
    }
    if (!digits_.empty() || digit != 0) {
      digits_.push_back(digit);
    }
  }
  if (digits_.empty()) {
    digits_.push_back(0);
  }
  digits_.shrink_to_fit();
}

Natural::Natural(const std::string &string) {
  digits_.reserve(string.length());
  for (char digit : string) {
    if (std::isspace(digit)) continue;
    Digit x = digit - '0';
    if (x >= kBase) {
      throw std::invalid_argument(
          "Invalid input: non-digit character in string");
    }
    if (!digits_.empty() || x != 0) {
      digits_.push_back(x);
    }
  }
  if (digits_.empty()) {
    digits_.push_back(0);
  }
  digits_.shrink_to_fit();
}

Natural::Natural(uint32_t number) {
  do {
    digits_.push_back(number % kBase);
    number /= kBase;
  } while (number != 0);
  std::reverse(digits_.begin(), digits_.end());
}

bool Natural::IsZero() const { return digits_.size() == 1 && digits_[0] == 0; }

Natural::operator bool() const { return IsZero(); }

Comparison Natural::Compare(const Natural &first, const Natural &second) {
  if (first.digits_.size() > second.digits_.size()) return Comparison::GREATER;
  if (first.digits_.size() < second.digits_.size()) return Comparison::LESS;

  // Если длины чисел равны, сравниваем их поразрядно
  for (int i = 0; i < first.digits_.size(); i++) {
    if (first.digits_[i] > second.digits_[i]) return Comparison::GREATER;
    if (first.digits_[i] < second.digits_[i]) return Comparison::LESS;
  }

  return Comparison::EQUAL;
}

bool Natural::operator==(const Natural &rhs) const {
  return Compare(*this, rhs) == Comparison::EQUAL;
}

bool Natural::operator!=(const Natural &rhs) const { return !(*this == rhs); }

bool Natural::operator<(const Natural &rhs) const {
  return Compare(*this, rhs) == Comparison::LESS;
}

bool Natural::operator>(const Natural &rhs) const { return rhs < *this; }

bool Natural::operator<=(const Natural &rhs) const { return !(*this > rhs); }

bool Natural::operator>=(const Natural &rhs) const { return !(*this < rhs); }

Natural &Natural::operator++() {
  // Изначально добавляем 1
  Digit surplus = 1;
  // Проходим по разрядам числа справа налево
  for (Digit &digit : std::ranges::reverse_view(digits_)) {
    // Если при сложении получается меньше kBase
    if (digit + surplus < kBase) {
      // Складываем с переносом
      digit += surplus;
      // Обнуляем перенос и выходим из цикла
      surplus = 0;
      break;
    }
    // Если при сложении получается kBase
    digit = 0;
  }
  // Если остался перенос, добавляем новый разряд в начало
  if (surplus != 0) {
    digits_.insert(digits_.begin(), 1);
  }
  return *this;
}

Natural Natural::operator++(int) {
  // Сохраняем текущее состояние числа для возвращения
  Natural old_value = *this;
  // Инкремент текущего объекта
  ++(*this);
  // Возвращаем значение до инкремента
  return old_value;
}

Natural &Natural::operator+=(const Natural &rhs) {
  // Если длина правый операнд длиннее левого,
  // добавляем недостающие нули в начало
  if (rhs.digits_.size() > digits_.size()) {
    digits_.insert(digits_.begin(), rhs.digits_.size() - digits_.size(), 0);
  }
  // Перенос в следующий разряд
  Digit surplus = 0;
  // Реверсные итераторы для операндов (справа налево)
  auto lhs_it = digits_.rbegin();
  auto rhs_it = rhs.digits_.rbegin();
  // Обрабатываем разряды, где оба числа имеют значение
  while (rhs_it != rhs.digits_.rend()) {
    // Складываем текущие разряды операндов и перенос
    Digit sum = *lhs_it + *rhs_it + surplus;
    // Заменяем текущий разряд левого операнда на остаток от деления на kBase
    *lhs_it = sum % kBase;
    // Обновляем перенос путём деления нацело суммы
    surplus = sum / kBase;
    ++lhs_it;
    ++rhs_it;
  }
  // Обрабатываем оставшиеся разряды текущего числа, если есть перенос
  while (lhs_it != digits_.rend() && surplus != 0) {
    Digit sum = *lhs_it + surplus;
    // Обновляем текущий разряд с учётом переноса
    *lhs_it = sum % kBase;
    // Обновляем перенос
    surplus = sum / kBase;
    ++lhs_it;
  }
  // Если избыток не равен 0, дописываем его в начало
  if (surplus != 0) {
    digits_.insert(digits_.begin(), surplus);
  }
  return *this;
}

Natural Natural::operator+(const Natural &rhs) const {
  // Складываем копию текущего объекта
  Natural result = *this;
  result += rhs;
  return result;
}

Natural &Natural::operator-=(const Natural &rhs) {
  if (*this < rhs) {
    throw std::invalid_argument(
        "Invalid input: Subtracting a larger number from a smaller one");
  }
  auto lhs_it = digits_.rbegin();
  auto rhs_it = rhs.digits_.rbegin();
  Digit borrow = 0;
  while (rhs_it != rhs.digits_.rend() || borrow) {
    // Получаем текущую цифру из правого операнда (rhs)
    Digit rhs_digit = (rhs_it != rhs.digits_.rend()) ? *rhs_it : 0;
    // Вычитаем текущую цифру rhs_digit из текущего разряда digits_[i]
    int32_t diff = *lhs_it - rhs_digit - borrow;
    if (diff < 0) {
      // Если результат меньше нуля, заимствуем
      *lhs_it = diff + kBase;
      borrow = 1;
    } else {
      // Если результат больше или равен нулю, просто присваиваем
      *lhs_it = diff;
      borrow = 0;
    }
    // Перемещаем итераторы
    if (rhs_it != rhs.digits_.rend()) ++rhs_it;
    ++lhs_it;
  }
  // Удаляем ведущие нули
  while (this->digits_.size() > 1 && this->digits_[0] == 0) {
    this->digits_.erase(this->digits_.begin());
  }
  return *this;
}

Natural Natural::operator-(const Natural &rhs) const {
  // Вычитаем копию текущего объекта
  Natural result = *this;
  result -= rhs;
  return result;
}

Natural &Natural::operator*=(Digit d) {
  if (d == 0) {
    digits_ = {0};
    return *this;
  }
  // избыток
  Digit surplus = 0;
  for (Digit &digit : std::ranges::reverse_view(digits_)) {
    // умножаем текущую цифру + избыток от предыдущего действия
    Digit product = digit * d + surplus;
    // и находим остаток от kBase - это наша новая цифра
    digit = product % kBase;
    // считаем избыток через деления нацело
    surplus = product / kBase;
  }
  // если после всех вычислений избыток не равен 0, то нужно дописать его
  if (surplus > 0) {
    digits_.insert(digits_.begin(), surplus);
  }
  return *this;
}

Natural Natural::operator*(Digit d) const {
  // Умножаем копию текущего объекта
  Natural result = *this;
  result *= d;
  return result;
}

Natural &Natural::operator*=(const Natural &rhs) {
  // При умножении на ноль произведение равно нулю
  if (IsZero() || rhs.IsZero()) {
    digits_ = {0};
    return *this;
  }

  Natural result;
  size_t rhs_size = rhs.digits_.size();
  for (size_t i = 0; i < rhs_size; ++i) {
    // Пропускаем умножение на 0
    if (rhs.digits_[i] == 0) continue;

    Natural tmp = *this;
    // Умножаем на цифру
    tmp *= rhs.digits_[i];
    // Сдвигаем на порядок
    tmp.MultiplyByBasePower(rhs_size - i - 1);
    // Добавляем к результату
    result += tmp;
  }
  *this = result;
  return *this;
}

Natural Natural::operator*(const Natural &rhs) const {
  // Умножаем копию текущего объекта
  Natural result = *this;
  result *= rhs;
  return result;
}

Natural &Natural::operator/=(const Natural &rhs) {
  auto quotient = Natural(0);
  // Пока в делимом есть хотя бы один делитель
  while (*this >= rhs) {
    // Получаем цифру частного и её позицию
    std::pair<Digit, uint32_t> division_result = GetLeadingQuotientDigit(rhs);
    // Вычитаем из делимого цифру, умноженную на произведение делителя и kBase^k
    SubtractMultiplied(rhs.MultiplyByBasePower(division_result.second),
                       division_result.first);
    // Добавляем к частному полученную цифру, умноженную на kBase^k
    quotient += Natural(division_result.first)
                    .MultiplyByBasePower(division_result.second);
  }
  // Записываем частное в текущее число
  *this = quotient;
  return *this;
}

Natural Natural::operator/(const Natural &rhs) const {
  // Вычисляем частное от деления копии
  Natural result = *this;
  result /= rhs;
  return result;
}

Natural &Natural::operator%=(const Natural &rhs) {
  Natural quotient = *this / rhs;
  *this -= rhs * quotient;
  return *this;
}

Natural Natural::operator%(const Natural &rhs) const {
  // Вычисляем остаток от деления копии
  Natural result = *this;
  result %= rhs;
  return result;
}

Natural &Natural::SubtractMultiplied(const Natural &rhs, Digit d) {
  // Считаем вычитаемое
  Natural subtrahend = rhs * d;
  *this -= subtrahend;
  return *this;
}

Natural Natural::SubtractMultiplied(const Natural &rhs, Digit d) const {
  Natural result = *this;
  result.SubtractMultiplied(rhs, d);
  return result;
}

Natural &Natural::MultiplyByBasePower(uint32_t k) {
  // если текущее число равно 0, оно не должно измениться
  if (this->IsZero()) {
    return *this;
  }
  // умножение числа на kBase^k - то же, что и дописывание в конец k нулей
  digits_.insert(digits_.end(), k, 0);
  return *this;
}

Natural Natural::MultiplyByBasePower(uint32_t k) const {
  Natural result = *this;
  result.MultiplyByBasePower(k);
  return result;
}

std::pair<Digit, uint32_t> Natural::GetLeadingQuotientDigit(
    const Natural &rhs) const {
  // Проверяем, не является ли делитель нулём
  if (rhs.IsZero()) {
    throw std::invalid_argument(
        "Invalid input: Division by zero is not allowed");
  }
  // Если делим меньшее на большее, возвращаем {0, 0}
  if (*this < rhs) {
    return {0, 0};
  }
  // Вычисляем номер позиции первой цифры при делении
  uint32_t k = digits_.size() - rhs.digits_.size();
  // Проверяем, нужно ли уменьшить k на 1
  if (k > 0) {
    for (size_t i = 0; i < digits_.size(); ++i) {
      Digit rhs_digit = i < rhs.digits_.size() ? rhs.digits_[i] : 0;
      // Если цифра делимого больше цифры делителя, то не нужно
      if (digits_[i] > rhs_digit) break;
      // Если цифра делимого меньше цифры делителя, то уменьшаем
      if (digits_[i] < rhs_digit) {
        --k;
        break;
      }
    }
  }
  Digit first_digit = 0;
  // Копируем текущее число
  Natural divisible = *this;
  // Умножаем правый операнд на kBase^k
  Natural divider = rhs.MultiplyByBasePower(k);
  // Пока наибольший операнд больше или равен меньшему
  while (divisible >= divider) {
    // Вычитаем меньшее из большего
    divisible -= divider;
    // Увеличиваем первую цифру частного
    ++first_digit;
  }
  // Возвращаем первую цифру частного и её позицию
  return {first_digit, k};
}

Natural Natural::GreatestCommonDivisor(const Natural &first,
                                       const Natural &second) {
  // Копируем числа
  Natural a = first;
  Natural b = second;
  // Применим алгоритм Евклида
  // Пока одно из чисел не станет равным нулю, продолжаем делить
  while (!b.IsZero()) {
    // Находим остаток от деления первого на второе
    Natural remainder = a % b;
    // Первое становится вторым
    a = b;
    // Второе становится остатком
    b = remainder;
  }
  // Возвращается НОД
  return a;
}

Natural Natural::LeastCommonMultiple(const Natural &first,
                                     const Natural &second) {
  // Вычисляем НОД двух чисел
  Natural gcd = GreatestCommonDivisor(first, second);
  Natural lcm = (first * second) / gcd;
  return lcm;
}

std::istream &operator>>(std::istream &is, Natural &number) {
  is >> std::ws;
  number.digits_.clear();
  while (true) {
    uint8_t c = is.get();
    if (std::isspace(c)) continue;
    if (!is.good() || !std::isdigit(c)) break;
    Digit digit = c - '0';
    if (digit != 0 || !number.digits_.empty()) {
      number.digits_.push_back(digit);
    }
  }
  if (number.digits_.empty()) {
    number.digits_.push_back(0);
  }
  number.digits_.shrink_to_fit();
  return is;
}

std::ostream &operator<<(std::ostream &os, const Natural &number) {
  for (Digit digit : number.digits_) {
    os << static_cast<int16_t>(digit);
  }
  return os;
}

std::string Natural::ToString() const {
  std::ostringstream result;
  result << *this;
  return result.str();
}
