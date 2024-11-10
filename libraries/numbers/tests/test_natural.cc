
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

TEST(NaturalTest, MultyByD) {
    Natural natural1("9999999");
    Natural natural2("5473");
    Natural natural3("123456789");
    Natural res1("89999991");
    Natural res2("0");
    Natural res3("123456789");
    EXPECT_EQ(natural1*=9, res1);
    EXPECT_EQ(natural2*=0, res2);
    EXPECT_EQ(natural3*=1, res3);
    Natural natural4("123321");
    Natural res4("863247");
    Natural a = natural4 * 7;
    EXPECT_EQ(a, res4);
}
