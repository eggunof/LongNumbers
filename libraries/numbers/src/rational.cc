
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

Integer Rational::ToInteger(const Rational &rational) { return {}; }

Rational &Rational::Reduce() { return *this; }

bool Rational::IsInteger() {
  Reduce();
  return false;
}

Rational Rational::operator+(const Rational &rhs) const { return {}; }

Rational Rational::operator-(const Rational &rhs) const {
  *this -= rhs;
  return *this;
 }

Rational Rational::operator*(const Rational &rhs) const { return {}; }

Rational Rational::operator/(const Rational &rhs) const { return {}; }

Rational Rational::operator+=(const Rational &rhs) { return {}; }

Rational Rational::operator-=(const Rational &rhs) {
  /// Находим общий знаменатель
  Natural Denum = denominator_.LeastCommonMultiple(denominator_, rhs.denominator_);

  // Находим числители с учетом дополнительных множителей
  Integer Num1 =
      numerator_*=(Integer(Denum/=(this->denominator_)));
  Integer Num2 =
      rhs.numerator_*(Integer(Denum/=(rhs.denominator_)));

  // Вычитаем числитель второй дроби из первой
  Integer Num = Num1-=Num2;

  // Создаем результат
  Rational result(Num, Denum);
  return result;
}

Rational Rational::operator*=(const Rational &rhs) { return {}; }

Rational Rational::operator/=(const Rational &rhs) { return {}; }
