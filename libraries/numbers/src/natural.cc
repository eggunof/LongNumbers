
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

bool Natural::operator>(const Natural &rhs) const {
  return Compare(*this, rhs) == Comparison::GREATER;
}

bool Natural::operator<=(const Natural &rhs) const { return !(*this > rhs); }

bool Natural::operator>=(const Natural &rhs) const { return !(*this < rhs); }

bool Natural::IsZero() const { return digits_.size() == 1 && digits_[0] == 0; }

Natural &Natural::operator++() { return *this; }

Natural &Natural::operator++(int) { return *this; }

// Сложение натуральных чисел "+"
// Над модулем работала Варфоломеева Арина, гр. 3383
Natural Natural::operator+(const Natural &rhs) const {
  // Создаём копию текущего объекта для хранения результата
  Natural result = *this;
  result += rhs;
  return result;
}

Natural Natural::operator-(const Natural &rhs) const { return {}; }

// Умножение натуральных чисел на цифру "*"
// Над модулем работал Матвеев Никита, гр. 3383
Natural Natural::operator*(Digit d) const {
  // умножаем копию текущего числа на цифру
  Natural result = *this;
  result *= d;
  return result;
}

Natural Natural::operator*(const Natural &rhs) const { return {}; }

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

Natural &Natural::operator-=(const Natural &rhs) { return *this; }

// Умножение натуральных чисел на цифру "*="
// Над модулем работал Матвеев Никита, гр. 3383
Natural &Natural::operator*=(Digit d) {
  if (d == 0) {
    digits_.clear();
    digits_.push_back(0);
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

Natural &Natural::operator*=(const Natural &rhs) { return *this; }

Natural &Natural::operator/=(const Natural &rhs) { return *this; }

Natural &Natural::operator%=(const Natural &rhs) { return *this; }

Natural &Natural::SubtractMultiplied(const Natural &rhs, Digit d) {
  return *this;
}

Natural &Natural::MultiplyBy10Power(uint32_t k) { return *this; }

Digit Natural::GetLeadingDigitAfterDivision(const Natural &rhs, uint32_t k) {
  return {};
}

Natural Natural::GreatestCommonDivisor(const Natural &first,
                                       const Natural &second) {
  return {};
}

Natural Natural::LeastCommonMultiple(const Natural &first,
                                     const Natural &second) {
  return {};
}
