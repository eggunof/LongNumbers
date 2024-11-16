
#include <gtest/gtest.h>

#include "natural.h"

TEST(NaturalTest, CreateEmpty) {
  Natural natural;
  EXPECT_TRUE(natural.IsZero());
}

TEST(NaturalTest, Compare) {
  std::vector<std::tuple<Natural, Natural, Comparison>> cases = {
      {Natural("5246345451"), Natural("5263345651"), Comparison::LESS},
      {Natural("1000000000"), Natural("1000000000"), Comparison::EQUAL},
      {Natural("999999999"), Natural("123"), Comparison::GREATER},
  };

  for (const auto &[first, second, expected] : cases) {
    EXPECT_EQ(Natural::Compare(first, second), expected);
    EXPECT_EQ(first == second, expected == Comparison::EQUAL);
    EXPECT_EQ(first != second, expected != Comparison::EQUAL);
    EXPECT_EQ(first < second, expected == Comparison::LESS);
    EXPECT_EQ(first > second, expected == Comparison::GREATER);
    EXPECT_EQ(first <= second, expected != Comparison::GREATER);
    EXPECT_EQ(first >= second, expected != Comparison::LESS);
  }
}

TEST(NaturalTest, Increment) {
  Natural a("1234569999");
  EXPECT_EQ(a++, Natural("1234569999"));
  EXPECT_EQ(a, Natural("1234570000"));

  Natural b("165999999");
  EXPECT_EQ(++b, Natural("166000000"));
  EXPECT_EQ(b, Natural("166000000"));
}

TEST(NaturalTest, Addition) {
  std::vector<std::tuple<Natural, Natural, Natural>> cases = {
      {Natural("1046"), Natural("599999"), Natural("601045")},
      {Natural("6541186631"), Natural("51866"), Natural("6541238497")},
      {Natural("123456789"), Natural("999999999"), Natural("1123456788")},
  };

  for (const auto &[a, b, expected] : cases) {
    Natural sum = a;
    sum += b;
    EXPECT_EQ(sum, expected);
    EXPECT_EQ(a + b, expected);
  }
}

TEST(NaturalTest, Subtraction) {
  std::vector<std::tuple<Natural, Natural, Natural, bool>> cases = {
      {Natural("23456789"), Natural("345678"), Natural("23111111"), false},
      {Natural("1234567"), Natural("999999"), Natural("234568"), false},
      {Natural("123456789"), Natural("0"), Natural("123456789"), false},
      {Natural("0"), Natural("1"), Natural(""), true},
      {Natural("9999999"), Natural("9999999"), Natural("0"), false},
  };

  for (const auto &[a, b, expected, throws] : cases) {
    if (throws) {
      EXPECT_THROW(auto result = a - b, std::invalid_argument);
    } else {
      Natural diff = a;
      diff -= b;
      EXPECT_EQ(diff, expected);
      EXPECT_EQ(a - b, expected);
    }
  }
}

TEST(NaturalTest, MultiplicationByDigit) {
  std::vector<std::tuple<Natural, Digit, Natural>> cases = {
      {Natural("9999999"), 9, Natural("89999991")},
      {Natural("5473"), 0, Natural("0")},
      {Natural("123456789"), 1, Natural("123456789")},
      {Natural("123321"), 7, Natural("863247")},
  };

  for (const auto &[value, digit, expected] : cases) {
    Natural result = value;
    result *= digit;
    EXPECT_EQ(result, expected);
    EXPECT_EQ(value * digit, expected);
  }
}

TEST(NaturalTest, Multiplication) {
  std::vector<std::tuple<Natural, Natural, Natural>> cases = {
      {Natural("123456"), Natural("987654"), Natural("121931812224")},
      {Natural("1234567890"), Natural("0"), Natural("0")},
      {Natural("0"), Natural("9876543210"), Natural("0")},
      {Natural("15468"), Natural("98484415"), Natural("1523356931220")},
  };

  for (const auto &[a, b, expected] : cases) {
    Natural product = a;
    product *= b;
    EXPECT_EQ(product, expected);
    EXPECT_EQ(a * b, expected);
  }
}

TEST(NaturalTest, DivisionQuotient) {
  std::vector<std::tuple<Natural, Natural, Natural, bool>> cases = {
      {Natural("30"), Natural("3"), Natural("10"), false},
      {Natural("4643121486"), Natural("5645631"), Natural("822"), false},
      {Natural("0"), Natural("123"), Natural("0"), false},
      {Natural("9999999999"), Natural("11188888"), Natural("893"), false},
      {Natural("108"), Natural("18"), Natural("6"), false},
      {Natural("123"), Natural("0"), Natural(""), true},
  };

  for (const auto &[a, b, expected, throws] : cases) {
    if (throws) {
      EXPECT_THROW(auto result = a / b, std::invalid_argument);
    } else {
      Natural quotient = a;
      quotient /= b;
      EXPECT_EQ(quotient, expected);
      EXPECT_EQ(a / b, expected);
    }
  }
}

