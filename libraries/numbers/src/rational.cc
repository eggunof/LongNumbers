
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

bool Rational::operator==(const Rational &rhs) const {
    return numerator_ == rhs.numerator_ && denominator_ == rhs.denominator_;
}

bool Rational::operator!=(const Rational &rhs) const {
    return numerator_ != rhs.numerator_ || denominator_ != rhs.denominator_;
}

bool Rational::operator<(const Rational &rhs) const {
    if (denominator_ == rhs.denominator_) {
        return numerator_ < rhs.numerator_;
    }
    // Находим НОК для знаменателей
    Natural lcm_denominator = Natural::LeastCommonMultiple(denominator_, rhs.denominator_);

    // Приводим обе дроби к общему знаменателю
    Integer left_numerator = numerator_ * Integer(lcm_denominator / denominator_);
    Integer right_numerator = rhs.numerator_ * Integer(lcm_denominator / rhs.denominator_);

    // Сравниваем числители
    return left_numerator < right_numerator;
}

bool Rational::operator>(const Rational &rhs) const {
    return rhs < *this; // Используем оператор <
}

bool Rational::operator<=(const Rational &rhs) const {
    return !(*this > rhs); // Используем оператор >
}

bool Rational::operator>=(const Rational &rhs) const {
    return !(*this < rhs); // Используем оператор <
}

Rational::operator Integer() const { return {}; }

Rational &Rational::Reduce() { return *this; }

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
