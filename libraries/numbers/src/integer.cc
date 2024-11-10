
#include "integer.h"

#include <algorithm>

Integer::Integer(const std::vector<Digit> &digits, Sign sign)
    : Natural(digits), sign_(sign) {
  if (IsZero()) {
    sign_ = Sign::ZERO;
  }
}

Integer::Integer(const std::string &string)
    : Natural(string.substr(string.find_first_not_of("+-"))) {
  if (IsZero()) {
    sign_ = Sign::ZERO;
  } else {
    size_t minus_count = std::count_if(string.begin(), string.end(),
                                       [](char c) { return c == '-'; });
    sign_ = (minus_count % 2 == 0) ? Sign::POSITIVE : Sign::NEGATIVE;
  }
}

Integer::Integer(const Natural &natural) {}

Natural Integer::ToNatural(const Integer &integer) { return {}; }

Integer Integer::AbsoluteValue(const Integer &integer) { return {}; }

// Умножение целых чисел на -1
// Над модулем работал Матвеев Никита, гр. 3383
Integer Integer::operator-() const {
  // Копия умножается на -1 и возвращается
  Integer result = *this;
  return -result;
}

// Умножение целых чисел на -1
// Над модулем работал Матвеев Никита, гр. 3383
Integer &Integer::operator-() {
  if (sign_ == Sign::NEGATIVE) {
    // Если знак был "-", то становится "+"
    sign_ = Sign::POSITIVE;
  } else if (sign_ == Sign::POSITIVE) {
    // Если знак был "+", то становится "-"
    sign_ = Sign::NEGATIVE;
  }
  return *this;
}

Integer Integer::operator+(const Integer &rhs) const { return {}; }

Integer Integer::operator-(const Integer &rhs) const { return {}; }

Integer Integer::operator*(const Integer &rhs) const { return {}; }

Integer Integer::operator/(const Integer &rhs) const { return {}; }

Integer Integer::operator%(const Integer &rhs) const { return {}; }

Integer &Integer::operator+=(const Integer &rhs) { return *this; }

Integer &Integer::operator-=(const Integer &rhs) { return *this; }

Integer &Integer::operator*=(const Integer &rhs) { return *this; }

Integer &Integer::operator/=(const Integer &rhs) { return *this; }

Integer &Integer::operator%=(const Integer &rhs) { return *this; }
