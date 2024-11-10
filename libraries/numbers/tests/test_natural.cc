
#include <gtest/gtest.h>

#include "natural.h"

TEST(NaturalTest, CreateEmpty) {
  Natural natural;
  EXPECT_TRUE(natural.IsZero());
}

TEST(NaturalTest, ADD_NN_N) {
  Natutal a(10099);
  Natural b(599999);
  a += b;
  EXPECT_EQ(a, Natural(610098));
}
