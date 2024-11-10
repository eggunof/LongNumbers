
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

Integer Integer::operator-() const { return {}; }

Integer &Integer::operator-() { return *this; }

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
