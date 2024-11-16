#ifndef NUMBERS_NATURAL_H
#define NUMBERS_NATURAL_H

#include <cstdint>
#include <string>
#include <vector>

/**
 * @typedef Digit
 * @brief Тип для представления цифр
 */
typedef uint8_t Digit;

/**
 * @enum Comparison
 * @brief Перечисление для сравнения чисел
 */
enum class Comparison { EQUAL = 0, LESS = 1, GREATER = 2 };

/**
 * @class Natural
 * @brief Класс для работы с длинными натуральными числами
 */
class Natural {
 private:
  /** @brief Вектор цифр числа */
  std::vector<Digit> digits_;

 public:
  /** @brief Основание системы счисления */
  constexpr static uint8_t kBase = 10;

  /**
   * @brief Конструктор по умолчанию, создаёт 0
   */
  Natural();

  /**
   * @brief Конструктор из вектора цифр
   * @param digits Вектор цифр числа
   */
  explicit Natural(const std::vector<Digit> &digits);

  /**
   * @brief Конструктор из строки
   * @param string Строковое представление числа
   */
  explicit Natural(const std::string &string);

  /**
   * @brief Конструктор из неотрицательного числа
   * @param number Неотрицательное число
   */
  explicit Natural(uint32_t number);

  /**
   * @brief Конструктор копирования
   * @param other Копируемое число
   */
  Natural(const Natural &other) = default;

  /**
   * @brief Оператор присваивания копированием
   * @param other Число для присваивания
   * @returns Ссылка на текущее число
   */
  Natural &operator=(const Natural &other) = default;

  /**
   * @brief Конструктор перемещения
   * @param other Перемещаемое число
   */
  Natural(Natural &&other) = default;

  /**
   * @brief Оператор присваивания перемещением
   * @param other Число для перемещения
   * @returns Ссылка на текущее число
   */
  Natural &operator=(Natural &&other) = default;

  /**
   * @brief Проверка, является ли число нулём (NZER_N_B)
   * @returns true, если число равно нулю, иначе false
   */
  [[nodiscard]] bool IsZero() const;

  /**
   * @brief Оператор приведения к bool
   * @returns true, если число равно нулю, иначе false
   */
  explicit operator bool() const;

  /**
   * @brief Сравнение двух натуральных чисел (COM_NN_D)
   * @param first Первое число
   * @param second Второе число
   * @returns Результат сравнения (EQUAL, LESS, GREATER)
   * @author Майская Вероника, гр. 3384
   */
  static Comparison Compare(const Natural &first, const Natural &second);

  /**
   * @brief Оператор равенства
   * @param rhs Второе число
   * @returns true, если числа равны, иначе false
   */
  bool operator==(const Natural &rhs) const;

  /**
   * @brief Оператор неравенства
   * @param rhs Второе число
   * @returns true, если числа не равны, иначе false
   */
  bool operator!=(const Natural &rhs) const;

  /**
   * @brief Оператор "меньше"
   * @param rhs Второе число
   * @returns true, если текущее число меньше, иначе false
   */
  bool operator<(const Natural &rhs) const;

  /**
   * @brief Оператор "больше"
   * @param rhs Второе число
   * @returns true, если текущее число больше, иначе false
   */
  bool operator>(const Natural &rhs) const;

  /**
   * @brief Оператор "меньше или равно"
   * @param rhs Второе число
   * @returns true, если текущее число меньше или равно, иначе false
   */
  bool operator<=(const Natural &rhs) const;

  /**
   * @brief Оператор "больше или равно"
   * @param rhs Второе число
   * @returns true, если текущее число больше или равно, иначе false
   */
  bool operator>=(const Natural &rhs) const;

  /**
   * @brief Префиксный инкремент числа (ADD_1N_N)
   * @returns Увеличенное число
   * @author Солдунова Екатерина, гр. 3383
   */
  Natural &operator++();

  /**
   * @brief Постфиксный инкремент числа (ADD_1N_N)
   * @returns Увеличенное число
   * @author Солдунова Екатерина, гр. 3383
   */
  Natural operator++(int);

  /**
   * @brief Сложение с другим натуральным числом (ADD_NN_N)
   * @param rhs Второе число
   * @returns Ссылка на изменённое число
   * @author Варфоломеева Арина, гр. 3383
   */
  Natural &operator+=(const Natural &rhs);

  /**
   * @brief Сложение с другим натуральным числом (ADD_NN_N)
   * @param rhs Второе число
   * @returns Результат сложения
   * @author Варфоломеева Арина, гр. 3383
   */
  Natural operator+(const Natural &rhs) const;

  /**
   * @brief Вычитание другого натурального числа (SUB_NN_N)
   * @param rhs Второе число
   * @returns Ссылка на изменённое число
   * @author Дмитриева Дарья, гр. 3383
   */
  Natural &operator-=(const Natural &rhs);

