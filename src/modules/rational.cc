
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
  // Находим общий знаменатель
    Natural Denum = this->denominator_.LCM_NN_N(other.denominator_);

    // Находим числители с учетом дополнительных множителей
    Integer Num1 = this->numerator_.MUL_ZZ_Z(Integer(Denum.DIV_NN_N(this->denominator_)));
    Integer Num2 = other.numerator_.MUL_ZZ_Z(Integer(Denum.DIV_NN_N(other.denominator_)));
    
    // Вычитаем числитель второй дроби из первой
    Integer Num = Num1.SUB_ZZ_Z(Num2);

    // Создаем результат
    Rational result(Num, Denum);
    return result;
}

Rational Rational::operator*=(const Rational &rhs) {
  return {};
}

Rational Rational::operator/=(const Rational &rhs) {
  return {};
}


