
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

//Вычитание целых чисел
//над модулем работала Кадникова Анна, гр. 3384
Z SUB_ZZ_Z(Z a, Z b) {
  //для вычитания можно применить сложение с противоположным знаком
  Z new_b = MUL_ZM_Z(b);
  Z result = ADD_ZZ_Z(a, new_b);
  return result;
}

Z MUL_ZZ_Z(Z a, Z b) {
  return Z();
}

Z DIV_ZZ_Z(Z a, Z b) {
  return Z();
}

Z MOD_ZZ_Z(Z a, Z b) {
  return Z();
}