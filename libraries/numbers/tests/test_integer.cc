
#include <gtest/gtest.h>

#include "integer.h"
#include "natural.h"

TEST(IntegerTest, NaturalToInteger) {
  std::vector<std::pair<Natural, Integer>> cases = {
      {Natural("12345678901234567890"), Integer("12345678901234567890")},
      {Natural("0"), Integer("0")},
  };

  for (const auto &[input, expected] : cases) {
    EXPECT_EQ(Integer(input), expected);
  }
}

TEST(IntegerTest, IntegerToNatural) {
  std::vector<std::tuple<Integer, Natural, bool>> cases = {
      {Integer("8641561246"), Natural("8641561246"), false},
      {Integer("0"), Natural("0"), false},
      {Integer("-8641561246"), Natural(), true},
  };

  for (const auto &[input, expected, throws] : cases) {
    if (throws) {
      EXPECT_THROW(auto result = Natural(input), std::invalid_argument);
    } else {
      EXPECT_EQ(Natural(input), expected);
    }
  }
}

TEST(IntegerTest, AbsoluteValue) {
  std::vector<std::pair<Integer, Integer>> cases = {
      {Integer("8641561246"), Integer("8641561246")},
      {Integer("0"), Integer("0")},
      {Integer("-8641561246"), Integer("8641561246")},
  };

  for (const auto &[input, expected] : cases) {
    EXPECT_EQ(Integer::AbsoluteValue(input), expected);
  }
}

TEST(IntegerTest, Sign) {
  std::vector<std::pair<Integer, Sign>> cases = {
      {Integer("123"), Sign::POSITIVE},
      {Integer("0"), Sign::ZERO},
      {Integer("-4846512846"), Sign::NEGATIVE},
  };

  for (const auto &[input, expected] : cases) {
    EXPECT_EQ(input.GetSign(), expected);
  }
}

TEST(IntegerTest, Negation) {
  std::vector<std::pair<Integer, Integer>> cases = {
      {Integer("4846512846"), Integer("-4846512846")},
      {Integer("-4846512846"), Integer("4846512846")},
      {Integer("0"), Integer("0")},
  };

  for (auto &[input, expected] : cases) {
    -input;
    EXPECT_EQ(input, expected);
  }
}

TEST(IntegerTest, Addition) {
  std::vector<std::tuple<Integer, Integer, Integer>> cases = {
      {Integer("4846512846"), Integer("98456198645"), Integer("103302711491")},
      {Integer("4846512846"), Integer("-98456198645"), Integer("-93609685799")},
      {Integer("-48462846"), Integer("-984561986"), Integer("-1033024832")},
      {Integer("-1234567890"), Integer("1234567890"), Integer("0")},
  };

  for (auto &[a, b, expected] : cases) {
    EXPECT_EQ(a + b, expected);
    a += b;
    EXPECT_EQ(a, expected);
  }
}

TEST(IntegerTest, Subtraction) {
  std::vector<std::tuple<Integer, Integer, Integer>> cases = {
      {Integer("1234567890"), Integer("98456198645"), Integer("-97221630755")},
      {Integer("1234567890"), Integer("-98456198645"), Integer("99690766535")},
      {Integer("1234567890"), Integer("1234567890"), Integer("0")},
      {Integer("0"), Integer("456"), Integer("-456")},
  };

  for (auto &[a, b, expected] : cases) {
    EXPECT_EQ(a - b, expected);
    a -= b;
    EXPECT_EQ(a, expected);
  }
}

TEST(IntegerTest, Multiplication) {
  std::vector<std::tuple<Integer, Integer, Integer>> cases = {
      {Integer("123"), Integer("456"), Integer("56088")},
      {Integer("-123"), Integer("456"), Integer("-56088")},
      {Integer("-123"), Integer("-456"), Integer("56088")},
      {Integer("0"), Integer("456"), Integer("0")},
  };

  for (const auto &[a, b, expected] : cases) {
    EXPECT_EQ(a * b, expected);
  }
}

TEST(IntegerTest, DivisionQuotient) {
  std::vector<std::tuple<Integer, Integer, Integer, bool>> cases = {
      {Integer("78"), Integer("33"), Integer("2"), false},
      {Integer("-78"), Integer("33"), Integer("-3"), false},
      {Integer("-78"), Integer("-33"), Integer("3"), false},
      {Integer("10"), Integer("33"), Integer("0"), false},
      {Integer("-10"), Integer("33"), Integer("-1"), false},
      {Integer("-10"), Integer("-33"), Integer("1"), false},
      {Integer("123"), Integer("0"), Integer(), true},
  };

  for (const auto &[a, b, expected, throws] : cases) {
    if (throws) {
      EXPECT_THROW(a / b, std::invalid_argument);
    } else {
      EXPECT_EQ(a / b, expected);
      Integer temp = a;
      temp /= b;
      EXPECT_EQ(temp, expected);
    }
  }
}

TEST(IntegerTest, DivisionRemainder) {
  std::vector<std::tuple<Integer, Integer, Integer, bool>> cases = {
      {Integer("78"), Integer("33"), Integer("12"), false},
      {Integer("-78"), Integer("33"), Integer("21"), false},
      {Integer("10"), Integer("33"), Integer("10"), false},
      {Integer("-10"), Integer("33"), Integer("23"), false},
      {Integer("123"), Integer("0"), Integer(), true},
  };

  for (const auto &[a, b, expected, throws] : cases) {
    if (throws) {
      EXPECT_THROW(a % b, std::invalid_argument);
    } else {
      EXPECT_EQ(a % b, expected);
      Integer temp = a;
      temp %= b;
      EXPECT_EQ(temp, expected);
    }
  }
}
