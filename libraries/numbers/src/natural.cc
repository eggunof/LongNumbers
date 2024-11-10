
#include "natural.h"

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

Comparison Natural::Compare(const Natural &first, const Natural &second) {
  return Comparison::EQUAL;
}

bool Natural::operator==(const Natural &rhs) const { return false; }

bool Natural::operator!=(const Natural &rhs) const { return false; }

bool Natural::operator<(const Natural &rhs) const { return false; }

bool Natural::operator>(const Natural &rhs) const { return false; }

bool Natural::operator<=(const Natural &rhs) const { return false; }

bool Natural::operator>=(const Natural &rhs) const { return false; }

bool Natural::IsZero() const { return digits_.size() == 1 && digits_[0] == 0; }

Natural &Natural::operator++() { return *this; }

Natural &Natural::operator++(int) { return *this; }

// Сложение натуральных чисел "+"
// Над модулем работала Варфоломеева Арина, гр. 3383
Natural Natural::operator+(const Natural &rhs) const {
  // Создаем копию текущего объекта для хранения результата
  Natural result = *this;
  // Если длина правого операнда (rhs) больше, чем длина текущего,
  // добавляем недостающие нули в начало
  if (rhs.digits_.size() > result.digits_.size()) {
    result.digits_.insert(result.digits_.begin(),
                          rhs.digits_.size() - result.digits_.size(), 0);
  }
  // Перенос в следующий разряд
  Digit surplus = 0;
  // Изначальное значение разряда левого операнда,
  // значение разряда правого операнда
  Digit old_digit, rhs_digit;
  // Реверсные итераторы для операндов (справо налево)
  auto lhs_it = result.digits_.rbegin();
  auto rhs_it = rhs.digits_.rbegin();
  // Обрабатываем разряды, где оба числа имеют значение
  while (rhs_it != rhs.digits_.rend()) {
    old_digit = *lhs_it;
    rhs_digit = *rhs_it;
    // Складываем текущие разряды операндов и перенос;
    // Заменяем текущий разряд левого операнда на остаток от деления на 10
    *lhs_it = (old_digit + rhs_digit + surplus) % 10;
    // Обновляем перенос путём деления нацело суммы разрядов операндов и
    // переноса
    surplus = (old_digit + rhs_digit + surplus) / 10;
    ++lhs_it;
    ++rhs_it;
  }
  // Обрабатываем оставшиеся разряды текущего числа, если есть перенос
  while (lhs_it != result.digits_.rend() && surplus != 0) {
    old_digit = *lhs_it;
    // Обновляем текущий разряд с учётом переноса
    *lhs_it = (old_digit + surplus) % 10;
    // Обновляем перенос
    surplus = (old_digit + surplus) / 10;
    ++lhs_it;
  }
  // Если избыток не равен 0, дописываем его в начало
  if (surplus != 0) {
    result.digits_.insert(result.digits_.begin(), surplus);
  }
  return result;
}

Natural Natural::operator-(const Natural &rhs) const { return {}; }

Natural Natural::operator*(Digit d) const { return {}; }

Natural Natural::operator*(const Natural &rhs) const { return {}; }

Natural Natural::operator/(const Natural &rhs) const { return {}; }

Natural Natural::operator%(const Natural &rhs) const { return {}; }

// Сложение натуральных чисел "+="
// Над модулем работала Варфоломеева Арина, гр. 3383
Natural &Natural::operator+=(const Natural &rhs) {
  // Если длина правого операнда (rhs) больше, чем длина текущего,
  // добавляем недостающие нули в начало
  if (rhs.digits_.size() > digits_.size()) {
    digits_.insert(digits_.begin(), rhs.digits_.size() - digits_.size(), 0);
  }
  // Перенос в следующий разряд
  Digit surplus = 0;
  // Изначальное значение разряда левого операнда,
  // значение разряда правого операнда
  Digit old_digit, rhs_digit;
  // Реверсные итераторы для операндов (справо налево)
  auto lhs_it = digits_.rbegin();
  auto rhs_it = rhs.digits_.rbegin();
  // Обрабатываем разряды, где оба числа имеют значение
  while (rhs_it != rhs.digits_.rend()) {
    old_digit = *lhs_it;
    rhs_digit = *rhs_it;
    // Складываем текущие разряды операндов и перенос;
    // Заменяем текущий разряд левого операнда на остаток от деления на 10
    *lhs_it = (old_digit + rhs_digit + surplus) % 10;
    // Обновляем перенос путём деления нацело суммы разрядов операндов и
    // переноса
    surplus = (old_digit + rhs_digit + surplus) / 10;
    ++lhs_it;
    ++rhs_it;
  }
  // Обрабатываем оставшиеся разряды текущего числа, если есть перенос
  while (lhs_it != digits_.rend() && surplus != 0) {
    old_digit = *lhs_it;
    // Обновляем текущий разряд с учётом переноса
    *lhs_it = (old_digit + surplus) % 10;
    // Обновляем перенос
    surplus = (old_digit + surplus) / 10;
    ++lhs_it;
  }
  // Если избыток не равен 0, дописываем его в начало
  if (surplus != 0) {
    digits_.insert(digits_.begin(), surplus);
  }
  return *this;
}

Natural &Natural::operator-=(const Natural &rhs) { return *this; }

Natural &Natural::operator*=(Digit d) { return *this; }

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
