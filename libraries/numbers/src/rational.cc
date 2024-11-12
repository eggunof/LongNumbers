
#include "rational.h"

#include <stdexcept>

Rational::Rational(const Integer &numerator, const Natural &denominator)
    : numerator_(numerator), denominator_(denominator) {
  if (denominator_.IsZero()) {
    throw std::invalid_argument("Invalid input: denominator cannot be zero");
  }
}

Rational::Rational(const std::string &string) {
  size_t pos = string.find('/');
  if (pos != std::string::npos) {
    numerator_ = Integer(string.substr(0, pos));
    denominator_ = Natural(string.substr(pos + 1));
  } else {
    numerator_ = Integer(string);
    denominator_ = Natural("1");
  }

  if (denominator_.IsZero()) {
    throw std::invalid_argument("Invalid input: denominator cannot be zero");
  }
}

Rational::operator Integer() const { return {}; }

bool Rational::operator==(const Rational &rhs) const {
    return numerator_ == rhs.numerator_ && denominator_ == rhs.denominator_;
}

bool Rational::operator!=(const Rational &rhs) const {
    return numerator_ != rhs.numerator_ || denominator_ != rhs.denominator_;
}

// Сокращение дроби
// Над модулем работала Дмитриева Дарья, гр. 3383
Rational &Rational::Reduce() {
    Natural GCD = Natural::GreatestCommonDivisor(Natural(numerator_), denominator_);
    if (GCD == Natural("1")) {
        return *this;
    }
    numerator_ /= Integer(GCD);
    denominator_ /= GCD;
    return *this;
}

bool Rational::IsInteger() {
  Reduce();
  return false;
}

Rational Rational::operator+(const Rational &rhs) const { return {}; }

Rational Rational::operator-(const Rational &rhs) const { return {}; }

Rational Rational::operator*(const Rational &rhs) const { return {}; }

Rational Rational::operator/(const Rational &rhs) const { return {}; }

Rational Rational::operator+=(const Rational &rhs) { return {}; }

Rational Rational::operator-=(const Rational &rhs) { return {}; }

Rational Rational::operator*=(const Rational &rhs) { return {}; }

Rational Rational::operator/=(const Rational &rhs) { return {}; }
