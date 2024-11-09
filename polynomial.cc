
#include "polynomial.h"

Polynomial Polynomial::operator+(const Polynomial &rhs) const {
  return {};
}

Polynomial Polynomial::operator-(const Polynomial &rhs) const {
  return {};
}

Polynomial Polynomial::operator*(const Rational &scalar) const {
  return {};
}

Polynomial Polynomial::operator*(const Polynomial &rhs) const {
  return {};
}

Polynomial Polynomial::operator/(const Polynomial &rhs) const {
  return {};
}

Polynomial Polynomial::operator%(const Polynomial &rhs) const {
  return {};
}

Polynomial &Polynomial::operator+=(const Polynomial &rhs) {
  return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &rhs) {
  return *this;
}

Polynomial &Polynomial::operator*=(const Rational &scalar) {
  return *this;
}

Polynomial &Polynomial::operator*=(const Polynomial &rhs) {
  return *this;
}

Polynomial &Polynomial::operator/=(const Polynomial &rhs) {
  return *this;
}

Polynomial &Polynomial::operator%=(const Polynomial &rhs) {
  return *this;
}

Polynomial &Polynomial::MultiplyByXPower(uint32_t k) {
  return *this;
}

Rational Polynomial::ToIntegerCoefficients(const Polynomial &polynomial) {
  return {};
}

Polynomial Polynomial::GreatestCommonDivisor(const Polynomial &first, const Polynomial &second) {
  return {};
}

//DER_P_P - производная многочлена
//Над модулем работала Кривошеина Дарья, группа 3383
Polynomial Polynomial::Derivative(const Polynomial &polynomial) {
    Polynomial derivative; // объект производной многочлена
    int counter = 0; // для подсчета пройденных слагаемых и нахождения последнего
    // цикл идет по степеням слагаемых переданного многочлена и их коэффициентам
    for (const auto& [degree, coefficient] : polynomial.coefficients_){
        counter++;
        // если степень слагаемого до взятия производной равна 1, оно не добавляется, так как обнулится
        if (counter == polynomial.coefficients_.size() && degree == Natural(1)){
            break;
        }
        // коэффициент равен произведению старого коэффициента на степень слагаемого
        // для умножения надо перевести натуральную степень в целое, а затем в рациональное число
        Rational new_coefficient = Rational(Integer(degree)) * coefficient;
        // степень понижается на единицу
        derivative.coefficients_[degree - Natural(1)] = new_coefficient;
    }
    return derivative;
}

Polynomial Polynomial::NormalizeRoots(const Polynomial &polynomial) {
  return {};
}
