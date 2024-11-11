
#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, GCDTest){
    Polynomial pol1({
        {Natural(0), Rational(Integer(1), Natural(1))},
        {Natural(1), Rational(Integer(2), Natural(1))},
        {Natural(2), Rational(Integer(1), Natural(1))}
    });
    Polynomial pol2({
        {Natural(0), Rational(Integer(1), Natural(1))},
        {Natural(1), Rational(Integer(1), Natural(1))},
    });
    EXPECT_EQ(Polynomial::GreatestCommonDivisor(pol1, pol2), pol2);
    EXPECT_EQ(Polynomial::GreatestCommonDivisor(pol2, pol1), pol2);
    Polynomial pol3({
        {Natural(5), Rational(Integer(2), Natural(1))},
        {Natural(4), Rational(Integer(-3), Natural(1))},
        {Natural(3), Rational(Integer(-5), Natural(1))},
        {Natural(2), Rational(Integer(1), Natural(1))},
        {Natural(1), Rational(Integer(6), Natural(1))},
        {Natural(0), Rational(Integer(3), Natural(1))}
    });
    Polynomial pol4({
         {Natural(4), Rational(Integer(3), Natural(1))},
         {Natural(3), Rational(Integer(2), Natural(1))},
         {Natural(2), Rational(Integer(-3), Natural(1))},
         {Natural(1), Rational(Integer(-5), Natural(1))},
         {Natural(0), Rational(Integer(-2), Natural(1))}
    });
    Polynomial res({
        {Natural(3), Rational(Integer(1), Natural(1))},
        {Natural(1), Rational(Integer(-1), Natural(1))},
        {Natural(0), Rational(Integer(-1), Natural(1))}
    });
    EXPECT_EQ(Polynomial::GreatestCommonDivisor(pol3, pol4), res);
    EXPECT_EQ(Polynomial::GreatestCommonDivisor(pol4, pol3), res);
    Polynomial pol5({
        {Natural(2), Rational(Integer(1), Natural(1))},
        {Natural(1), Rational(Integer(1), Natural(1))},
        {Natural(0), Rational(Integer(1), Natural(1))}
    });
    Polynomial pol6({
        {Natural(1), Rational(Integer(-1), Natural(1))},
    });
    Polynomial res2({
        {Natural(0), Rational(Integer(1), Natural(1))},
    });
    EXPECT_EQ(Polynomial::GreatestCommonDivisor(pol5, pol6), res2);
}
