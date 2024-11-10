
#include "integer.h"

#include <algorithm>
#include <stdexcept>

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

// Преобразование целого неотрицательного в натуральное
// Над модулем работала Варфоломеева Арина, гр. 3383
Integer::operator Natural() const {
  if (sign_ == Sign::NEGATIVE) {
    throw std::invalid_argument(
        "Invalid input: Converting a negative integer to natural");
  }
  return natural_;
}

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

// Сумма целых чисел
// над модулем работала Кадникова Анна, гр.3384
Integer Integer::operator+(const Integer &rhs) const {
  Natural a_new = ToNatural(*this);
  Natural b_new = ToNatural(rhs);
  Natural sum_a_b;
  Sign sign;
  // если знаки одинаковые, просто суммируем модули и знак результата — знак
  // обоих чисел
  if (this->sign_ == rhs.sign_) {
    sum_a_b = a_new + b_new;
    sign = rhs.sign_;
  }
  // если знаки разные, то вычитаем из большего меньшее и присваиваем знак
  // большего модуля
  else {
    if (a_new == b_new){
      sign = Sign::ZERO;
      sum_a_b = a_new - b_new;
    }
    else{
      if (a_new > b_new) {
        sum_a_b = a_new - b_new;
        sign = this->sign_;
      } else {
        sum_a_b = b_new - a_new;
        sign = rhs.sign_;
      }
    }
    
  }
  Integer result = Integer(sum_a_b);
  result.sign_ = sign;
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

Integer &Integer::operator+=(const Integer &rhs) { 
  *this = *this + rhs;
  return *this; }

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
