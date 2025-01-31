
#include "operations.h"

#include <iostream>

#include "input.h"
#include "integer.h"
#include "natural.h"
#include "polynomial.h"

void PerformNaturalOperation(int choice) {
  Natural num1, num2;
  switch (choice) {
    case 1: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      auto comparison = Natural::Compare(num1, num2);
      std::cout << "Результат сравнения: "
                << (comparison == Comparison::EQUAL  ? "Равны"
                    : comparison == Comparison::LESS ? "Меньше"
                                                     : "Больше")
                << std::endl;
      break;
    }
    case 2: {
      num1 = GetNaturalInput();
      std::cout << "Проверка на ноль: " << (num1.IsZero() ? "Да" : "Нет")
                << std::endl;
      break;
    }
    case 3: {
      num1 = GetNaturalInput();
      std::cout << "Результат после добавления 1: " << (++num1) << std::endl;
      break;
    }
    case 4: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      std::cout << "Сумма: " << (num1 + num2) << std::endl;
      break;
    }
    case 5: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      std::cout << "Результат после вычитания: " << (num1 - num2) << std::endl;
      break;
    }
    case 6: {
      num1 = GetNaturalInput();
      int digit;
      std::cout << "Введите цифру (0-9): ";
      std::cin >> digit;
      std::cout << "Результат умножения на цифру: " << (num1 * static_cast<Digit>(digit))
                << std::endl;
      break;
    }
    case 7: {
      num1 = GetNaturalInput();
      uint32_t k;
      std::cout << "Введите k (степень 10): ";
      std::cin >> k;
      std::cout << "Результат умножения на 10^k: "
                << num1.MultiplyByBasePower(k) << std::endl;
      break;
    }
    case 8: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      std::cout << "Результат умножения: " << num1 * num2 << std::endl;
      break;
    }
    case 9: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      int digit;
      std::cout << "Введите цифру (0-9): ";
      std::cin >> digit;
      std::cout << "Результат после вычитания: "
                << num1.SubtractMultiplied(num2, static_cast<Digit>(digit)) << std::endl;
      break;
    }
    case 10: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      const auto& [digit, k] =
          num1.GetLeadingQuotientDigit(num2);
      std::cout << "Первая цифра после деления: "
                << static_cast<uint16_t>(digit)
                << " k: " << k << std::endl;
      break;
    }
    case 11: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      auto result = num1 / num2;
      std::cout << "Частное: " << result << std::endl;
      break;
    }
    case 12: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      std::cout << "Остаток: " << num1 % num2 << std::endl;
      break;
    }
    case 13: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      std::cout << "НОД: " << Natural::GreatestCommonDivisor(num1, num2)
                << std::endl;
      break;
    }
    case 14: {
      num1 = GetNaturalInput();
      num2 = GetNaturalInput();
      std::cout << "НОК: " << Natural::LeastCommonMultiple(num1, num2)
                << std::endl;
      break;
    }
    default: {
      std::cout << "Неверный выбор" << std::endl;
    }
  }
}

void PerformIntegerOperation(int choice) {
  Integer num1, num2;
  switch (choice) {
    case 1: {
      num1 = GetIntegerInput();
      std::cout << "Абсолютная величина: " << Integer::AbsoluteValue(num1)
                << std::endl;
      break;
    }
    case 2: {
      num1 = GetIntegerInput();
      auto sign = num1.GetSign();
      std::cout << "Положительность числа: "
                << (sign == Sign::POSITIVE ? "Положительно"
                    : sign == Sign::ZERO   ? "Ноль"
                                           : "Отрицательно")
                << std::endl;
      break;
    }
    case 3: {
      num1 = GetIntegerInput();
      std::cout << "Результат умножения на (-1): " << (-num1) << std::endl;
      break;
    }
    case 4: {
      auto natural = GetNaturalInput();
      std::cout << "Преобразование в целое: " << static_cast<Integer>(natural)
                << std::endl;
      break;
    }
    case 5: {
      num1 = GetIntegerInput();
      std::cout << "Преобразование в натуральное: "
                << static_cast<Natural>(num1) << std::endl;

      break;
    }
    case 6: {
      num1 = GetIntegerInput();
      num2 = GetIntegerInput();
      std::cout << "Результат сложения: " << num1 + num2 << std::endl;
      break;
    }
    case 7: {
      num1 = GetIntegerInput();
      num2 = GetIntegerInput();
      std::cout << "Результат вычитания: " << num1 - num2 << std::endl;
      break;
    }
    case 8: {
      num1 = GetIntegerInput();
      num2 = GetIntegerInput();
      std::cout << "Результат умножения: " << num1 * num2 << std::endl;
      break;
    }
    case 9: {
      num1 = GetIntegerInput();
      num2 = GetIntegerInput();
      std::cout << "Частное: " << num1 / num2 << std::endl;
      break;
    }
    case 10: {
      num1 = GetIntegerInput();
      num2 = GetIntegerInput();
      std::cout << "Остаток: " << num1 % num2 << std::endl;
      break;
    }
    default: {
      std::cout << "Неверный выбор" << std::endl;
    }
  }
}

