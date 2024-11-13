
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

Polynomial Polynomial::GreatestCommonDivisor(const Polynomial &first,
                                             const Polynomial &second) {
  return {};
}

Polynomial Polynomial::Derivative(const Polynomial &polynomial) { return {}; }

// NMR_P_P - преобразование многочлена — кратные корни в простые
// Над модулем работала Кривошеина Дарья, группа 3383
Polynomial Polynomial::NormalizeRoots(const Polynomial &polynomial) {
  // создаем объект для будущего нормализованного многочлена (равен 1)
  Polynomial normalized_polynomial(
      {{Natural(0), Rational(Integer(1), Natural(1))}});
  // многочлен, равный переданному, который будет изменяться
  Polynomial current_polynomial = polynomial;
  // цикл, пока изменяемый многочлен не станет константой
  while (current_polynomial.GetDegree() != Natural(0)) {
    // берется производная от изменяемого многочлена
    Polynomial derivative = Derivative(current_polynomial);
    // находится gcd1 - НОД изменяемого многочлена и его производной
    Polynomial gcd1 = GreatestCommonDivisor(current_polynomial, derivative);
    // находится interim1 - результат деления изменяемого многочлена на
    // найденный выше НОД
    Polynomial interim1 = current_polynomial / gcd1;
    // находится gcd2 - НОД временного многочлена и производной изменяемого
    Polynomial gcd2 = GreatestCommonDivisor(interim1, derivative);
    // находится interim2 - результат деления interim1 на gcd2
    Polynomial interim2 = interim1 / gcd2;
    // коэффициенты interim2 сокращаются на (НОД числителей / НОК знаменателей)
    interim2.ToIntegerCoefficients();
    // если старший коэффициент interim2 отрицательный, многочлен умножается на
    // -1
    if (interim2.GetLeadingCoefficient().GetNumerator().GetSign() ==
        Sign::NEGATIVE) {
      interim2 *= Rational("-1");
    }
    // нормализованный многочлен умножается на получившийся
    normalized_polynomial *= interim2;
    current_polynomial = gcd1;
  }
  return normalized_polynomial;
}
