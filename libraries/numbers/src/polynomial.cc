
#include "polynomial.h"

Polynomial Polynomial::operator+(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator-(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator*(const Rational &scalar) const { return {}; }

Polynomial Polynomial::operator*(const Polynomial &rhs) const { return {}; }

// Частное от деления многочлена на многочлен при делении с остатком
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial Polynomial::operator/(const Polynomial &rhs) const {
  Polynomial result = *this;
  result /= rhs;
  return result;
}

Polynomial Polynomial::operator%(const Polynomial &rhs) const { return {}; }

Polynomial &Polynomial::operator+=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator-=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator*=(const Rational &scalar) { return *this; }

Polynomial &Polynomial::operator*=(const Polynomial &rhs) { return *this; }

// Частное от деления многочлена на многочлен при делении с остатком
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial &Polynomial::operator/=(const Polynomial &rhs) {
  Polynomial result;
  // Остаток от деления
  Polynomial remainder = *this;
  // До момента, пока степень делителя меньше или равна степени многочлена, продолжаем деление
  while (rhs.GetDegree() <= remainder.GetDegree()){
    Rational remainder_leading = remainder.GetLeadingCoefficient();
    Natural remainder_degree = remainder.GetDegree();
    Rational rhs_leading = rhs.GetLeadingCoefficient();
    Natural rhs_degree = rhs.GetDegree();
    // Подсчитываем, на сколько нужно увеличить степень делителя для того, чтоюы сравнять её со степенью многочлена 
    // и для данной степени вычисляем коэффициент, при котором старший член при вычитании сократится
    result[remainder_degree-rhs_degree] = remainder_leading/rhs_leading;
    // Вычитаем из многочлена произведение делителя и вышеописанного члена
    remainder -= (rhs*(remainder_leading/rhs_leading)).MultiplyByXPower(remainder_degree-rhs_degree);
  }
  *this = result;
  return *this;
}

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
