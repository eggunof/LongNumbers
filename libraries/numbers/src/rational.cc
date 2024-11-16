
#include "rational.h"

#include <sstream>
#include <stdexcept>
#include <utility>

Rational::Rational() : numerator_(0), denominator_(1) {}

Rational::Rational(Integer numerator, Natural denominator)
    : numerator_(std::move(numerator)), denominator_(std::move(denominator)) {
  if (denominator_.IsZero()) {
    throw std::invalid_argument("Invalid input: denominator cannot be zero");
  }
}

Rational::Rational(Integer integer)
    : numerator_(std::move(integer)), denominator_(1) {}

Rational::Rational(Natural natural)
    : numerator_(std::move(natural)), denominator_(1) {}

Rational::Rational(const std::string &string) {
  std::stringstream ss;
  ss << string;
  ss >> *this;
}

Rational::operator Integer() const {
  Integer denominator = static_cast<Integer>(denominator_);
  // Если не делится нацело, выбрасываем исключение
  if (numerator_ % denominator != Integer("0")) {
    throw std::logic_error(
        "Rational cannot be converted to an Integer without a remainder");
  }
  // Если делится нацело, возвращаем целое частное
  return numerator_ / denominator;
}

bool Rational::IsInteger() {
  // Сокращаем
  Reduce();
  // Сокращённое дробное является целым, если знаменатель равен 1
  return denominator_ == Natural(1);
}

Rational &Rational::Reduce() {
  // Находим НОД числителя и знаменателя
  Natural gcd = Natural::GreatestCommonDivisor(
      static_cast<Natural>(Integer::AbsoluteValue(numerator_)), denominator_);
  // Если НОД равен единице, дробь уже сокращена
  if (gcd == Natural(1)) return *this;
  // Сокращаем дробь
  numerator_ /= Integer(gcd);
  denominator_ /= gcd;
  return *this;
}

Rational Rational::Reduce() const {
  Rational result = *this;
  result.Reduce();
  return result;
}

const Integer &Rational::GetNumerator() const { return numerator_; }

const Natural &Rational::GetDenominator() const { return denominator_; }

Sign Rational::GetSign() const { return numerator_.GetSign(); }

bool Rational::operator==(const Rational &rhs) const {
  return numerator_ * static_cast<Integer>(rhs.denominator_) ==
         rhs.numerator_ * static_cast<Integer>(denominator_);
}

bool Rational::operator!=(const Rational &rhs) const { return !(*this == rhs); }

bool Rational::operator<(const Rational &rhs) const {
  return numerator_ * static_cast<Integer>(rhs.denominator_) <
         rhs.numerator_ * static_cast<Integer>(denominator_);
}

bool Rational::operator>(const Rational &rhs) const { return rhs < *this; }

bool Rational::operator<=(const Rational &rhs) const { return !(*this > rhs); }

bool Rational::operator>=(const Rational &rhs) const { return !(*this < rhs); }

Rational &Rational::operator-() {
  // Меняем знак числителя
  -numerator_;
  return *this;
}

Rational Rational::operator-() const {
  Rational result = *this;
  return -result;
}

Rational &Rational::operator+=(const Rational &rhs) {
  // Находим НОК знаменателей
  Natural lcm = Natural::LeastCommonMultiple(denominator_, rhs.denominator_);
  // Определяем множители для каждого числителя
  Natural lhs_multiplier = lcm / denominator_;
  Natural rhs_multiplier = lcm / rhs.denominator_;
  // Умножаем числитель левого операнда
  numerator_ *= static_cast<Integer>(lhs_multiplier);
  // Прибавляем умноженный числитель правого операнда
  numerator_ += rhs.numerator_ * static_cast<Integer>(rhs_multiplier);
  // Обновляем знаменатель
  denominator_ = lcm;
  // Сокращаем дробь
  Reduce();
  return *this;
}

Rational Rational::operator+(const Rational &rhs) const {
  // Складываем копию текущего объекта
  Rational result = *this;
  result += rhs;
  return result;
}

Rational &Rational::operator-=(const Rational &rhs) {
  // Применяем сложение с противоположным знаком
  *this += -rhs;
  return *this;
}

Rational Rational::operator-(const Rational &rhs) const {
  // Вычитаем копию текущего объекта
  Rational result = *this;
  result -= rhs;
  return result;
}

Rational &Rational::operator*=(const Rational &rhs) {
  numerator_ *= rhs.numerator_;
  denominator_ *= rhs.denominator_;
  // Сокращаем дробь
  Reduce();
  return *this;
}

Rational Rational::operator*(const Rational &rhs) const {
  Rational result = *this;
  result *= rhs;
  return result;
}

Rational &Rational::operator/=(const Rational &rhs) {
  if (rhs.numerator_ == Integer("0")) {
    throw std::invalid_argument(
        "Invalid input: Division by zero is not allowed");
  }
  numerator_ *= Integer(rhs.denominator_, rhs.numerator_.GetSign());
  denominator_ *= static_cast<Natural>(Integer::AbsoluteValue(rhs.numerator_));
  // Сокращаем получившуюся дробь
  Reduce();
  return *this;
}

Rational Rational::operator/(const Rational &rhs) const {
  Rational result = *this;
  result /= rhs;
  return result;
}

std::istream &operator>>(std::istream &is, Rational &rational) {
  is >> rational.numerator_ >> std::ws;
  if (is.good() && is.peek() == '/') {
    is.get();
    is >> rational.denominator_;
  } else {
    rational.denominator_ = Natural(1);
  }
  if (rational.denominator_.IsZero()) {
    throw std::invalid_argument("Invalid input: denominator cannot be zero");
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const Rational &rational) {
  os << rational.numerator_;
  if (rational.denominator_ != Natural(1)) {
    os << "/" << rational.denominator_;
  }
  return os;
}

std::string Rational::ToString() const {
  std::ostringstream result;
  result << *this;
  return result.str();
}
