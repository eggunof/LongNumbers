
#ifndef LONGNUMBERS_SRC_MODULES_NATURAL_H_
#define LONGNUMBERS_SRC_MODULES_NATURAL_H_

#include <cstdint>
#include <vector>

typedef uint8_t Digit;
typedef std::vector<Digit> Natural;

uint8_t COM_NN_D(const Natural &a, const Natural &b);

bool NZER_N_B(const Natural &a);

Natural ADD_1N_N(const Natural &a);

Natural ADD_NN_N(const Natural &a, const Natural &b);

Natural SUB_NN_N(const Natural &a, const Natural &b);

Natural MUL_ND_N(const Natural &a, const Digit &d);

Natural MUL_Nk_N(const Natural &a, const uint32_t &k);

Natural MUL_NN_N(const Natural &a, const Natural &b);

Natural SUB_NDN_N(const Natural &a, const Natural &b, const Digit &d);

Digit DIV_NN_Dk(const Natural &a, const Natural &b, const uint32_t &k);

Natural DIV_NN_N(const Natural &a, const Natural &b);

Natural MOD_NN_N(const Natural &a, const Natural &b);

Natural GCF_NN_N(const Natural &a, const Natural &b);

Natural LCM_NN_N(const Natural &a, const Natural &b);

#endif //LONGNUMBERS_SRC_MODULES_NATURAL_H_
