
#include "integer.h"

Integer::Integer(const std::string &string) {

}

Integer::Integer(const Natural &natural) : Natural(natural), sign_(Sign::POSITIVE) {}

Natural Integer::ToNatural(const Integer &integer) {
  return {};
}

Integer Integer::AbsoluteValue(const Integer &integer) {
  return {};
}

Integer Integer::operator-() const {
  return {};
}

Integer &Integer::operator-() {
  return *this;
}

Integer Integer::operator+(const Integer &rhs) const {
  return {};
}

Integer Integer::operator-(const Integer &rhs) const {
  return {};
}

Integer Integer::operator*(const Integer &rhs) const {
  return {};
}

Integer Integer::operator/(const Integer &rhs) const {
  return {};
}

Integer Integer::operator%(const Integer &rhs) const {
  return {};
}

Integer &Integer::operator+=(const Integer &rhs) {
  return *this;
}

Integer &Integer::operator-=(const Integer &rhs) {
  return *this;
}

Integer &Integer::operator*=(const Integer &rhs) {
  return *this;
}

Integer &Integer::operator/=(const Integer &rhs) {
  return *this;
}

Integer &Integer::operator%=(const Integer &rhs) {
  return *this;
}
