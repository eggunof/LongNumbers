
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

// Преобразование целого неотрицательного в натуральное
// Над модулем работала Варфоломеева Арина, гр. 3383
Integer::operator Natural() const {
  // если число равно 0,
  // возвращаем Natural, представляющий число 1
  if (sign_ == Sign::ZERO) {
    return Natural("1");  // Возвращаем Natural, представляющий число 1
  }
  // Иначе возвращаем без изменений
  return natural_;
}

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

Integer Integer::operator/(const Integer &rhs) const { return {}; }

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

Integer &Integer::operator/=(const Integer &rhs) { return *this; }

Integer &Integer::operator%=(const Integer &rhs) { return *this; }
