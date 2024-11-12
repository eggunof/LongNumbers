
#include "polynomial.h"

Polynomial Polynomial::operator+(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator-(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator*(const Rational &scalar) const { return {}; }

// Умножение многочленов
// Над модулем работала Дмитриева Дарья, гр. 3383
Polynomial Polynomial::operator*(const Polynomial &rhs) const {
    Polynomial result = *this;
    result *= rhs;
    return result;
}

Polynomial Polynomial::operator/(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator%(const Polynomial &rhs) const { return {}; }

Polynomial &Polynomial::operator+=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator-=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator*=(const Rational &scalar) { return *this; }

// Умножение многочленов
// Над модулем работала Дмитриева Дарья, гр. 3383
Polynomial &Polynomial::operator+=(const Polynomial &rhs) {
    // Создаем временной многочлен для хранения результата
    std::map<Natural, Rational, Comparator> resultCoefficients;
    // Перебираем все коэффициенты текущего многочлена
    for (const auto &[thisDegree, thisCoefficient] : coefficients_) {
        // Перебираем все коэффициенты многочлена rhs
        for (const auto &[rhsDegree, rhsCoefficient] : rhs.coefficients_) {
            // Вычисляем новую степень
            Natural newDegree = thisDegree + rhsDegree;
            // Вычисляем новый коэффициент
            Rational newCoefficient = thisCoefficient * rhsCoefficient;
            // Суммируем коэффициенты при одинаковых степенях
            resultCoefficients[newDegree] += newCoefficient;
        }
    }
    coefficients_ = std::move(resultCoefficients);
    return *this;
}

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
