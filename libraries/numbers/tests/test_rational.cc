
#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, LargeComparisonOperators) {
  Rational e("123456789/987654321");
  Rational f("1/8");
  Rational g("111111111/222222222");
  Rational h("1/2");

  EXPECT_TRUE(e < f);
  EXPECT_FALSE(e == h);
  EXPECT_TRUE(g == h);
  EXPECT_TRUE(f != h);
  EXPECT_FALSE(f > h);
  EXPECT_TRUE(h >= f);
}
