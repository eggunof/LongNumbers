
#include "integer.h"

#include <algorithm>

Integer::Integer(const std::vector<Digit> &digits, Sign sign) : Natural(digits), sign_(sign) {
  if (IsZero()) {
    sign_ = Sign::ZERO;
  }
}

Integer::Integer(const std::string &string)
    : Natural(string.substr(string.find_first_not_of("+-"))) {
  if (IsZero()) {
    sign_ = Sign::ZERO;
  } else {
    size_t minus_count = std::count_if(string.begin(), string.end(),
                                       [](char c) { return c == '-'; });
    sign_ = (minus_count % 2 == 0) ? Sign::POSITIVE : Sign::NEGATIVE;
  }
}

Integer::Integer(const Natural &natural) {

}

Natural Integer::ToNatural(const Integer &integer) {
  return {};
}

Integer Integer::AbsoluteValue(const Integer &integer) {
  return {};
}

Integer Integer::operator-() const {
  return {};
}

Integer &Integer::operator-() {
  return *this;
}

//Сумма целых чисел
//над модулем работала Кадникова Анна, гр.3384
Integer Integer::operator+(const Integer &rhs) const {
  Natural a_new = ToNatural(*this);
  Natural b_new = ToNatural(rhs);
  Natural sum_a_b;
  Sign sign;
  //если знаки одинаковые, просто суммируем модули
  //и знак результата - знак обоих чисел
  if (this->sign_ == rhs.sign_){
    sum_a_b = a_new + b_new;
    sign = rhs.sign_;
  }
  //если знаки разные, то вычитаем из большего меньшее и присваиваем знак большего модуля
  else{
    if (a_new > b_new){
      sum_a_b = a_new - b_new;
      sign = this->sign_;
    }
    else{
      sum_a_b = b_new - a_new;
      sign = rhs.sign_;
    }
  }
  Integer result = Integer(sum_a_b);
  result.sign_ = sign;
  return result;
}

Integer Integer::operator-(const Integer &rhs) const {
  return {};
}

Integer Integer::operator*(const Integer &rhs) const {
  return {};
}

Integer Integer::operator/(const Integer &rhs) const {
  return {};
}

Integer Integer::operator%(const Integer &rhs) const {
  return {};
}

Integer &Integer::operator+=(const Integer &rhs) {
  return *this;
}

Integer &Integer::operator-=(const Integer &rhs) {
  return *this;
}

Integer &Integer::operator*=(const Integer &rhs) {
  return *this;
}

Integer &Integer::operator/=(const Integer &rhs) {
  return *this;
}

Integer &Integer::operator%=(const Integer &rhs) {
  return *this;
}
