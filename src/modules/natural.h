
#ifndef LONGNUMBERS_SRC_MODULES_NATURAL_H_
#define LONGNUMBERS_SRC_MODULES_NATURAL_H_

#include <cstdint>
#include <vector>

typedef uint8_t Digit;
typedef std::vector<Digit> Natural;

uint8_t COM_NN_D(Natural &a, Natural &b);

bool NZER_N_B(Natural &a);

Natural ADD_1N_N(Natural &a);

Natural ADD_NN_N(Natural &a, Natural &b);

Natural SUB_NN_N(Natural &a, Natural &b);

Natural MUL_ND_N(Natural &a, Digit d);

Natural MUL_Nk_N(Natural &a, uint32_t k);

Natural MUL_NN_N(Natural &a, Natural &b);

Natural SUB_NDN_N(Natural &a, Natural &b, Digit d);

Digit DIV_NN_Dk(Natural &a, Natural &b, uint32_t k);

Natural DIV_NN_N(Natural &a, Natural &b);

Natural MOD_NN_N(Natural &a, Natural &b);

Natural GCF_NN_N(Natural &a, Natural &b);

Natural LCM_NN_N(Natural &a, Natural &b);

#endif //LONGNUMBERS_SRC_MODULES_NATURAL_H_
