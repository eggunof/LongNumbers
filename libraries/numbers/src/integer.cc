
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

Integer Integer::operator-() const { return {}; }

Integer &Integer::operator-() { return *this; }

Integer Integer::operator+(const Integer &rhs) const { return {}; }

Integer Integer::operator-(const Integer &rhs) const { return {}; }

Integer Integer::operator/(const Integer &rhs) const { return {}; }

Integer Integer::operator%(const Integer &rhs) const { return {}; }

Integer &Integer::operator+=(const Integer &rhs) { return *this; }

Integer &Integer::operator-=(const Integer &rhs) { return *this; }

// Умножение целых чисел
// Над модулем работала Майская Вероника, гр. 3384
Integer &Integer::operator*=(const Integer &rhs) {
    // Определяем знаки текущего числа и правого операнда
    bool is_negative_this = (this->sign_ == Sign::NEGATIVE);
    bool is_negative_rhs = (rhs.sign_ == Sign::NEGATIVE);
    // Получаем абсолютные значения двух чисел и преобразуем их в натуральные числа
    Natural abs_this = ToNatural(this->AbsoluteValue(*this));
    Natural abs_rhs = ToNatural(rhs.AbsoluteValue(rhs));
    // Умножение двух натуральных чисел
    Natural result_n = abs_this * abs_rhs;
    this->digits_ = result_n.digits_;
    // Определяем знак результата
    if (result_n.IsZero()) {
        this->sign_ = Sign::ZERO;
    } else if (is_negative_this != is_negative_rhs) {
        this->sign_ = Sign::NEGATIVE;  // Если исходные знаки разные, результат отрицательный
    } else {
        this->sign_ = Sign::POSITIVE;  // Если исходные знаки одинаковые, результат положительный
    }
  return *this;
}

// Оператор умножения
// Над модулем работала Майская Вероника, гр. 3384
Integer Integer::operator*(const Integer &rhs) const {
    Integer result = *this;
    result *= rhs;
    return result;
}

Integer &Integer::operator/=(const Integer &rhs) { return *this; }

Integer &Integer::operator%=(const Integer &rhs) { return *this; }