  /**
   * @brief Вычитание другого натурального числа (SUB_NN_N)
   * @param rhs Второе число
   * @returns Результат вычитания
   * @author Дмитриева Дарья, гр. 3383
   */
  Natural operator-(const Natural &rhs) const;

  /**
   * @brief Умножение на цифру (MUL_ND_N)
   * @param d Цифра
   * @returns Ссылка на изменённое число
   * @author Матвеев Никита, гр. 3383
   */
  Natural &operator*=(Digit d);

  /**
   * @brief Умножение на цифру (MUL_ND_N)
   * @param d Цифра
   * @returns Результат умножения
   * @author Матвеев Никита, гр. 3383
   */
  Natural operator*(Digit d) const;

  /**
   * @brief Умножение на другое натуральное число (MUL_NN_N)
   * @param rhs Второе число
   * @returns Ссылка на изменённое число
   * @author Егунов Даниил, гр. 3383
   */
  Natural &operator*=(const Natural &rhs);

  /**
   * @brief Умножение на другое натуральное число (MUL_NN_N)
   * @param rhs Второе число
   * @returns Результат умножения
   * @author Егунов Даниил, гр. 3383
   */
  Natural operator*(const Natural &rhs) const;

  /**
   * @brief Деление на другое натуральное число (DIV_NN_N)
   * @param rhs Делитель
   * @returns Ссылка на изменённое число
   * @author Дмитриева Дарья, гр. 3383
   */
  Natural &operator/=(const Natural &rhs);

  /**
   * @brief Деление на другое натуральное число (DIV_NN_N)
   * @param rhs Делитель
   * @returns Результат деления
   * @author Дмитриева Дарья, гр. 3383
   */
  Natural operator/(const Natural &rhs) const;

  /**
   * @brief Остаток от деления на другое натуральное число (MOD_NN_N)
   * @param rhs Делитель
   * @returns Ссылка на изменённое число
   * @author Егунов Даниил, гр. 3383
   */
  Natural &operator%=(const Natural &rhs);

  /**
   * @brief Остаток от деления на другое натуральное число (MOD_NN_N)
   * @param rhs Делитель
   * @returns Остаток от деления
   * @author Егунов Даниил, гр. 3383
   */
  Natural operator%(const Natural &rhs) const;

  /**
   * @brief Вычитание произведения числа на цифру (SUB_NDN_N)
   * @param rhs Второе число
   * @param d Цифра
   * @returns Ссылка на изменённое число
   * @author Солдунова Екатерина, гр. 3383
   */
  Natural &SubtractMultiplied(const Natural &rhs, Digit d);

  /**
   * @brief Вычитание произведения числа на цифру (SUB_NDN_N)
   * @param rhs Второе число
   * @param d Цифра
   * @returns Результат вычитания
   */
  [[nodiscard]] Natural SubtractMultiplied(const Natural &rhs, Digit d) const;

  /**
   * @brief Умножение числа на kBase^k (MUL_Nk_N)
   * @param k Степень
   * @returns Ссылка на результат
   * @author Кривошеина Дарья, гр. 3383
   */
  Natural &MultiplyByBasePower(uint32_t k);

  /**
   * @brief Умножение на kBase^k (MUL_Nk_N)
   * @param k Степень
   * @returns Результат умножения
   * @author Кривошеина Дарья, гр. 3383
   */
  [[nodiscard]] Natural MultiplyByBasePower(uint32_t k) const;

  /**
   * @brief Получение старшей цифры частного и степени десяти (DIV_NN_Dk)
   * @param rhs Делитель
   * @returns Пара: цифра и степень десяти
   * @author Варфоломеева Арина, гр. 3383
   */
  [[nodiscard]] std::pair<Digit, uint32_t> GetLeadingQuotientDigit(
      const Natural &rhs) const;

  /**
   * @brief НОД двух чисел (GCD_NN_N)
   * @param first Первое число
   * @param second Второе число
   * @returns Наибольший общий делитель
   * @author Кадникова Анна, гр. 3384
   */
  static Natural GreatestCommonDivisor(const Natural &first,
                                       const Natural &second);

  /**
   * @brief НОК двух чисел (LCM_NN_N)
   * @param first Первое число
   * @param second Второе число
   * @returns Наименьшее общее кратное
   * @author Майская Вероника, гр. 3384
   */
  static Natural LeastCommonMultiple(const Natural &first,
                                     const Natural &second);

  /**
   * @brief Оператор ввода из потока
   * @param is Поток ввода
   * @param number Число
   * @returns Поток ввода
   */
  friend std::istream &operator>>(std::istream &is, Natural &number);

  /**
   * @brief Оператор вывода в поток
   * @param os Поток вывода
   * @param number Число
   * @returns Поток вывода
   */
  friend std::ostream &operator<<(std::ostream &os, const Natural &number);

  /**
   * @brief Преобразование числа в строку
   * @returns Строковое представление числа
   */
  [[nodiscard]] std::string ToString() const;
};

#endif  // NUMBERS_NATURAL_H
