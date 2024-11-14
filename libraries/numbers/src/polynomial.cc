
#include "polynomial.h"

// Сложение многочленов "+"
// Над модулем работала Варфоломеева Арина, гр. 3383
Polynomial Polynomial::operator+(const Polynomial &rhs) const {
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
  // Проходим по всем коэффициентам многочлена rhs
  for (auto &coefficient : rhs.coefficients_) {
    // Для каждого коэффициента из rhs (coefficient.first - степень,
    // coefficient.second - коэффициент) увеличиваем соответствующий коэффициент
    // текущего многочлена
    coefficients_[coefficient.first] += coefficient.second;
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
