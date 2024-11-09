
#include "natural.h"

#include <stdexcept>

Natural::Natural(const std::vector<Digit> &digits) {
  if (digits.empty()) {
    throw std::invalid_argument("Invalid input: vector must not be empty");
  }
  digits_.reserve(digits.size());
  for (Digit digit : digits) {
    if (digit >= 10) {
      throw std::invalid_argument("Invalid input: digit must be less than 10");
    }
    if (!digits_.empty() || digit != 0) {
      digits_.push_back(digit);
    }
  }
  if (digits_.empty()) {
    digits_.push_back(0);
  }
  digits_.shrink_to_fit();
}

Natural::Natural(const std::string &string) {
  if (string.empty()) {
    throw std::invalid_argument(
        "Invalid input: string must contain at least one digit");
  }
  digits_.reserve(string.length());
  for (char digit : string) {
    Digit x = digit - '0';
    if (x >= 10) {
      throw std::invalid_argument(
          "Invalid input: non-digit character in string");
    }
    if (!digits_.empty() || x != 0) {
      digits_.push_back(x);
    }
  }
  if (digits_.empty()) {
    digits_.push_back(0);
  }
  digits_.shrink_to_fit();
}

Comparison Natural::Compare(const Natural &first, const Natural &second) {
  return Comparison::EQUAL;
}

bool Natural::operator==(const Natural &rhs) const { return false; }

bool Natural::operator!=(const Natural &rhs) const { return false; }

bool Natural::operator<(const Natural &rhs) const { return false; }

bool Natural::operator>(const Natural &rhs) const { return false; }

bool Natural::operator<=(const Natural &rhs) const { return false; }

bool Natural::operator>=(const Natural &rhs) const { return false; }

bool Natural::IsZero() const { return digits_.size() == 1 && digits_[0] == 0; }

Natural &Natural::operator++() { return *this; }

Natural &Natural::operator++(int) { return *this; }

Natural Natural::operator+(const Natural &rhs) const { return {}; }

Natural Natural::operator-(const Natural &rhs) const { return {}; }

Natural Natural::operator*(Digit d) const { return {}; }

Natural Natural::operator*(const Natural &rhs) const { return {}; }

Natural Natural::operator/(const Natural &rhs) const { return {}; }

Natural Natural::operator%(const Natural &rhs) const { return {}; }

// Сложение натуральных чисел "+="
// Над модулем работала Варфоломеева Арина, гр. 3383
Natural &Natural::operator+=(const Natural &rhs) {
  // Если длина правого операнда (rhs) больше, чем длина текущего (this),
  // добавляем недостающие нули в начало
  if (rhs.digits_.size() > this->digits_.size()) {
    for (int i = 0; i <= (rhs.digits_.size() - this->digits_.size()); i++) {
      this->digits_.insert(this->digits_.begin(), 0);
    }
  }
  // перенос в следующий разряд
  uint8_t surplus = 0;
  // изначальное значение разряда текущего числа
  // подходящее значение левого операнда rhs
  uint8_t old_digit, rhs_digit;
  // Проходим по разрядам чисел справа налево (от младших к старшим)
  for (int i = this->digits_.size() - 1, j = rhs.digits_.size() - 1; i >= 0;
       --i, --j) {
    // если индекс j правого операнда rhs меньше нуля, берем 0 (rhs имеет меньше
    // разрядов, чем this) иначе берем текущий разряд правого операнда
    if (j >= 0) {
      rhs_digit = rhs.digits_[j];
    } else {
      rhs_digit = 0;
    }
    // записываем старое значение разряда текущего числа
    old_digit = this->digits_[i];
    // складываем текущие разряды операндов и перенос;
    // заменяем текущий разряд левого операнда на остаток от деления на 10
    this->digits_[i] = (old_digit + rhs_digit + surplus) % 10;
    // обновляем перенос путём деления нацело суммы разрядов операндов и
    // переноса
    surplus = (old_digit + rhs_digit + surplus) / 10;
  }
  // если избыток не равен 0, дописываем его в начало
  if (surplus != 0) {
    this->digits_.insert(this->digits_.begin(), surplus);
  }
  return *this;
}

Natural &Natural::operator-=(const Natural &rhs) { return *this; }

Natural &Natural::operator*=(Digit d) { return *this; }

Natural &Natural::operator*=(const Natural &rhs) { return *this; }

Natural &Natural::operator/=(const Natural &rhs) { return *this; }

Natural &Natural::operator%=(const Natural &rhs) { return *this; }

Natural &Natural::SubtractMultiplied(const Natural &rhs, Digit d) {
  return *this;
}

Natural &Natural::MultiplyBy10Power(uint32_t k) { return *this; }

Digit Natural::GetLeadingDigitAfterDivision(const Natural &rhs, uint32_t k) {
  return {};
}

Natural Natural::GreatestCommonDivisor(const Natural &first,
                                       const Natural &second) {
  return {};
}

Natural Natural::LeastCommonMultiple(const Natural &first,
                                     const Natural &second) {
  return {};
}
