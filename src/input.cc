
#include "input.h"

#include <iostream>
#include <limits>

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
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  Polynomial p;
  std::cout << "Введите многочлен: ";
  std::cin >> p;
  return p;
}
