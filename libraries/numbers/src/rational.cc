
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

// Сложение дробей "+"
// Над модулем работала Майская Вероника, гр. 3384
Rational Rational::operator+(const Rational &rhs) const {
    // Находим НОК знаменателей
    Natural common_denominator = LCM_NN_N(this->denominator_, rhs.denominator_);
    // Определяем множители для каждого числителя
    Natural scale_left = common_denominator / this->denominator_;
    Natural scale_right = common_denominator / rhs.denominator_;
    // Приводим числители к общему знаменателю
    Integer new_numerator_left = MUL_ZZ_Z(this->numerator_, Integer(scale_left));
    Integer new_numerator_right = MUL_ZZ_Z(this->numerator_, Integer(scale_right));
    // Складываем числители
    Integer result_numerator = ADD_ZZ_Z(new_numerator_left, new_numerator_right);
    return Rational(result_numerator, common_denominator);
}

Rational Rational::operator-(const Rational &rhs) const { return {}; }

Rational Rational::operator*(const Rational &rhs) const { return {}; }

Rational Rational::operator/(const Rational &rhs) const { return {}; }

// Сложение дробей "+="
// Над модулем работала Майская Вероника, гр. 3384
Rational Rational::operator+=(const Rational &rhs) {
    *this = *this + rhs;
    return *this;
}

Rational Rational::operator-=(const Rational &rhs) { return {}; }

Rational Rational::operator*=(const Rational &rhs) { return {}; }

Rational Rational::operator/=(const Rational &rhs) { return {}; }
