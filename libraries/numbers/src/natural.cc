
#include "natural.h"

#include <ranges>
#include <sstream>
#include <stdexcept>

Natural::Natural() : digits_(1, 0) {}

Natural::Natural(const std::vector<Digit> &digits) {
  if (digits.empty()) {
    throw std::invalid_argument("Invalid input: vector must not be empty");
  }
  digits_.reserve(digits.size());
  for (Digit digit : digits) {
    if (digit >= 10) {
      throw std::invalid_argument("Invalid input: digit must be less than 10");
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
  if (string.empty()) {
    throw std::invalid_argument(
        "Invalid input: string must contain at least one digit");
  }
  digits_.reserve(string.length());
  for (char digit : string) {
    if (std::isspace(digit)) continue;
    Digit x = digit - '0';
    if (x >= 10) {
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

Natural::Natural(uint32_t number) : Natural(std::to_string(number)) {}

bool Natural::IsZero() const { return digits_.size() == 1 && digits_[0] == 0; }

// Сравнение натуральных чисел
// Над модулем работала Майская Вероника, гр. 3384
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

// Инкремент натурального числа "++n"
// Над модулем работала Солдунова Екатерина, гр. 3383
Natural &Natural::operator++() {
  // Изначально добавляем 1
  Digit surplus = 1;
  // Проходим по разрядам числа справа налево
  for (Digit &digit : std::ranges::reverse_view(digits_)) {
    // Если при сложении получается меньше 10
    if (digit + surplus < 10) {
      // Складываем с переносом
      digit += surplus;
      // Обнуляем перенос и выходим из цикла
      surplus = 0;
      break;
    }
    // Если при сложении получается 10
    digit = 0;
  }
  // Если остался перенос, добавляем новый разряд в начало
  if (surplus != 0) {
    digits_.insert(digits_.begin(), 1);
  }
  return *this;
}

// Сложение натуральных чисел "+="
// Над модулем работала Варфоломеева Арина, гр. 3383
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
    // Заменяем текущий разряд левого операнда на остаток от деления на 10
    *lhs_it = sum % 10;
    // Обновляем перенос путём деления нацело суммы
    surplus = sum / 10;
    ++lhs_it;
    ++rhs_it;
  }
  // Обрабатываем оставшиеся разряды текущего числа, если есть перенос
  while (lhs_it != digits_.rend() && surplus != 0) {
    Digit sum = *lhs_it + surplus;
    // Обновляем текущий разряд с учётом переноса
    *lhs_it = sum % 10;
    // Обновляем перенос
    surplus = sum / 10;
    ++lhs_it;
  }
  // Если избыток не равен 0, дописываем его в начало
  if (surplus != 0) {
    digits_.insert(digits_.begin(), surplus);
  }
  return *this;
}

// Вычитание натуральных чисел "-="
// Над модулем работала Дмитриева Дарья, гр. 3383
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
      *lhs_it = diff + 10;
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

// Умножение натуральных чисел на цифру "*="
// Над модулем работал Матвеев Никита, гр. 3383
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
    // и находим остаток от 10 - это наша новая цифра
    digit = product % 10;
    // считаем избыток через деления нацело
    surplus = product / 10;
  }
  // если после всех вычислений избыток не равен 0, то нужно дописать его
  if (surplus > 0) {
    digits_.insert(digits_.begin(), surplus);
  }
  return *this;
}

// Умножение натуральных чисел "*="
// Над модулем работал Егунов Даниил, гр. 3383
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
    tmp.MultiplyBy10Power(rhs_size - i - 1);
    // Добавляем к результату
    result += tmp;
  }
  *this = result;
  return *this;
}

// Целое от деления натуральных чисел "/="
// Над модулем работала Дмитриева Дарья, гр. 3383
Natural &Natural::operator/=(const Natural &rhs) {
  auto quotient = Natural(0);
  // Пока в делимом есть хотя бы один делитель
  while (*this >= rhs) {
    // Получаем цифру частного и её позицию
    std::pair<Digit, uint32_t> division_result = GetLeadingQuotientDigit(rhs);
    // Вычитаем из делимого цифру, умноженную на произведение делителя и 10^k
    SubtractMultiplied(rhs.MultiplyBy10Power(division_result.second),
                       division_result.first);
    // Добавляем к частному полученную цифру, умноженную на 10^k
    quotient += Natural(division_result.first)
                    .MultiplyBy10Power(division_result.second);
  }
  // Записываем частное в текущее число
  *this = quotient;
  return *this;
}

