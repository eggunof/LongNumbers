
#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, Dummy) { EXPECT_TRUE(true); }

TEST(PolynomialTest, Addition) {
  Polynomial pol1({{Natural(0), Rational(Integer(1), Natural(1))},
                   {Natural(1), Rational(Integer(2), Natural(1))},
                   {Natural(2), Rational(Integer(3), Natural(1))},
                   {Natural(3), Rational(Integer(4), Natural(1))}});
  Polynomial pol2({{Natural(0), Rational(Integer(10), Natural(1))},
                   {Natural(2), Rational(Integer(20), Natural(1))},
                   {Natural(3), Rational(Integer(30), Natural(1))},
                   {Natural(10), Rational(Integer(40), Natural(1))}});
  Polynomial pol_expected1({{Natural(0), Rational(Integer(11), Natural(1))},
                            {Natural(1), Rational(Integer(2), Natural(1))},
                            {Natural(2), Rational(Integer(23), Natural(1))},
                            {Natural(3), Rational(Integer(34), Natural(1))},
                            {Natural(10), Rational(Integer(40), Natural(1))}});

  EXPECT_EQ(pol1 += pol2, pol_expected1);

  Polynomial pol3({{Natural(0), Rational(Integer(100), Natural(1))},
                   {Natural(10), Rational(Integer(500), Natural(1))},
                   {Natural(20), Rational(Integer(600), Natural(1))},
                   {Natural(30), Rational(Integer(700), Natural(1))}});
  Polynomial pol4({{Natural(0), Rational(Integer(-100), Natural(1))},
                   {Natural(10), Rational(Integer(-200), Natural(1))},
                   {Natural(20), Rational(Integer(400), Natural(1))},
                   {Natural(30), Rational(Integer(-800), Natural(1))},
                   {Natural(50), Rational(Integer(500), Natural(1))}});
  Polynomial pol_expected2({{Natural(10), Rational(Integer(300), Natural(1))},
                            {Natural(20), Rational(Integer(1000), Natural(1))},
                            {Natural(30), Rational(Integer(-100), Natural(1))},
                            {Natural(50), Rational(Integer(500), Natural(1))}});

  EXPECT_EQ(pol3 += pol4, pol_expected2);
}
