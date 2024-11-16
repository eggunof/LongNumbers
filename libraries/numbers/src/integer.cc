
#include "integer.h"

#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <utility>

Integer::Integer() : natural_(), sign_(Sign::ZERO) {}

Integer::Integer(Natural natural, Sign sign)
    : natural_(std::move(natural)), sign_(sign) {
  if (natural_.IsZero())
    sign_ = Sign::ZERO;
  else if (sign_ == Sign::ZERO)
    natural_ = Natural("0");
}

Integer::Integer(const std::vector<Digit> &digits, Sign sign)
    : Integer(Natural(digits), sign) {}

Integer::Integer(const std::string &string)
    : natural_(string.substr(string.find_first_not_of("+- "))) {
  if (natural_.IsZero()) {
    sign_ = Sign::ZERO;
  } else {
    size_t minus_count = std::count_if(string.begin(), string.end(),
                                       [](char c) { return c == '-'; });
    sign_ = (minus_count % 2 == 0) ? Sign::POSITIVE : Sign::NEGATIVE;
  }
}

Integer::Integer(int32_t number) {
  if (number >= 0) {
    sign_ = number != 0 ? Sign::POSITIVE : Sign::ZERO;
    natural_ = Natural(number);
  } else {
    sign_ = Sign::NEGATIVE;
    natural_ = Natural(-number);
  }
}

Integer::Integer(Natural natural)
    : natural_(std::move(natural)),
      sign_(natural_.IsZero() ? Sign::ZERO : Sign::POSITIVE) {}

Integer::operator Natural() const {
  if (sign_ == Sign::NEGATIVE) {
    throw std::invalid_argument(
        "Invalid input: Converting a negative integer to natural");
  }
  return natural_;
}

Integer::operator bool() const { return sign_ == Sign::ZERO; }

Integer Integer::AbsoluteValue(const Integer &integer) {
  // Если число равно нулю, возвращаем его
  if (integer.natural_.IsZero()) return integer;
  // Иначе устанавливаем положительный знак
  return {integer.natural_, Sign::POSITIVE};
}

Sign Integer::GetSign() const { return sign_; }

bool Integer::operator==(const Integer &rhs) const {
  return natural_ == rhs.natural_ && sign_ == rhs.sign_;
}

bool Integer::operator!=(const Integer &rhs) const { return !(rhs == *this); }

bool Integer::operator<(const Integer &rhs) const {
  if (sign_ < rhs.sign_) return true;
  if (sign_ > rhs.sign_) return false;
  return sign_ == Sign::POSITIVE ? natural_ < rhs.natural_
                                 : natural_ > rhs.natural_;
}

bool Integer::operator>(const Integer &rhs) const { return rhs < *this; }

bool Integer::operator<=(const Integer &rhs) const { return !(rhs < *this); }

bool Integer::operator>=(const Integer &rhs) const { return !(*this < rhs); }

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

Integer Integer::operator-() const {
  // Копия умножается на -1 и возвращается
  Integer result = *this;
  return -result;
}

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

Integer Integer::operator+(const Integer &rhs) const {
  Integer result = *this;
  result += rhs;
  return result;
}

Integer &Integer::operator-=(const Integer &rhs) {
  // Применяем сложение с противоположным знаком
  *this += -rhs;
  return *this;
}

Integer Integer::operator-(const Integer &rhs) const {
  Integer result = *this;
  result -= rhs;
  return result;
}

Integer &Integer::operator*=(const Integer &rhs) {
  // Перемножаем натуральные части
  natural_ *= rhs.natural_;
  // Определяем знак результата
  sign_ = (sign_ == rhs.sign_) ? Sign::POSITIVE : Sign::NEGATIVE;
  if (natural_.IsZero()) sign_ = Sign::ZERO;
  return *this;
}

Integer Integer::operator*(const Integer &rhs) const {
  Integer result = *this;
  result *= rhs;
  return result;
}

Integer &Integer::operator/=(const Integer &rhs) {
  if (sign_ != Sign::NEGATIVE) {
    // Если делимое положительное, делим натуральные части
    natural_ /= rhs.natural_;
    // Устанавливаем знак делителя частному
    sign_ = rhs.sign_;
  } else {
    // Иначе делим натуральные части и устанавливаем частному знак
    // противоположный знаку делителя
    auto quotient = Integer(natural_ / rhs.natural_, rhs.sign_);
    -quotient;
    // Если произведение делителя и частного не равно (больше) делимого
    if (*this != rhs * quotient) {
      // Увеличиваем частное на 1
      if (rhs.sign_ == Sign::POSITIVE)
        quotient -= Integer("1");
      else
        quotient += Integer("1");
    }
    // Записываем частное в текущее число
    *this = quotient;
  }
  // Если частное оказалось нулём, устанавливаем соответсвующий знак
  if (natural_.IsZero()) sign_ = Sign::ZERO;
  return *this;
}

Integer Integer::operator/(const Integer &rhs) const {
  Integer result = *this;
  result /= rhs;
  return result;
}

Integer &Integer::operator%=(const Integer &rhs) {
  // Вычисляем неполное частное
  Integer quotient = *this / rhs;
  // Вычитаем из делимого неполное частное, умноженное на делитель
  *this -= rhs * quotient;
  return *this;
}

Integer Integer::operator%(const Integer &rhs) const {
  Integer result = *this;
  result %= rhs;
  return result;
}

Integer Integer::GreatestCommonDivisor(const Integer &first,
                                       const Integer &second) {
  // Копируем числа
  Integer a = first;
  Integer b = second;
  // Применим алгоритм Евклида
  // Пока одно из чисел не станет равным нулю, продолжаем делить
  while (b.GetSign() != Sign::ZERO) {
    // Находим остаток от деления первого на второе
    Integer remainder = a % b;
    // Первое становится вторым
    a = b;
    // Второе становится остатком
    b = remainder;
  }
  // Возвращается НОД
  return a;
}

Integer Integer::LeastCommonMultiple(const Integer &first,
                                     const Integer &second) {
  // Вычисляем НОД двух чисел
  Integer gcd = GreatestCommonDivisor(first, second);
  Integer lcm = (first * second) / gcd;
  return lcm;
}

std::istream &operator>>(std::istream &is, Integer &number) {
  size_t minus_count = 0;
  do {
    is >> std::ws;
    uint8_t c = is.peek();
    if (c != '-' && c != '+') break;
    is.get();
    ++minus_count;
  } while (true);
  is >> number.natural_;
  number.sign_ = number.natural_.IsZero() ? Sign::ZERO
                 : minus_count % 2 == 0   ? Sign::POSITIVE
                                          : Sign::NEGATIVE;
  return is;
}

std::ostream &operator<<(std::ostream &os, const Integer &number) {
  if (number.sign_ == Sign::NEGATIVE) os << "-";
  os << number.natural_;
  return os;
}

std::string Integer::ToString() const {
  std::ostringstream result;
  result << *this;
  return result.str();
}
