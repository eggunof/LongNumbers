
#ifndef NUMBERS_INTEGER_H_
#define NUMBERS_INTEGER_H_

#include "natural.h"

/**
 * @enum Sign
 * @brief Перечисление для знака числа
 */
enum class Sign { NEGATIVE = -1, ZERO = 0, POSITIVE = 1 };

/**
 * @class Integer
 * @brief Класс для работы с длинными целыми числами
 */
class Integer {
 private:
  /** @brief Натуральная часть числа */
  Natural natural_;

  /** @brief Знак числа */
  Sign sign_;

 public:
  /**
   * @brief Конструктор по умолчанию, создаёт 0
   */
  Integer();

  /**
   * @brief Конструктор из натурального числа и знака
   * @param natural Натуральная часть числа
   * @param sign Знак числа
   */
  Integer(Natural natural, Sign sign);

  /**
   * @brief Конструктор из вектора цифр и знака
   * @param digits Вектор цифр числа
   * @param sign Знак числа
   */
  Integer(const std::vector<Digit> &digits, Sign sign);

  /**
   * @brief Конструктор из строки
   * @param string Строковое представление целого числа
   */
  explicit Integer(const std::string &string);

  /**
   * @brief Конструктор из 32-битного целого числа
   * @param number 32-битное целое число
   */
  explicit Integer(int32_t number);

  /**
   * @brief Конструктор копирования
   * @param other Копируемое число
   */
  Integer(const Integer &other) = default;

  /**
   * @brief Оператор присваивания копированием
   * @param other Число для присваивания
   * @returns Ссылка на текущее число
   */
  Integer &operator=(const Integer &other) = default;

  /**
   * @brief Конструктор перемещения
   * @param other Перемещаемое число
   */
  Integer(Integer &&other) = default;

  /**
   * @brief Оператор присваивания перемещением
   * @param other Число для перемещения
   * @returns Ссылка на текущее число
   */
  Integer &operator=(Integer &&other) = default;

  /**
   * @brief Конструктор преобразования из натурального числа
   * @param natural Натуральная часть числа
   * @returns Целое число с положительным знаком
   * @author Дмитриева Дарья, гр. 3383
   */
  explicit Integer(Natural natural);

  /**
   * @brief Преобразование неотрицательного числа в натуральное
   * @returns Натуральная часть числа
   * @author Варфоломеева Арина, гр. 3383
   */
  explicit operator Natural() const;

  /**
   * @brief Оператор приведения к bool
   * @returns true, если число равно нулю, иначе false
   */
  explicit operator bool() const;

  /**
   * @brief Абсолютное значение целого числа
   * @param integer Целое число
   * @returns Абсолютное значение целого числа
   * @author Егунов Даниил, гр. 3383
   */
  static Integer AbsoluteValue(const Integer &integer);

  /**
   * @brief Получение знака числа
   * @returns Знак числа (NEGATIVE, ZERO, POSITIVE)
   * @author Кривошеина Дарья, гр. 3383
   */
  [[nodiscard]] Sign GetSign() const;

  /**
   * @brief Оператор равенства
   * @param rhs Число для сравнения
   * @returns true, если числа равны, иначе false
   */
  bool operator==(const Integer &rhs) const;

  /**
   * @brief Оператор неравенства
   * @param rhs Число для сравнения
   * @returns true, если числа не равны, иначе false
   */
  bool operator!=(const Integer &rhs) const;

  /**
   * @brief Оператор "меньше"
   * @param rhs Число для сравнения
   * @returns true, если текущее число меньше, иначе false
   */
  bool operator<(const Integer &rhs) const;

  /**
   * @brief Оператор "больше"
   * @param rhs Число для сравнения
   * @returns true, если текущее число больше, иначе false
   */
  bool operator>(const Integer &rhs) const;

  /**
   * @brief Оператор "меньше или равно"
   * @param rhs Число для сравнения
   * @returns true, если текущее число меньше или равно, иначе false
   */
  bool operator<=(const Integer &rhs) const;

