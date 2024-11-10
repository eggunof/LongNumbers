
#include <gtest/gtest.h>

#include "natural.h"

TEST(NaturalTest, CreateEmpty) {
  Natural natural;
  EXPECT_TRUE(natural.IsZero());
}

TEST(NaturalTest, Compare) {
  Natural first("5246345451");
  Natural second("5263345651");
  EXPECT_EQ(Natural::Compare(first, second), Comparison::LESS);
  EXPECT_FALSE(first == second);
  EXPECT_TRUE(first != second);
  EXPECT_TRUE(first < second);
  EXPECT_FALSE(first > second);
  EXPECT_TRUE(first <= second);
  EXPECT_FALSE(first >= second);
}


TEST(NaturalTest, Addition) {
  Natural a("10099");
  Natural b("599999");
  a += b;
  EXPECT_EQ(a, Natural("610098"));
}

TEST(NaturalTest, MultipleByDigit) {
  Natural a("9999999");
  EXPECT_EQ(a *= 9, Natural("89999991"));

  Natural b("5473");
  EXPECT_EQ(b *= 0, Natural("0"));

  Natural c("123456789");
  EXPECT_EQ(c *= 1, Natural("123456789"));

  Natural d("123321");
  EXPECT_EQ(d * 7, Natural("863247"));
}
