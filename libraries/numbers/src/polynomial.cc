
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

Polynomial &Polynomial::MultiplyByXPower(uint32_t k) { return *this; }

Rational Polynomial::ToIntegerCoefficients(const Polynomial &polynomial) {
  return {};
}

// НОД многочленов
// Над модулем работал Матвеев Никита гр. 3383
Polynomial Polynomial::GreatestCommonDivisor(const Polynomial &first, const Polynomial &second) {
    Polynomial dividend; // делимое
    Polynomial divisor; // делитель
    Polynomial remains; // для хранения остатка
    if (first.GetDegree() >= second.GetDegree()) { // если степень первого превосходи или равна второму
        dividend = first; // делимое - первое число, делитель второе
        divisor = second;
    } else { // иначе числа меняются местами
        dividend = second;
        divisor = first;
    }
    remains = dividend % divisor; // первый раз находим остаток от деления первого на второго
    while (!remains.coefficients_.empty()) { // пока отсаток не равен 0 (не пуст равнозначно)
        dividend = divisor; // теперь делимое - бывший делитель
        divisor = remains; // делитель - получившийся остаток
        remains = dividend % divisor; // новый остаток от деления новых элементов
    }
    divisor.ToIntegerCoefficients(); // выносится общий множитель коэффициентов 
    return divisor;
}

Polynomial Polynomial::Derivative(const Polynomial &polynomial) { return {}; }

Polynomial Polynomial::NormalizeRoots(const Polynomial &polynomial) {
  return {};
}
