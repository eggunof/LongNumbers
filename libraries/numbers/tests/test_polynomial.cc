
#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, Dummy) { EXPECT_TRUE(true); }

TEST(PolynomialTest, MultiplyByXPower) {
  // P(x) = 3 + 2x + x^2
  Polynomial poly({
      {Natural(0), Rational(Integer(3), Natural(1))},
      {Natural(1), Rational(Integer(2), Natural(1))},
      {Natural(2), Rational(Integer(1), Natural(1))}
  });
  Polynomial result1 = poly;
  result1.MultiplyByXPower(0);
  EXPECT_EQ(result1, poly);

  Polynomial result2 = poly;
  result2.MultiplyByXPower(1);
  Polynomial expected2({
      {Natural(1), Rational(Integer(3), Natural(1))},
      {Natural(2), Rational(Integer(2), Natural(1))},
      {Natural(3), Rational(Integer(1), Natural(1))}
  });
  EXPECT_EQ(result2, expected2);

  Polynomial result3 = poly;
  result3.MultiplyByXPower(2);
  Polynomial expected3({
      {Natural(2), Rational(Integer(3), Natural(1))},
      {Natural(3), Rational(Integer(2), Natural(1))},
      {Natural(4), Rational(Integer(1), Natural(1))}
  });
  EXPECT_EQ(result3, expected3);
}
