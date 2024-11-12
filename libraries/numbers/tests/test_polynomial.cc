
#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, Multiplication) {
    Polynomial pol1({{Natural(0), Rational(Integer(1), Natural(1))},
                     {Natural(1), Rational(Integer(2), Natural(1))},
                     {Natural(2), Rational(Integer(3), Natural(1))}});
    Polynomial pol2({
        {Natural(0), Rational(Integer(2), Natural(1))},
        {Natural(1), Rational(Integer(6), Natural(1))},
    });
    pol1 *= pol2;
    Polynomial pol_expexted1({
    {Natural(0), Rational(Integer(2), Natural(1))},
    {Natural(1), Rational(Integer(10), Natural(1))},
    {Natural(2), Rational(Integer(18), Natural(1))},
    {Natural(3), Rational(Integer(18), Natural(1))}
    });

    EXPECT_EQ(pol1, pol_expected);

    Polynomial pol3({{Natural(0), Rational(Integer(10), Natural(1))},
                     {Natural(1), Rational(Integer(16), Natural(1))}});
    Polynomial pol4({{Natural(0), Rational(Integer(16), Natural(1))}});
    pol3 *= pol4;
    Polynomial pol_expexted2({
    {Natural(0), Rational(Integer(160), Natural(1))}, 
    {Natural(1), Rational(Integer(256), Natural(1))}  
    });
    EXPECT_EQ(pol3, pol_expexted2);
}
