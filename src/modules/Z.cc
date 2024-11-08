
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

//Сумма целых чисел
//Над модулем работала Кадникова Анна, гр. 3384
Z ADD_ZZ_Z(Z a, Z b) {
  N a_new = TRANS_Z_N(a);
  N b_new = TRANS_Z_N(b);
  N sum_a_b;
  bool sign;
  //если знаки одинаковые, просто суммируем модули
  //и знак результата - знак обоих чисел
  if (a.sign == b.sign){
    N sum_a_b = ADD_NN_N(a_new, b_new);
    bool sign = a.sign;
  }
  //если знаки разные, то вычитаем из большего меньшее и присваиваем знак большего модуля
  else{
    if (COM_NN_D(a_new, b_new)==2){
      N sum_a_b = SUB_NN_N(a_new, b_new);
      bool sign = a.sign;
    }
    else{
      N sum_a_b = SUB_NN_N(b_new, a_new);
      bool sign = b.sign;
    }
  }
  Z result = TRANS_N_Z(sum_a_b);
  result.sign = sign;
  return result;
}

Z SUB_ZZ_Z(Z a, Z b) {
  return Z();
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