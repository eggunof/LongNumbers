
#include "input.h"

#include <iostream>

#include "integer.h"
#include "natural.h"
#include "polynomial.h"
#include "rational.h"

Natural GetNaturalInput() {
  Natural num;
  std::cout << "Введите натуральное число: ";
  std::cin >> num;
  return num;
}

Integer GetIntegerInput() {
  Integer num;
  std::cout << "Введите целое число: ";
  std::cin >> num;
  return num;
}

Rational GetRationalInput() {
  Rational num;
  std::cout << "Введите рациональное число (в формате числитель/знаменатель): ";
  std::cin >> num;
  return num;
}

Polynomial GetPolynomialInput() {
  std::cout << "Введите многочлен: ";
  std::string polynomial_string;
  std::cin >> polynomial_string;
  Polynomial p(polynomial_string);
  return p;
}
