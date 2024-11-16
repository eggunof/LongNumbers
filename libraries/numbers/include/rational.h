
#ifndef NUMBERS_RATIONAL_H_
#define NUMBERS_RATIONAL_H_

#include "integer.h"
#include "natural.h"

/**
 * @class Rational
 * @brief Класс для работы с длинными рациональными числами
 */
class Rational {
 private:
  /** @brief Числитель рационального числа */
  Integer numerator_;

  /** @brief Знаменатель рационального числа */
  Natural denominator_;

 public:
  /**
   * @brief Конструктор по умолчанию, создаёт рациональное число 0/1
   */
  Rational();

  /**
   * @brief Конструктор из числителя и знаменателя
   * @param numerator Числитель
   * @param denominator Знаменатель
   */
  Rational(Integer numerator, Natural denominator);

  /**
   * @brief Конструктор преобразования из целого числа (TRANS_Z_Q)
   * @param integer Целое число
   * @author Кривошеина Дарья, гр. 3383
   */
  explicit Rational(Integer integer);

  /**
   * @brief Конструктор преобразования из натурального числа
   * @param integer Целое число
   */
  explicit Rational(Natural natural);

  /**
   * @brief Конструктор из строки
   * @param string Строковое представление рационального числа
   */
  explicit Rational(const std::string &string);

  /**
   * @brief Конструктор копирования
   * @param other Копируемое число
   */
  Rational(const Rational &other) = default;

  /**
   * @brief Оператор присваивания копированием
   * @param other Число для присваивания
   * @returns Ссылка на текущее число
   */
  Rational &operator=(const Rational &other) = default;

  /**
   * @brief Конструктор перемещения
   * @param other Перемещаемое число
   */
  Rational(Rational &&other) = default;

  /**
   * @brief Оператор присваивания перемещением
   * @param other Число для перемещения
   * @returns Ссылка на текущее число
   */
  Rational &operator=(Rational &&other) = default;

  /**
   * @brief Преобразование рационального числа в целое (TRANS_Q_Z)
   * @returns Целая часть рационального числа
   * @author Егунов Даниил, гр. 3383
   */
  explicit operator Integer() const;

  /**
   * @brief Проверка, является ли рациональное число целым (INT_Q_B)
   * @returns true, если число целое, иначе false
   * @author Матвеев Никита, гр. 3383
   */
  bool IsInteger();

  /**
   * @brief Сокращение дроби (RED_Q_Q)
   * @returns Ссылка на текущее рациональное число
   * @author Дмитриева Дарья, гр. 3383
   */
  Rational &Reduce();

  /**
   * @brief Сокращение дроби (RED_Q_Q)
   * @returns Результат сокращения
   * @author Дмитриева Дарья, гр. 3383
   */
  [[nodiscard]] Rational Reduce() const;

  /**
   * @brief Получение числителя
   * @returns Константная ссылка на числитель
   */
  [[nodiscard]] const Integer &GetNumerator() const;

  /**
   * @brief Получение знаменателя
   * @returns Константная ссылка на знаменатель
   */
  [[nodiscard]] const Natural &GetDenominator() const;

  /**
   * @brief Получение знака числа
   * @returns Знак числа (NEGATIVE, ZERO, POSITIVE)
   */
  [[nodiscard]] Sign GetSign() const;

  /**
   * @brief Оператор равенства
   * @param rhs Число для сравнения
   * @returns true, если числа равны, иначе false
   */
  bool operator==(const Rational &rhs) const;

  /**
   * @brief Оператор неравенства
   * @param rhs Число для сравнения
   * @returns true, если числа не равны, иначе false
   */
  bool operator!=(const Rational &rhs) const;

  /**
   * @brief Оператор "меньше"
   * @param rhs Число для сравнения
   * @returns true, если текущее число меньше, иначе false
   */
  bool operator<(const Rational &rhs) const;

  /**
   * @brief Оператор "больше"
   * @param rhs Число для сравнения
   * @returns true, если текущее число больше, иначе false
   */
  bool operator>(const Rational &rhs) const;

  /**
   * @brief Оператор "меньше или равно"
   * @param rhs Число для сравнения
   * @returns true, если текущее число меньше или равно, иначе false
   */
  bool operator<=(const Rational &rhs) const;

  /**
   * @brief Оператор "больше или равно"
   * @param rhs Число для сравнения
   * @returns true, если текущее число больше или равно, иначе false
   */
  bool operator>=(const Rational &rhs) const;

  /**
   * @brief Оператор смены знака числа
   * @returns Ссылка на изменённое число
   */
  Rational &operator-();

  /**
   * @brief Оператор смены знака числа
   * @returns Отрицательное значение числа
   */
  Rational operator-() const;

  /**
   * @brief Оператор сложения (ADD_QQ_Q)
   * @param rhs Число для сложения
   * @returns Ссылка на изменённое число
   * @author Майская Вероника, гр. 3384
   */
  Rational &operator+=(const Rational &rhs);

  /**
   * @brief Оператор сложения (SUB_QQ_Q)
   * @param rhs Число для сложения
   * @returns Результат сложения
   * @author Майская Вероника, гр. 3384
   */
  Rational operator+(const Rational &rhs) const;

  /**
   * @brief Оператор вычитания (SUB_QQ_Q)
   * @param rhs Число для вычитания
   * @returns Ссылка на изменённое число
   * @author Кадникова Анна, гр. 3384
   */
  Rational &operator-=(const Rational &rhs);

  /**
   * @brief Оператор вычитания (SUB_QQ_Q)
   * @param rhs Число для вычитания
   * @returns Результат вычитания
   * @author Кадникова Анна, гр. 3384
   */
  Rational operator-(const Rational &rhs) const;

  /**
   * @brief Оператор умножения (MUL_QQ_Q)
   * @param rhs Число для умножения
   * @returns Ссылка на изменённое число
   * @author Солдунова Екатерина, гр. 3383
   */
  Rational &operator*=(const Rational &rhs);

  /**
   * @brief Оператор умножения (MUL_QQ_Q)
   * @param rhs Число для умножения
   * @returns Результат умножения
   * @author Солдунова Екатерина, гр. 3383
   */
  Rational operator*(const Rational &rhs) const;

  /**
   * @brief Оператор деления (DIV_QQ_Q)
   * @param rhs Делитель
   * @returns Ссылка на изменённое число
   * @author Варфоломеева Арина, гр. 3383
   */
  Rational &operator/=(const Rational &rhs);

  /**
   * @brief Оператор деления (DIV_QQ_Q)
   * @param rhs Делитель
   * @returns Результат деления
   * @author Варфоломеева Арина, гр. 3383
   */
  Rational operator/(const Rational &rhs) const;

  /**
   * @brief Оператор ввода из потока
   * @param is Поток ввода
   * @param rational Число
   * @returns Поток ввода
   */
  friend std::istream &operator>>(std::istream &is, Rational &rational);

  /**
   * @brief Оператор вывода в поток
   * @param os Поток вывода
   * @param rational Число
   * @returns Поток вывода
   */
  friend std::ostream &operator<<(std::ostream &os, const Rational &rational);

  /**
   * @brief Преобразование числа в строку
   * @returns Строковое представление числа
   */
  [[nodiscard]] std::string ToString() const;
};

#endif  // NUMBERS_RATIONAL_H_
