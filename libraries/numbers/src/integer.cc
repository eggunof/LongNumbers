
#include "integer.h"

#include <algorithm>

Integer::Integer(const std::vector<Digit> &digits, Sign sign)
    : natural_(digits), sign_(sign) {
  if (natural_.IsZero()) {
    sign_ = Sign::ZERO;
  }
}

Integer::Integer(const std::string &string)
    : natural_(string.substr(string.find_first_not_of("+-"))) {
  if (natural_.IsZero()) {
    sign_ = Sign::ZERO;
  } else {
    size_t minus_count = std::count_if(string.begin(), string.end(),
                                       [](char c) { return c == '-'; });
    sign_ = (minus_count % 2 == 0) ? Sign::POSITIVE : Sign::NEGATIVE;
  }
}

Integer::Integer(const Natural &natural) {}

Integer::operator Natural() const { return {}; }

Integer Integer::AbsoluteValue(const Integer &integer) { return {}; }

bool Integer::operator==(const Integer &rhs) const {
  return natural_ == rhs.natural_ && sign_ == rhs.sign_;
}

bool Integer::operator!=(const Integer &rhs) const { return !(rhs == *this); }

bool Integer::operator<(const Integer &rhs) const {
  if (sign_ < rhs.sign_) return true;
  if (sign_ > rhs.sign_) return false;
  return natural_ < rhs.natural_;
}

bool Integer::operator>(const Integer &rhs) const { return rhs < *this; }

bool Integer::operator<=(const Integer &rhs) const { return !(rhs < *this); }

bool Integer::operator>=(const Integer &rhs) const { return !(*this < rhs); }

Integer Integer::operator-() const { return {}; }

Integer &Integer::operator-() { return *this; }

// Сложение целых чисел
// Над модулем работала Солдунова Екатерина, гр. 3383
Integer Integer::operator+(const Integer &rhs) const { 
    Integer result = *this;
    result += rhs;
    return result; 
}

Integer Integer::operator-(const Integer &rhs) const { return {}; }

// Умножение целых чисел "*"
// Над модулем работала Майская Вероника, гр. 3384
Integer Integer::operator*(const Integer &rhs) const {
  Integer result = *this;
  result *= rhs;
  return result;
}

Integer Integer::operator/(const Integer &rhs) const { return {}; }

Integer Integer::operator%(const Integer &rhs) const { return {}; }

// Сложение целых чисел
// Над модулем работала Солдунова Екатерина, гр. 3383
Integer &Integer::operator+=(const Integer &rhs) { 
    // Для прибавления к положительному отрицательного, вычитаем модуль отрицательного из положительного
    if ((sign_ == Sign::POSITIVE) && (rhs.sign_ == Sign::NEGATIVE)) *this -= AbsoluteValue(rhs);
    // Для прибавления к отрицательному положительного
    if ((sign_ == Sign::NEGATIVE) && (rhs.sign_ == Sign::POSITIVE)){
        if (nature_ < rhs.nature_){
            nature_ = rhs.nature_ - nature_;
            sign_ = Sign::POSITIVE;
        }
        else nature_ -= rhs.nature;
    }
    // Если знаки совпадают, складываем натуральные части
    if (sign_ == rhs.sign_) natural_ += rhs.natural;
    if (natural_.IsZero()) sign_ = Sign::ZERO;
    return *this; 
}

Integer &Integer::operator-=(const Integer &rhs) { return *this; }

// Умножение целых чисел "*="
// Над модулем работала Майская Вероника, гр. 3384
Integer &Integer::operator*=(const Integer &rhs) {
  // Перемножаем натуральные части
  natural_ *= rhs.natural_;
  // Определяем знак результата
  sign_ = (sign_ == rhs.sign_) ? Sign::POSITIVE : Sign::NEGATIVE;
  if (natural_.IsZero()) sign_ = Sign::ZERO;
  return *this;
}

Integer &Integer::operator/=(const Integer &rhs) { return *this; }

Integer &Integer::operator%=(const Integer &rhs) { return *this; }
