
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

// преобразование целого неотрицательного в натуральное; Варфоломеева Арина
N TRANS_Z_N(Z a) {
    if (!a.sign) { // число отрицательное
        std::cerr << "Ошибка: число должно быть целым неотрицательным" << std::endl;
    }
    else { // число неотрицательное
        if (a.number[0] == 0 && a.number.size() == 1) { // если число равно 0, то оно преобразуется в 1. Иначе не меняется
            a.number[0] = 1;
        }
    }
    return a.number;
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
  return Z();
}

Z MOD_ZZ_Z(Z a, Z b) {
  return Z();
}