  /**
   * @brief Оператор "больше или равно"
   * @param rhs Число для сравнения
   * @returns true, если текущее число больше или равно, иначе false
   */
  bool operator>=(const Integer &rhs) const;

  /**
   * @brief Оператор смены знака числа
   * @returns Ссылка на изменённое число
   * @author Матвеев Никита, гр. 3383
   */
  Integer &operator-();

  /**
   * @brief Оператор смены знака числа (без изменения исходного числа)
   * @returns Отрицательное значение числа
   * @author Матвеев Никита, гр. 3383
   */
  Integer operator-() const;

  /**
   * @brief Оператор сложения
   * @param rhs Число для сложения
   * @returns Ссылка на изменённое число
   * @author Кадникова Анна, гр. 3384
   */
  Integer &operator+=(const Integer &rhs);

  /**
   * @brief Оператор сложения
   * @param rhs Число для сложения
   * @returns Результат сложения
   * @author Кадникова Анна, гр. 3384
   */
  Integer operator+(const Integer &rhs) const;

  /**
   * @brief Оператор вычитания
   * @param rhs Число для вычитания
   * @returns Ссылка на изменённое число
   * @author Кадникова Анна, гр. 3384
   */
  Integer &operator-=(const Integer &rhs);

  /**
   * @brief Оператор вычитания
   * @param rhs Число для вычитания
   * @returns Результат вычитания
   * @author Кадникова Анна, гр. 3384
   */
  Integer operator-(const Integer &rhs) const;

  /**
   * @brief Оператор умножения
   * @param rhs Число для умножения
   * @returns Ссылка на изменённое числ
   * @author Майская Вероника, гр. 3384о
   */
  Integer &operator*=(const Integer &rhs);

  /**
   * @brief Оператор умножения
   * @param rhs Число для умножения
   * @returns Результат умножения
   * @author Майская Вероника, гр. 3384
   */
  Integer operator*(const Integer &rhs) const;

  /**
   * @brief Оператор деления
   * @param rhs Число для деления
   * @returns Ссылка на изменённое число
   * @author Майская Вероника, гр. 3384
   */
  Integer &operator/=(const Integer &rhs);

  /**
   * @brief Оператор деления
   * @param rhs Число для деления
   * @returns Результат деления
   * @author Майская Вероника, гр. 3384
   */
  Integer operator/(const Integer &rhs) const;

  /**
   * @brief Оператор остатка от деления
   * @param rhs Делитель
   * @returns Ссылка на изменённое число
   * @author Матвеев Никита, гр. 3383
   */
  Integer &operator%=(const Integer &rhs);

  /**
   * @brief Оператор остатка от деления
   * @param rhs Делитель
   * @returns Остаток от деления
   * @author Матвеев Никита, гр. 3383
   */
  Integer operator%(const Integer &rhs) const;

  /**
   * @brief НОД двух целых чисел
   * @param first Первое число
   * @param second Второе число
   * @returns Наибольший общий делитель
   */
  static Integer GreatestCommonDivisor(const Integer &first,
                                       const Integer &second);

  /**
   * @brief НОК двух целых чисел
   * @param first Первое число
   * @param second Второе число
   * @returns Наименьшее общее кратное
   */
  static Integer LeastCommonMultiple(const Integer &first,
                                     const Integer &second);

  /**
   * @brief Оператор ввода из потока
   * @param is Поток ввода
   * @param number Число
   * @returns Поток ввода
   */
  friend std::istream &operator>>(std::istream &is, Integer &number);

  /**
   * @brief Оператор вывода в поток
   * @param os Поток вывода
   * @param number Число
   * @returns Поток вывода
   */
  friend std::ostream &operator<<(std::ostream &os, const Integer &number);

  /**
   * @brief Преобразование числа в строку
   * @returns Строковое представление числа
   */
  [[nodiscard]] std::string ToString() const;
};

#endif  // NUMBERS_INTEGER_H_
