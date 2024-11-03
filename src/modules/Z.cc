
#include "Z.h"

N ABS_Z_N(N a) {
  return N();
}

uint8_t POZ_Z_D(Z a) {
  return 0;
}

Z MUL_ZM_Z(Z a) {
  return Z();
}

Z TRANS_N_Z(N a) {
  return Z();
}

N TRANS_Z_N(Z a) {
  return N();
}

Z ADD_ZZ_Z(Z a, Z b) {
  return Z();
}

Z SUB_ZZ_Z(Z a, Z b) {
  return Z();
}

Z MUL_ZZ_Z(Z a, Z b) {
  return Z();
}

Z DIV_ZZ_Z(Z a, Z b) {
  // Абсолютные значения делимого и делителя
  N absA = ABS_Z_N(a);
  N absB = ABS_Z_N(b);

  // Выполняем деление для абсолютных значений
  N quotient = DIV_NN_N(absA, absB);

  // Определяем знак результата
  bool resultSign = a.sign != b.sign;

  // Возвращаем результат в виде структуры Z
  return Z{quotient, resultSign};
}

Z MOD_ZZ_Z(Z a, Z b) {
  return Z();
}
