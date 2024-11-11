
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

// Абсолютная величина числа
// Над модулем работал Егунов Даниил, гр. 3383
Integer Integer::AbsoluteValue(const Integer &integer) {
  // Если число равно нулю, возвращаем его
  if (integer.natural_.IsZero()) return integer;
  // Иначе устанавливаем положительный знак
  return {integer.natural_, Sign::POSITIVE};
}

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

// Умножение целых чисел на -1
// Над модулем работал Матвеев Никита, гр. 3383
Integer Integer::operator-() const {
  // Копия умножается на -1 и возвращается
  Integer result = *this;
  return -result;
}

// Умножение целых чисел на -1
// Над модулем работал Матвеев Никита, гр. 3383
Integer &Integer::operator-() {
  if (sign_ == Sign::NEGATIVE) {
    // Если знак был "-", то становится "+"
    sign_ = Sign::POSITIVE;
  } else if (sign_ == Sign::POSITIVE) {
    // Если знак был "+", то становится "-"
    sign_ = Sign::NEGATIVE;
  }
  return *this;
}

// Сложение целых чисел "+"
// Над модулем работала Кадникова Анна, гр. 3384
Integer Integer::operator+(const Integer &rhs) const {
  Integer result = *this;
  result += rhs;
  return result;
}

// Вычитание целых чисел "-"
// Над модулем работала Кадникова Анна, гр. 3384
Integer Integer::operator-(const Integer &rhs) const {
  Integer result = *this;
  result -= rhs;
  return result;
}

// Умножение целых чисел "*"
// Над модулем работала Майская Вероника, гр. 3384
Integer Integer::operator*(const Integer &rhs) const {
  Integer result = *this;
  result *= rhs;
  return result;
}

Integer Integer::operator/(const Integer &rhs) const { return {}; }

Integer Integer::operator%(const Integer &rhs) const { return {}; }

// Сложение целых чисел "+="
// Над модулем работала Кадникова Анна, гр. 3384
Integer &Integer::operator+=(const Integer &rhs) {
  if (sign_ == rhs.sign_) {
    // Если знаки одинаковые — складываем натуральные части
    natural_ += rhs.natural_;
  } else if (natural_ > rhs.natural_) {
    // Если знаки разные и текущее число больше, вычитаем из натуральной части
    // левого операнда
    natural_ -= rhs.natural_;
  } else if (natural_ < rhs.natural_) {
    // Если знаки разные и текущее число меньше, вычитаем из натуральной части
    // правого операнда и меняем знак
    natural_ = rhs.natural_ - natural_;
    sign_ = rhs.sign_;
  } else {
    // Если знаки разные и натуральные части равны, результатом будет ноль
    natural_ = Natural(0);
    sign_ = Sign::ZERO;
  }
  return *this;
}

// Вычитание целых чисел "-="
// Над модулем работала Кадникова Анна, гр. 3384
Integer &Integer::operator-=(const Integer &rhs) {
  // Применяем сложение с противоположным знаком
  *this += -rhs;
  return *this;
}

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
