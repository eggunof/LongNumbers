
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

// Преобразование целого в дробное
// Над модулем работала Кривошеина Дарья, гр. 3383
Rational::Rational(const Integer &integer)
    : numerator_(integer), denominator_(Natural("1")) {}

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

// Сложение дробей "+="
// Над модулем работала Майская Вероника, гр. 3384
Rational Rational::operator+=(const Rational &rhs) {
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

// Вычитание дробей "-="
// Над модулем работала Кадникова Анна, гр. 3384
Rational Rational::operator-=(const Rational &rhs) {
  // Применяем сложение с противоположным знаком
  *this += -rhs;
  return *this;
}

// Умножение дробей "*="
// Над модулем работала Солдунова Екатерина, гр. 3383
Rational Rational::operator*=(const Rational &rhs) {
  numerator_ *= rhs.numerator_;
  denominator_ *= rhs.denominator_;
  // Сокращаем дробь
  Reduce();
  return *this;
}

// Деление дробей "/="
// Над модулем работала Варфоломеева Арина, гр. 3383
Rational Rational::operator/=(const Rational &rhs) {
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

Rational Rational::operator-() const {
  Rational result = *this;
  return -result;
}

// Сложение дробей "+"
// Над модулем работала Майская Вероника, гр. 3384
Rational Rational::operator+(const Rational &rhs) const {
  // Складываем копию текущего объекта
  Rational result = *this;
  result += rhs;
  return result;
}

// Вычитание дробей "-"
// Над модулем работала Кадникова Анна, гр. 3384
Rational Rational::operator-(const Rational &rhs) const {
  // Вычитаем копию текущего объекта
  Rational result = *this;
  result -= rhs;
  return result;
}

// Умножение дробей "*"
// Над модулем работала Солдунова Екатерина, гр. 3383
Rational Rational::operator*(const Rational &rhs) const {
  Rational result = *this;
  result *= rhs;
  return result;
}

// Деление дробей "/"
// Над модулем работала Варфоломеева Арина, гр. 3383
Rational Rational::operator/(const Rational &rhs) const {
  Rational result = *this;
  result /= rhs;
  return result;
}
