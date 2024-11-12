
#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, Remainder) {
    // Тест 1: Остаток от деления многочлена на многочлен с нулевым коэффициентом
    Polynomial pol1({{Natural(0), Rational(Integer(1), Natural(1))}, // 1
                      {Natural(1), Rational(Integer(2), Natural(1))}, // 2x
                      {Natural(2), Rational(Integer(3), Natural(1))}}); // 3x^2
    Polynomial pol2({{Natural(0), Rational(Integer(0), Natural(1))}}); // Нулевой многочлен
    EXPECT_THROW(pol1 %= pol2, std::invalid_argument);

    // Тест 2: Остаток от деления многочлена на многочлен с нулевым ведущим коэффициентом
    Polynomial pol3({{Natural(0), Rational(Integer(0), Natural(1))}, // 0
                      {Natural(1), Rational(Integer(1), Natural(1))}}); // x
    EXPECT_THROW(pol1 %= pol3, std::invalid_argument);

    // Тест 3: Остаток от деления, когда степень делимого меньше степени делителя
    Polynomial pol4({{Natural(0), Rational(Integer(1), Natural(1))}}); // 1
    Polynomial pol5({{Natural(0), Rational(Integer(1), Natural(1))}, // 1
                      {Natural(1), Rational(Integer(1), Natural(1))}}); // x
    pol4 %= pol5; // Остаток должен быть равен пол4 (1)
    EXPECT_EQ(pol4, Polynomial({{Natural(0), Rational(Integer(1), Natural(1))}}));

    // Тест 4: Остаток от деления, когда делимое и делитель имеют одинаковую степень
    Polynomial pol6({{Natural(0), Rational(Integer(1), Natural(1))}, // 1
                      {Natural(1), Rational(Integer(2), Natural(1))}}); // 2x
    Polynomial pol7({{Natural(0), Rational(Integer(1), Natural(1))}, // 1
                      {Natural(1), Rational(Integer(1), Natural(1))}}); // x
    pol6 %= pol7; // Остаток должен быть равен (1 + 2x) - ((1 + 2x) / (1 + x)) * (1 + x)
    EXPECT_EQ(pol6, Polynomial({{Natural(0), Rational(Integer(1), Natural(1))}})); // Остаток должен быть равен 1

    // Тест 5: Остаток от деления, когда делимое имеет степень больше делителя
    Polynomial pol8({{Natural(0), Rational(Integer(3), Natural(1))}, // 3
                      {Natural(1), Rational(Integer(2), Natural(1))}, // 2x
                      {Natural(2), Rational(Integer(1), Natural(1))}}); // x^2
    Polynomial pol9({{Natural(0), Rational(Integer(1), Natural(1))}, // 1
                      {Natural(1), Rational(Integer(1), Natural(1))}}); // x
    pol8 %= pol9; // Остаток должен быть равен 3 - ((3 + 2x + x^2) / (1 + x)) * (1 + x)
    EXPECT_EQ(pol8, Polynomial({{Natural(0), Rational(Integer(3), Natural(1))}})); // Остаток должен быть равен 3

    // Тест 6: Проверка, что остаток от деления многочлена на себя равен нулю
    Polynomial pol10({{Natural(0), Rational(Integer(3), Natural(1))}, // 3
                       {Natural(1), Rational(Integer(2), Natural(1))}, // 2x
                       {Natural(2), Rational(Integer(1), Natural(1))}}); // x^2
    pol10 %= pol10; // Остаток должен быть равен 0
    EXPECT_EQ(pol10, Polynomial({{Natural(0), Rational(Integer(0), Natural(1))}})); // Остаток должен быть равен 0
}
