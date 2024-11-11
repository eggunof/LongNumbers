
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

Rational &Rational::Reduce() { return *this; }

bool Rational::IsInteger() {
  Reduce();
  return false;
}

Rational Rational::operator+(const Rational &rhs) const { return {}; }

Rational Rational::operator-(const Rational &rhs) const { return {}; }

Rational Rational::operator*(const Rational &rhs) const { return {}; }

// Деление дробей (делитель отличен от нуля) "/"
// Над модулем работала Варфоломеева Арина, гр. 3383
Rational Rational::operator/(const Rational &rhs) const {
  Rational result = *this;
  result /= rhs;
  return result;
}

Rational Rational::operator+=(const Rational &rhs) { return {}; }

Rational Rational::operator-=(const Rational &rhs) { return {}; }

Rational Rational::operator*=(const Rational &rhs) { return {}; }

// Деление дробей (делитель отличен от нуля) "/="
// Над модулем работала Варфоломеева Арина, гр. 3383
Rational Rational::operator/=(const Rational &rhs) {
  Rational result;
  // Определяем знак, сравнив знаки числителей
  // Если они равны, то дробь положительна, иначе отрицательная
  if (numerator_.sigh_ == rhs.numerator_.sigh_) {
    numerator_.sigh_ = Sigh::POSITIVE;
  } else if (numerator_.sigh_ == Sigh::ZERO) {
    numerator_.sigh_ = Sigh::ZERO;
  } else {
    numerator_.sigh_ = Sigh::NEGATIVE;
  }
  // Перемножаем числитель левого операнда и знаменатель правого
  numerator_.natural_ = numerator_.natural_ * rhs.denominator_;
  // Перемножаем числитель правого операнда и знаменатель левого
  denominator_ = denominator_ * rhs.numerator_.natural_;
  // Сокращаем получившуюся дробь
  // Reduce();
  return *this;
}
