#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, IntegerToRational) {
  std::vector<std::pair<Integer, Rational>> cases = {
      {Integer("46532186"), Rational("46532186")},
      {Integer("0"), Rational("0")},
      {Integer("-65431864"), Rational("-65431864")},
  };

  for (const auto &[integer, expected] : cases) {
    EXPECT_EQ(static_cast<Rational>(integer), expected);
  }
}

TEST(RationalTest, RationalToInteger) {
  std::vector<std::pair<Rational, Integer>> valid_cases = {
      {Rational("1564/4"), Integer("391")},
      {Rational("-7087572768/453"), Integer("-15645856")},
  };

  for (const auto &[rational, expected] : valid_cases) {
    EXPECT_EQ(static_cast<Integer>(rational), expected);
  }

  std::vector<Rational> invalid_cases = {
      Rational("1/2"),
  };

  for (const auto &rational : invalid_cases) {
    EXPECT_THROW(static_cast<Integer>(rational), std::logic_error);
  }
}

TEST(RationalTest, Reduce) {
  std::vector<std::pair<Rational, Rational>> cases = {
      {Rational("25/5"), Rational("5/1")},
      {Rational("1234567834/98765434"), Rational("617283917/49382717")},
      {Rational("1234567891234567/123"), Rational("1234567891234567/123")},
      {Rational("-674743870000/474848784"), Rational("-1454189375/1023381")},
  };

  for (auto &[rational, expected] : cases) {
    rational.Reduce();
    EXPECT_EQ(rational, expected);
  }
}

TEST(RationalTest, IsInteger) {
  std::vector<std::pair<Rational, bool>> cases = {
      {Rational("1/3"), false}, {Rational("-5322/1"), true},
      {Rational("10/2"), true}, {Rational("17/34"), false},
      {Rational("0"), true},
  };

  for (auto &[rational, expected] : cases) {
    EXPECT_EQ(rational.IsInteger(), expected);
  }
}

TEST(RationalTest, Compare) {
  Rational a("123456789/987654321");
  Rational b("1/8");
  Rational g("111111111/222222222");
  Rational d("1/2");

  EXPECT_TRUE(a < b);
  EXPECT_TRUE(a <= d);
  EXPECT_TRUE(g == d);
  EXPECT_TRUE(b != d);
  EXPECT_FALSE(b > d);
  EXPECT_TRUE(d >= b);
}

TEST(RationalTest, Addition) {
  std::vector<std::tuple<Rational, Rational, Rational>> cases = {
      {Rational("1/3"), Rational("1/6"), Rational("1/2")},
      {Rational("-3/4"), Rational("1/10"), Rational("-13/20")},
      {Rational("-45486/644"), Rational("156431/1628"), Rational("86657/3404")},
  };

  for (auto &[lhs, rhs, expected] : cases) {
    lhs += rhs;
    EXPECT_EQ(lhs, expected);
  }
}

TEST(RationalTest, Subtraction) {
  std::vector<std::tuple<Rational, Rational, Rational>> cases = {
      {Rational("1/3"), Rational("1/6"), Rational("1/6")},
      {Rational("-3/4"), Rational("1/10"), Rational("-17/20")},
      {Rational("-45486/814"), Rational("441/1628"), Rational("-91413/1628")},
  };

  for (auto &[lhs, rhs, expected] : cases) {
    lhs -= rhs;
    EXPECT_EQ(lhs, expected);
  }
}

TEST(RationalTest, Multiplication) {
  std::vector<std::tuple<Rational, Rational, Rational>> cases = {
      {Rational("1/3"), Rational("1/6"), Rational("1/18")},
      {Rational("-3/4"), Rational("1/10"), Rational("-3/40")},
      {Rational("-1345/45"), Rational("453165/455"), Rational("-8126759/273")},
  };

  for (auto &[lhs, rhs, expected] : cases) {
    lhs *= rhs;
    EXPECT_EQ(lhs, expected);
  }
}

TEST(RationalTest, Division) {
  std::vector<std::tuple<Rational, Rational, Rational>> valid_cases = {
      {Rational("9/2"), Rational("7/4"), Rational("18/7")},
      {Rational("-3/4"), Rational("1/10"), Rational("-30/4")},
      {Rational("145/45"), Rational("-165/15"), Rational("-29/99")},
      {Rational("-54/32"), Rational("-455/25"), Rational("135/1456")},
      {Rational("0"), Rational("10"), Rational("0")},
  };

  for (auto &[lhs, rhs, expected] : valid_cases) {
    lhs /= rhs;
    EXPECT_EQ(lhs, expected);
  }

  Rational invalid_lhs("10/2");
  Rational invalid_rhs("0");
  EXPECT_THROW(invalid_lhs / invalid_rhs, std::invalid_argument);
}
