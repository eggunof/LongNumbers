
#include "polynomial.h"

Polynomial Polynomial::operator+(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator-(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator*(const Rational &scalar) const { return {}; }

Polynomial Polynomial::operator*(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator/(const Polynomial &rhs) const { return {}; }

// Остаток от деления многочлена на многочлен при делении с остатком
// Над модулем работала Дмитриева Дарья, гр. 3383
Polynomial Polynomial::operator%(const Polynomial &rhs) const {
    Polynomial result = *this;
    result %= rhs;
    return result;
}

Polynomial &Polynomial::operator+=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator-=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator*=(const Rational &scalar) { return *this; }

Polynomial &Polynomial::operator*=(const Polynomial &rhs) { return *this; }

// Остаток от деления многочлена на многочлен при делении с остатком
// Над модулем работала Дмитриева Дарья, гр. 3383
Polynomial &Polynomial::operator%=(const Polynomial &rhs) {
    // Проверяем, не является ли многочлен rhs нулевым
    if (rhs.coefficients_.empty() ||  rhs.GetLeadingCoefficient() == Rational("0")) {
        throw std::invalid_argument("Division by zero polynomial");
    }
    // Если степень текущего многочлена меньше степени rhs, возвращаем текущий многочлен как остаток
    if (this->GetDegree() < rhs.GetDegree()) {
        return *this;
    }
    // Вычисляем частное (this / rhs) и умножаем его на rhs
    // Затем вычитаем это значение из текущего многочлена для получения остатка.
    Polynomial remainder = *this - ((*this /  rhs) * rhs);
    *this = remainder;
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