// Остаток от деления натуральных чисел "%="
// Над модулем работал Егунов Даниил, гр. 3383
Natural &Natural::operator%=(const Natural &rhs) {
  Natural quotient = *this / rhs;
  *this -= rhs * quotient;
  return *this;
}

// Инкремент натурального числа "n++"
// Над модулем работала Солдунова Екатерина, гр. 3383
Natural Natural::operator++(int) {
  // Сохраняем текущее состояние числа для возвращения
  Natural old_value = *this;
  // Инкремент текущего объекта
  ++(*this);
  // Возвращаем значение до инкремента
  return old_value;
}

// Сложение натуральных чисел "+"
// Над модулем работала Варфоломеева Арина, гр. 3383
Natural Natural::operator+(const Natural &rhs) const {
  // Складываем копию текущего объекта
  Natural result = *this;
  result += rhs;
  return result;
}

// Вычитание натуральных чисел "-"
// Над модулем работала Дмитриева Дарья, гр. 3383
Natural Natural::operator-(const Natural &rhs) const {
  // Вычитаем копию текущего объекта
  Natural result = *this;
  result -= rhs;
  return result;
}

// Умножение натуральных чисел на цифру "*"
// Над модулем работал Матвеев Никита, гр. 3383
Natural Natural::operator*(Digit d) const {
  // Умножаем копию текущего объекта
  Natural result = *this;
  result *= d;
  return result;
}

// Умножение натуральных чисел "*"
// Над модулем работал Егунов Даниил, гр. 3383
Natural Natural::operator*(const Natural &rhs) const {
  // Умножаем копию текущего объекта
  Natural result = *this;
  result *= rhs;
  return result;
}

// Целое от деления натуральных чисел "/"
// Над модулем работала Дмитриева Дарья, гр. 3383
Natural Natural::operator/(const Natural &rhs) const {
  // Вычисляем частное от деления копии
  Natural result = *this;
  result /= rhs;
  return result;
}

// Остаток от деления натуральных чисел "%"
// Над модулем работал Егунов Даниил, гр. 3383
Natural Natural::operator%(const Natural &rhs) const {
  // Вычисляем остаток от деления копии
  Natural result = *this;
  result %= rhs;
  return result;
}

// Вычитание из натурального умноженного на цифру натурального
// Над модулем работала Солдунова Екатерина, гр. 3383
Natural &Natural::SubtractMultiplied(const Natural &rhs, Digit d) {
  // Считаем вычитаемое
  Natural subtrahend = rhs * d;
  if (*this < subtrahend) {
    throw std::invalid_argument(
        "Invalid input: Subtracting a larger number from a smaller one");
  }
  // Если получившееся число не больше уменьшаемого, производим вычитание
  *this -= subtrahend;
  return *this;
}

// Умножение натурального числа на 10 в k-ой степени
// Над модулем работала Кривошеина Дарья, гр. 3383
Natural Natural::MultiplyBy10Power(uint32_t k) const {
  Natural result = *this;
  result.MultiplyBy10Power(k);
  return result;
}

// Умножение натурального числа на 10 в k-ой степени
// Над модулем работала Кривошеина Дарья, гр. 3383
Natural &Natural::MultiplyBy10Power(uint32_t k) {
  // если текущее число равно 0, оно не должно измениться
  if (this->IsZero()) {
    return *this;
  }
  // умножение числа на 10^k - то же, что и дописывание в конец k нулей
  digits_.insert(digits_.end(), k, 0);
  return *this;
}

// Вычисление первой цифры деления на натуральное, домноженное на 10^k
// Над модулем работала Варфоломеева Арина, гр. 3383
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
  // Умножаем правый операнд на 10^k
  Natural divider = rhs.MultiplyBy10Power(k);
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

// Наибольший общий делитель натуральных чисел
// Над модулем работала Кадникова Анна, гр. 3384
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

// НОК натуральных чисел
// Над модулем работала Майская Вероника, гр. 3384
Natural Natural::LeastCommonMultiple(const Natural &first,
                                     const Natural &second) {
  // Вычисляем НОД двух чисел
  Natural gcd = GreatestCommonDivisor(first, second);
  Natural lcm = (first * second) / gcd;
  return lcm;
}

Natural::operator std::string() const {
  std::ostringstream result;
  for (Digit digit : digits_) {
    result << static_cast<int>(digit);
  }
  return result.str();
}
