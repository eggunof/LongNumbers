
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

// Преобразование дробного в целое
// Над модулем работал Егунов Даниил, гр. 3383
Rational::operator Integer() const {
  Integer denominator = static_cast<Integer>(denominator_);
  // Если не делится нацело, выбрасываем исключение
  if (numerator_ % denominator != Integer("0")) {
    throw std::invalid_argument(
        "Invalid input: Rational cannot be converted to an Integer without a "
        "remainder");
  }
  // Если делится нацело, возвращаем целое частное
  return numerator_ / denominator;
}

bool Rational::operator==(const Rational &rhs) const {
  return numerator_ * static_cast<Integer>(rhs.denominator_) ==
         rhs.numerator_ * static_cast<Integer>(denominator_);
}

bool Rational::operator!=(const Rational &rhs) const { return !(*this == rhs); }

// Сокращение дроби
// Над модулем работала Дмитриева Дарья, гр. 3383
Rational &Rational::Reduce() {
  // Находим НОД числителя и знаменателя
  Natural gcd = Natural::GreatestCommonDivisor(
      static_cast<Natural>(Integer::AbsoluteValue(numerator_)), denominator_);
  // Если НОД равен единице, дробь уже сокращена
  if (gcd == Natural("1")) return *this;
  // Сокращаем дробь
  numerator_ /= Integer(gcd);
  denominator_ /= gcd;
  return *this;
}

// Проверка сокращённого дробного на целое
// Над модулем работал Матвеев Никита, гр. 3383
bool Rational::IsInteger() {
  // Сокращаем
  Reduce();
  // Сокращённое дробное является целым, если знаменатель равен 1
  return denominator_ == Natural("1");
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
    Rational result(result_numerator, common_denominator);
    // Сокращаем дробь
    result.Reduce();
    return result;
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
