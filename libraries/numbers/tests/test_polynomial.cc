
#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, Dummy) { EXPECT_TRUE(true); }

TEST(PolynomialTest, Derivative) {
  Polynomial pol1({{Natural(0), Rational(Integer(1), Natural(1))},
                   {Natural(1), Rational(Integer(2), Natural(1))},
                   {Natural(2), Rational(Integer(3), Natural(1))}});
  Polynomial pol2({
      {Natural(0), Rational(Integer(2), Natural(1))},
      {Natural(1), Rational(Integer(6), Natural(1))},
  });
  pol1 = pol1.Derivative(pol1);
  EXPECT_EQ(pol1.GetDegree(), pol2.GetDegree());

  Polynomial pol3({{Natural(0), Rational(Integer(10), Natural(1))},
                   {Natural(1), Rational(Integer(16), Natural(1))}});
  Polynomial pol4({{Natural(0), Rational(Integer(16), Natural(1))}});
  pol3 = pol3.Derivative(pol3);
  EXPECT_EQ(pol3.GetDegree(), pol4.GetDegree());

  Polynomial pol5({{Natural(1), Rational(Integer(6), Natural(1))},
                   {Natural(12), Rational(Integer(2), Natural(1))}});
  Polynomial pol6({{Natural(0), Rational(Integer(6), Natural(1))},
                   {Natural(11), Rational(Integer(24), Natural(1))}});
  pol5 = pol5.Derivative(pol5);
  EXPECT_EQ(pol5.GetDegree(), pol6.GetDegree());
 
  Polynomial pol7({{Natural(10), Rational(Integer(264), Natural(1))}});
  pol5 = pol5.Derivative(pol5);
  EXPECT_EQ(pol5.GetDegree(), pol7.GetDegree());
}
