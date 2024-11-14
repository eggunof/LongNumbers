
#include "polynomial.h"

// Сложение многочленов "+"
// Над модулем работала Варфоломеева Арина, гр. 3383
Polynomial Polynomial::operator+(const Polynomial &rhs) const {
  // Складываем копию текущего объекта
  Polynomial result = *this;
  result += rhs;
  return result;
}

Polynomial Polynomial::operator-(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator*(const Rational &scalar) const { return {}; }

Polynomial Polynomial::operator*(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator/(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator%(const Polynomial &rhs) const { return {}; }

// Сложение многочленов "+="
// Над модулем работала Варфоломеева Арина, гр. 3383
Polynomial &Polynomial::operator+=(const Polynomial &rhs) {
  // Проходимся по коэффициентам правого многочлена
  for (auto &[degree, coefficient] : rhs.coefficients_) {
    // Складываем и проверяем, не стал ли коэффициент равным нулю
    if ((coefficients_[degree] += coefficient) == Rational("0")) {
      // Если стал, удаляем
      coefficients_.erase(degree);
    }
  }
  return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator*=(const Rational &scalar) { return *this; }

Polynomial &Polynomial::operator*=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator/=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator%=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::MultiplyByXPower(uint32_t k) { return *this; }

Rational Polynomial::ToIntegerCoefficients(const Polynomial &polynomial) {
  return {};
}

Polynomial Polynomial::GreatestCommonDivisor(const Polynomial &first,
                                             const Polynomial &second) {
  return {};
}

Polynomial Polynomial::Derivative(const Polynomial &polynomial) { return {}; }

Polynomial Polynomial::NormalizeRoots(const Polynomial &polynomial) {
  return {};
}
