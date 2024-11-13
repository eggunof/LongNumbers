
#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, Dummy) { EXPECT_TRUE(true); }

TEST(PolynomialTest, NormalizeRootsTest){
  Polynomial pol1({{Natural(0), Rational(Integer("-12"), Natural(1))},
                   {Natural(1), Rational(Integer("-20"), Natural(1))},
                   {Natural(2), Rational(Integer("5"), Natural(1))},
                   {Natural(3), Rational(Integer("16"), Natural(1))},
                   {Natural(4), Rational(Integer("-2"), Natural(1))},
                   {Natural(5), Rational(Integer("-4"), Natural(1))},
                   {Natural(6), Rational(Integer("1"), Natural(1))}});
  pol1 = pol1.NormalizeRoots(pol1);
  Polynomial pol2({{Natural(0), Rational(Integer("6"), Natural(1))},
                   {Natural(1), Rational(Integer("1"), Natural(1))},
                   {Natural(2), Rational(Integer("-4"), Natural(1))},
                   {Natural(3), Rational(Integer("1"), Natural(1))}});
  EXPECT_EQ(pol1, pol2);

  Polynomial pol3({{Natural(0), Rational(Integer("25"), Natural(1))},
                   {Natural(1), Rational(Integer("-1"), Natural(1))},
                   {Natural(2), Rational(Integer("1"), Natural(1))}});
  pol3 = pol3.NormalizeRoots(pol3);
  Polynomial pol4({{Natural(0), Rational(Integer("25"), Natural(1))},
                   {Natural(1), Rational(Integer("-1"), Natural(1))},
                   {Natural(2), Rational(Integer("1"), Natural(1))}});
  EXPECT_EQ(pol3, pol4);

  Polynomial pol5({{Natural(0), Rational(Integer("845"), Natural(1))},
                   {Natural(1), Rational(Integer("39"), Natural(1))},
                   {Natural(2), Rational(Integer("-21"), Natural(1))},
                   {Natural(3), Rational(Integer("1"), Natural(1))}});
  pol5 = pol5.NormalizeRoots(pol5);
  Polynomial pol6({{Natural(0), Rational(Integer("-65"), Natural(1))},
                   {Natural(1), Rational(Integer("-8"), Natural(1))},
                   {Natural(2), Rational(Integer("1"), Natural(1))}});
  EXPECT_EQ(pol5, pol6);
}
