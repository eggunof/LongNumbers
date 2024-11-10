
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

TEST(NaturalTest, MulByTenPow1) {
  Natural natural("5000000000");
  natural.MultiplyBy10Power(2);
  std::vector<uint8_t> expected = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  EXPECT_EQ(natural.digits_, expected);
}

TEST(NaturalTest, MulByTenPow2) {
  Natural natural("5000000000");
  natural.MultiplyBy10Power(0);
  std::vector<uint8_t> expected = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  EXPECT_EQ(natural.digits_, expected);
}
