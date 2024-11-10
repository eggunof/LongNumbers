
#include "integer.h"

#include <algorithm>

Integer::Integer(const std::vector<Digit> &digits, Sign sign)
    : natural_(digits), sign_(sign) {
  if (natural_.IsZero()) {
    sign_ = Sign::ZERO;
  }
}

Integer::Integer(const std::string &string)
    : natural_(string.substr(string.find_first_not_of("+-"))) {
  if (natural_.IsZero()) {
    sign_ = Sign::ZERO;
  } else {
    size_t minus_count = std::count_if(string.begin(), string.end(),
                                       [](char c) { return c == '-'; });
    sign_ = (minus_count % 2 == 0) ? Sign::POSITIVE : Sign::NEGATIVE;
  }
}

Integer::Integer(const Natural &natural) {}

Integer::operator Natural() const { return {}; }

Integer Integer::AbsoluteValue(const Integer &integer) { return {}; }

bool Integer::operator==(const Integer &rhs) const {
  return natural_ == rhs.natural_ && sign_ == rhs.sign_;
}

bool Integer::operator!=(const Integer &rhs) const { return !(rhs == *this); }

bool Integer::operator<(const Integer &rhs) const {
  if (sign_ < rhs.sign_) return true;
  if (sign_ > rhs.sign_) return false;
  return natural_ < rhs.natural_;
}

bool Integer::operator>(const Integer &rhs) const { return rhs < *this; }

bool Integer::operator<=(const Integer &rhs) const { return !(rhs < *this); }

bool Integer::operator>=(const Integer &rhs) const { return !(*this < rhs); }

Integer Integer::operator-() const { return {}; }

Integer &Integer::operator-() { return *this; }

Integer Integer::operator+(const Integer &rhs) const { return {}; }

Integer Integer::operator-(const Integer &rhs) const { return {}; }

// Умножение целых чисел "*"
// Над модулем работала Майская Вероника, гр. 3384
Integer Integer::operator*(const Integer &rhs) const {
  Integer result = *this;
  result *= rhs;
  return result;
}

// Частное от деления целого на целое (делитель отличен от нуля) "/"
// Над модулем работала Майская Вероника, гр. 3384
Integer Integer::operator/(const Integer &rhs) const {
    Integer result = *this;
    result /= rhs;
    return result;
}

Integer Integer::operator%(const Integer &rhs) const { return {}; }

Integer &Integer::operator+=(const Integer &rhs) { return *this; }

Integer &Integer::operator-=(const Integer &rhs) { return *this; }

// Умножение целых чисел "*="
// Над модулем работала Майская Вероника, гр. 3384
Integer &Integer::operator*=(const Integer &rhs) {
  // Перемножаем натуральные части
  natural_ *= rhs.natural_;
  // Определяем знак результата
  sign_ = (sign_ == rhs.sign_) ? Sign::POSITIVE : Sign::NEGATIVE;
  if (natural_.IsZero()) sign_ = Sign::ZERO;
  return *this;
}

// Частное от деления целого на целое (делитель отличен от нуля) "/="
// Над модулем работала Майская Вероника, гр. 3384
Integer &Integer::operator/=(const Integer &rhs) {
    // Проверка на деление на ноль
    if (rhs.sign_ == Sign::ZERO) {
        throw std::invalid_argument("Division by zero");
    }
    // Определяем знак результата
    Sign result_sign = (this->sign_ == rhs.sign_) ? Sign::POSITIVE : Sign::NEGATIVE;
    // Вычисляем модули делимого и делителя
    Integer abs_dividend = AbsoluteValue(*this);
    Integer abs_divisor = AbsoluteValue(rhs);
    // Выполняем деление для натуральных чисел, используя натуральную часть Integer
    this->natural_ = abs_dividend.natural_ / abs_divisor.natural_;
    // Устанавливаем знак результата
    this->sign_ = (this->natural_ == Natural(0)) ? Sign::ZERO : result_sign;
    return *this;
}

Integer &Integer::operator%=(const Integer &rhs) { return *this; }
