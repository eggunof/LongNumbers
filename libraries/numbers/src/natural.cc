
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

Natural &Natural::operator+=(const Natural &rhs) { return *this; }

// Разность натуральных чисел "-="
// Над модулем работала Дмитриева Дарья, гр. 3383
Natural &Natural::operator-=(const Natural &rhs) {
  // Выполняем вычитание по разрядам (справа налево)
  for (int i = digits_.size() - 1, j = rhs.digits_.size() - 1; i >= 0;
       i--, j--) {
    // Получаем текущую цифру из правого операнда (rhs)
    // Если индекс j меньше 0, считаем цифру равной 0 (это значит, что не
    // осталось цифр для вычитания)
    uint8_t digit = (j >= 0) ? rhs.digits_[j] : 0;
    // Проверяем, нужно ли заимствовать из следующего разряда
    if (this->digits_[i] < digit) {
      // Заимствуем единицу из следующего разряда
      this->digits_[i] += 10;
      this->digits_[i - 1]--;
    }
    // Вычитаем текущую цифру (digit) из текущего разряда (this->digits_[i])
    this->digits_[i] -= digit;
  }
  // Удаляем ведущие нули
  while (this->digits_.size() > 1 && this->digits_[0] == 0) {
    this->digits_.erase(this->digits_.begin());
  }
  return *this;
}

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
