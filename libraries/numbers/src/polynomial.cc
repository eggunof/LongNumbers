
#include "polynomial.h"

Polynomial Polynomial::operator+(const Polynomial &rhs) const { return {}; }

// Вычитание многочленов
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial Polynomial::operator-(const Polynomial &rhs) const { 
  Polynomial result = *this;
  result -= rhs;
  return result;
}

Polynomial Polynomial::operator*(const Rational &scalar) const { return {}; }

Polynomial Polynomial::operator*(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator/(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator%(const Polynomial &rhs) const { return {}; }

Polynomial &Polynomial::operator+=(const Polynomial &rhs) { return *this; }

// Вычитание многочленов
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial &Polynomial::operator-=(const Polynomial &rhs) { 
  for (auto & coefficient : rhs.coefficients_) coefficients_[coefficient.first] -= coefficient.second;
  return *this; 
}

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
