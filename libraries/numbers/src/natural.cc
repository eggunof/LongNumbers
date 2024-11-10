
#include "natural.h"

#include <ranges>
#include <stdexcept>

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

bool Natural::IsZero() const { return digits_.size() == 1 && digits_[0] == 0; }

Natural &Natural::operator++() { return *this; }

Natural &Natural::operator++(int) { return *this; }

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

Natural Natural::operator/(const Natural &rhs) const { return {}; }

Natural Natural::operator%(const Natural &rhs) const { return {}; }

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

Natural &Natural::operator/=(const Natural &rhs) { return *this; }

Natural &Natural::operator%=(const Natural &rhs) { return *this; }

Natural &Natural::SubtractMultiplied(const Natural &rhs, Digit d) {
  return *this;
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

// Вычисление первой цифры деления большего натурального на меньшее, домноженное
// на 10^k,где k - номер позиции этой цифры
// Над модулем работала Варфоломеева Арина, гр. 3383
Digit Natural::GetLeadingDigitAfterDivision(const Natural &rhs) {
  // Позиция первой значащей цифры частного (считая от старшего разряда)
  uint32_t k;
  Digit firstDigit = 0;
  Natural bigNatural;
  Natural smallNatural;
  // Левый операнд больше правого
  if (*this > rhs) {
    bigNatural = *this;
    smallNatural = rhs;
  }
  // Левый операнд меньше либо равен правому
  else {
    bigNatural = rhs;
    smallNatural = *this;
  }
  // Вычисляем номер позиции первой цифры при делении натуральных чисел
  k = bigNatural.digits_.size() - smallNatural.digits_.size();
  // Умножаем меньшее натуральное числа на 10^k
  smallNatural.MultiplyBy10Power(k);
  // Пока наибольший операнд больше или равен меньшему
  while (bigNatural >= smallNatural) {
    // Вычитаем меньшее из большего
    bigNatural -= smallNatural;
    // Увеличиваем первую цифру частного
    firstDigit++;
  }
  // Возвращаем первую цифру частного
  return firstDigit;
}

Natural Natural::GreatestCommonDivisor(const Natural &first,
                                       const Natural &second) {
  return {};
}

Natural Natural::LeastCommonMultiple(const Natural &first,
                                     const Natural &second) {
  return {};
}