void PerformRationalOperation(int choice) {
  Rational num1, num2;

  switch (choice) {
    case 1: {
      num1 = GetRationalInput();
      std::cout << "Сокращенная дробь: " << num1.Reduce() << std::endl;
      break;
    }
    case 2: {
      num1 = GetRationalInput();
      std::cout << "Проверка на целое: " << (num1.IsInteger() ? "Да" : "Нет")
                << std::endl;
      break;
    }
    case 3: {
      auto integer = GetIntegerInput();
      std::cout << "Результат: " << static_cast<Rational>(integer) << std::endl;
      break;
    }
    case 4: {
      num1 = GetRationalInput();
      std::cout << "Результат: " << static_cast<Integer>(num1) << std::endl;
      break;
    }
    case 5: {
      num1 = GetRationalInput();
      num2 = GetRationalInput();
      std::cout << "Результат сложения: " << num1 + num2 << std::endl;
      break;
    }
    case 6: {
      num1 = GetRationalInput();
      num2 = GetRationalInput();
      std::cout << "Результат вычитания: " << num1 - num2 << std::endl;
      break;
    }
    case 7: {
      num1 = GetRationalInput();
      num2 = GetRationalInput();
      std::cout << "Результат умножения: " << num1 * num2 << std::endl;
      break;
    }
    case 8: {
      num1 = GetRationalInput();
      num2 = GetRationalInput();
      std::cout << "Результат деления: " << num1 / num2 << std::endl;
      break;
    }
    default: {
      std::cout << "Неверный выбор" << std::endl;
    }
  }
}

void PerformPolynomialOperation(int choice) {
  Polynomial p1, p2;

  switch (choice) {
    case 1: {
      p1 = GetPolynomialInput();
      p2 = GetPolynomialInput();
      std::cout << "Результат сложения: " << p1 + p2 << std::endl;
      break;
    }
    case 2: {
      p1 = GetPolynomialInput();
      p2 = GetPolynomialInput();
      std::cout << "Результат вычитания: " << p1 - p2 << std::endl;
      break;
    }
    case 3: {
      p1 = GetPolynomialInput();
      auto scalar = GetRationalInput();
      std::cout << "Результат умножения: " << p1 * scalar << std::endl;
      break;
    }
    case 4: {
      p1 = GetPolynomialInput();
      uint32_t k;
      std::cout << "Введите степень (натуральное число или 0): ";
      std::cin >> k;
      std::cout << "Результат умножения на x^" << k << ": "
                << p1.MultiplyByXPower(k) << std::endl;
      break;
    }
    case 5: {
      p1 = GetPolynomialInput();
      std::cout << "Старший коэффициент: " << p1.GetLeadingCoefficient()
                << std::endl;
      break;
    }
    case 6: {
      p1 = GetPolynomialInput();
      std::cout << "Степень многочлена: " << p1.GetDegree() << std::endl;
      break;
    }
    case 7: {
      p1 = GetPolynomialInput();
      std::cout << "Вынесенный множитель: " << p1.ToIntegerCoefficients()
                << " многочлен после преобразования: " << p1 << std::endl;
      break;
    }
    case 8: {
      p1 = GetPolynomialInput();
      p2 = GetPolynomialInput();
      std::cout << "Результат умножения: " << p1 * p2 << std::endl;
      break;
    }
    case 9: {
      p1 = GetPolynomialInput();
      p2 = GetPolynomialInput();
      std::cout << "Частное: " << p1 / p2 << std::endl;
      break;
    }
    case 10: {
      p1 = GetPolynomialInput();
      p2 = GetPolynomialInput();
      std::cout << "Остаток: " << p1 % p2 << std::endl;
      break;
    }
    case 11: {
      p1 = GetPolynomialInput();
      p2 = GetPolynomialInput();
      std::cout << "НОД многочленов: "
                << Polynomial::GreatestCommonDivisor(p1, p2) << std::endl;
      break;
    }
    case 12: {
      p1 = GetPolynomialInput();
      std::cout << "Производная: " << Polynomial::Derivative(p1) << std::endl;
      break;
    }
    case 13: {
      p1 = GetPolynomialInput();
      std::cout << "Многочлен с нормализованными корнями: "
                << Polynomial::NormalizeRoots(p1) << std::endl;
      break;
    }
    default: {
      std::cout << "Неверный выбор" << std::endl;
    }
  }
}
