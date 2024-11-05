
#include "rational.h"

Rational::Rational(const std::string &string) {

}

Integer Rational::ToInteger(const Rational &rational) {
  return {};
}

Rational &Rational::Reduce() {
  return *this;
}

bool Rational::IsInteger() {
  Reduce();
  return false;
}

Rational Rational::operator+(const Rational &rhs) const {
  return {};
}

Rational Rational::operator-(const Rational &rhs) const {
  return {};
}

Rational Rational::operator*(const Rational &rhs) const {
  return {};
}

Rational Rational::operator/(const Rational &rhs) const {
  return {};
}

Rational Rational::operator+=(const Rational &rhs) {
  return {};
}

Rational Rational::operator-=(const Rational &rhs) {
  return {};
}

Rational Rational::operator*=(const Rational &rhs) {
  return {};
}

Rational Rational::operator/=(const Rational &rhs) {
  return {};
}
