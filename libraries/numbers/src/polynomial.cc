
#include "polynomial.h"

Polynomial Polynomial::operator+(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator-(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator*(const Rational &scalar) const { return {}; }

Polynomial Polynomial::operator*(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator/(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator%(const Polynomial &rhs) const { return {}; }

Polynomial &Polynomial::operator+=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator-=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator*=(const Rational &scalar) { return *this; }

Polynomial &Polynomial::operator*=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator/=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator%=(const Polynomial &rhs) { return *this; }

// Умножение многочлена на x^k, k-натуральное или 0
// Над модулем работала Майская Вероника, гр. 3384
Polynomial &Polynomial::MultiplyByXPower(uint32_t k) {
  // Если k = 0, то умножение на x^0 не меняет многочлен
  if (k == 0) {
    return *this;
  }
  // Создаем временное хранилище для коэффициентов
  std::map<Natural, Rational, Comparator> new_coefficients;
  // Проходим по каждому члену многочлена
  for (const auto &term : this->coefficients_) {
    Natural new_degree = term.first + k;  // Новая степень после смещения на k
    new_coefficients[new_degree] = term.second;  // Добавляем коэффициент в новую степень
  }
  // Обновляем текущий многочлен новыми коэффициентами
  this->coefficients_ = new_coefficients;
  return *this;
}

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