TEST(NaturalTest, DivisionRemainder) {
  std::vector<std::tuple<Natural, Natural, Natural, bool>> cases = {
      {Natural("30"), Natural("3"), Natural("0"), false},
      {Natural("4643121486"), Natural("5645631"), Natural("2412804"), false},
      {Natural("0"), Natural("123"), Natural("0"), false},
      {Natural("9999999999"), Natural("11188888"), Natural("8323015"), false},
      {Natural("108"), Natural("18"), Natural("0"), false},
      {Natural("123"), Natural("0"), Natural(""), true},
  };

  for (const auto &[a, b, expected, throws] : cases) {
    if (throws) {
      EXPECT_THROW(auto result = a % b, std::invalid_argument);
    } else {
      Natural remainder = a;
      remainder %= b;
      EXPECT_EQ(remainder, expected);
      EXPECT_EQ(a % b, expected);
    }
  }
}

TEST(NaturalTest, SubtractionMultiplied) {
  std::vector<std::tuple<Natural, Natural, Digit, Natural, bool>> cases = {
      {Natural("38964841"), Natural("215894"), 4, Natural("38101265"), false},
      {Natural("4986169649"), Natural("1568943299"), 3, Natural("279339752"),
       false},
      {Natural("1234567890"), Natural("1234567890"), 1, Natural("0"), false},
      {Natural("0"), Natural("1"), 1, Natural(""), true},
  };

  for (const auto &[a, b, digit, expected, throws] : cases) {
    if (throws) {
      EXPECT_THROW(auto _ = a.SubtractMultiplied(b, digit),
                   std::invalid_argument);
    } else {
      Natural result = a;
      result.SubtractMultiplied(b, digit);
      EXPECT_EQ(result, expected);
    }
  }
}

TEST(NaturalTest, MultiplyByBasePower) {
  std::vector<std::tuple<Natural, uint32_t, Natural>> cases = {
      {Natural("5000000000"), 2, Natural("500000000000")},
      {Natural("5000000000"), 0, Natural("5000000000")},
      {Natural("0"), 3, Natural("0")},
  };

  for (const auto &[value, power, expected] : cases) {
    Natural result = value;
    result.MultiplyByBasePower(power);
    EXPECT_EQ(result, expected);
    EXPECT_EQ(value.MultiplyByBasePower(power), expected);
  }
}

TEST(NaturalTest, GetLeadingQuotientDigit) {
  std::vector<std::tuple<Natural, Natural, std::pair<Digit, uint32_t>, bool>>
      cases = {
          {Natural("2"), Natural("3"), std::make_pair(Digit(0), 0), false},
          {Natural("7"), Natural("3"), std::make_pair(Digit(2), 0), false},
          {Natural("23"), Natural("3"), std::make_pair(Digit(7), 0), false},
          {Natural("84"), Natural("3"), std::make_pair(Digit(2), 1), false},
          {Natural("2"), Natural("18"), std::make_pair(Digit(0), 0), false},
          {Natural("1"), Natural("0"), std::make_pair(Digit(0), 0), true},
      };

  for (const auto &[a, b, expected, throws] : cases) {
    if (throws) {
      EXPECT_THROW(auto _ = a.GetLeadingQuotientDigit(b),
                   std::invalid_argument);
    } else {
      EXPECT_EQ(a.GetLeadingQuotientDigit(b), expected);
    }
  }
}

TEST(NaturalTest, GreatestCommonDivisor) {
  std::vector<std::tuple<Natural, Natural, Natural>> cases = {
      {Natural("17"), Natural("19"), Natural("1")},
      {Natural("15"), Natural("1"), Natural("1")},
      {Natural("100"), Natural("100"), Natural("100")},
      {Natural("22222222222222"), Natural("444444444444"), Natural("22")},
      {Natural("100000000000"), Natural("500000000"), Natural("500000000")},
      {Natural("123"), Natural("0"), Natural("123")},
  };

  for (const auto &[a, b, expected] : cases) {
    EXPECT_EQ(Natural::GreatestCommonDivisor(a, b), expected);
  }
}

TEST(NaturalTest, LeastCommonMultiple) {
  std::vector<std::tuple<Natural, Natural, Natural>> cases = {
      {Natural("4294297"), Natural("10010496"), Natural("42988042941312")},
      {Natural("42949670"), Natural("85934590"), Natural("369086228208530")},
      {Natural("4500000000"), Natural("7000000000"), Natural("63000000000")},
      {Natural("100"), Natural("100"), Natural("100")},
  };

  for (const auto &[a, b, expected] : cases) {
    EXPECT_EQ(Natural::LeastCommonMultiple(a, b), expected);
  }
}
