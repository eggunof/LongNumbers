
#ifndef LONGNUMBERS_SRC_MODULES_Z_H_
#define LONGNUMBERS_SRC_MODULES_Z_H_

#include "N.h"

struct Z {
  N number;
  bool sign;
};

N ABS_Z_N(const N &a);

uint8_t POZ_Z_D(const Z &a);

Z MUL_ZM_Z(const Z &a);

Z TRANS_N_Z(const N &a);

N TRANS_Z_N(const Z &a);

Z ADD_ZZ_Z(const Z &a, const Z &b);

Z SUB_ZZ_Z(const Z &a, const Z &b);

Z MUL_ZZ_Z(const Z &a, const Z &b);

Z DIV_ZZ_Z(const Z &a, const Z &b);

Z MOD_ZZ_Z(const Z &a, const Z &b);

#endif //LONGNUMBERS_SRC_MODULES_Z_H_
