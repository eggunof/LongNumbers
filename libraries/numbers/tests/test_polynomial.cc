
#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, ToIntegerCoefficients) {
  Polynomial pol1({
      {Natural(2), Rational(Integer(25), Natural(33))},
      {Natural(1), Rational(Integer(5), Natural(11))},
      {Natural(0), Rational(Integer(5), Natural(1))}
  });
  EXPECT_EQ(pol1.ToIntegerCoefficients(), Rational("5/33"));
  Polynomial pol2({
      {Natural(0), Rational(Integer(-15625), Natural(139968))},
      {Natural(1), Rational(Integer(-15625), Natural(279936))},
  });
  EXPECT_EQ(pol2.ToIntegerCoefficients(), Rational("15625/279936"));
  Polynomial res1({
      {Natural(0), Rational(Integer(-2), Natural(1))},
      {Natural(1), Rational(Integer(-1), Natural(1))},
  });
  EXPECT_EQ(pol2, res1);
  Polynomial pol3({
      {Natural(2), Rational(Integer(7), Natural(1))},
      {Natural(1), Rational(Integer(14), Natural(1))},
      {Natural(0), Rational(Integer(21), Natural(1))}
  });
  EXPECT_EQ(pol3.ToIntegerCoefficients(), Rational("7/1"));
  Polynomial pol4({
      {Natural(2), Rational(Integer(1), Natural(7))},
      {Natural(1), Rational(Integer(1), Natural(2))},
      {Natural(0), Rational(Integer(1), Natural(1))}
  });
  EXPECT_EQ(pol4.ToIntegerCoefficients(), Rational("1/14"));
  Polynomial res2({
      {Natural(2), Rational(Integer(2), Natural(1))},
      {Natural(1), Rational(Integer(7), Natural(1))},
      {Natural(0), Rational(Integer(14), Natural(1))}
  });
  EXPECT_EQ(pol4, res2);
}