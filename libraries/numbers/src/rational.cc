
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
  // Складываем копию текущего объекта
  Rational result = *this;
  result += rhs;
  return result;
}

Rational Rational::operator-(const Rational &rhs) const { return {}; }

Rational Rational::operator*(const Rational &rhs) const { return {}; }

// Деление дробей (делитель отличен от нуля) "/"
// Над модулем работала Варфоломеева Арина, гр. 3383
Rational Rational::operator/(const Rational &rhs) const {
  Rational result = *this;
  result /= rhs;
  return result;
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

Rational Rational::operator-=(const Rational &rhs) { return {}; }

Rational Rational::operator*=(const Rational &rhs) { return {}; }

// Деление дробей (делитель отличен от нуля) "/="
// Над модулем работала Варфоломеева Арина, гр. 3383
Rational Rational::operator/=(const Rational &rhs) {
  // Определяем знак, сравнив знаки числителей
  // Если знаки числителей операндов различны, дробь отрицательная;
  // Иначе если знак числителя отрицательный, меняем на положительный
  if (numerator_.GetSign() != rhs.numerator_.GetSign()) {
    numerator_ = -numerator_;
  } else {
    if (numerator_.GetSign() == Sign::NEGATIVE) {
      numerator_ = -numerator_;
    }
  }
  // Перемножаем числитель левого операнда и знаменатель правого
  numerator_ *= Integer(rhs.denominator_);
  // Перемножаем числитель правого операнда и знаменатель левого
  denominator_ *= Natural(Integer::AbsoluteValue(rhs.numerator_));
  // Сокращаем получившуюся дробь
  Reduce();
  return *this;
}
