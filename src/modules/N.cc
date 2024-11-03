
#include "N.h"

uint8_t COM_NN_D(const N &a, const N &b) {
  return 0;
}

bool NZER_N_B(const N &a) {
  return false;
}

N ADD_1N_N(const N &a) {
  return N();
}

N ADD_NN_N(const N &a, const N &b) {
  return N();
}

//Вычитание из числа натурального А число натуральное число B, при этом A >= B
N SUB_NN_N(const N &a, const N &b) {
    //Дополняем вектор b нулями
    while (b.size() < a.size()) {
        b.insert(b.begin(), 0);
    }
    // Выполняем вычитание по разрядам (справа налево)
    for (int i = a.size() - 1; i > 0; i--) {
        // Проверяем, нужно ли заимствовать из следующего разряда
        if (a[i] < b[i]) {
            // Заимствуем единицу из следующего разряда
            a[i] += 10;
            // Вычитаем единицу из следующего разряда
            a[i - 1]--;
        }
        // Вычитаем цифры текущего разряда
        a[i] -= b[i];
    }
    // Обрабатываем самый левый разряд отдельно
    a[0] -= b[0];

    // Удаляем ведущие нули
    while (a.size() > 1 && a[0] == 0) {
        a.erase(a.begin());
    }
    return a;
}

N MUL_ND_N(const N &a, const Digit &d) {
  return N();
}

N MUL_Nk_N(const N &a, const uint32_t &k) {
  return N();
}

N MUL_NN_N(const N &a, const N &b) {
  return N();
}

N SUB_NDN_N(const N &a, const N &b, const Digit &d) {
  return N();
}

Digit DIV_NN_Dk(const N &a, const N &b, const uint32_t &k) {
  return 0;
}

N DIV_NN_N(const N &a, const N &b) {
  return N();
}

N MOD_NN_N(const N &a, const N &b) {
  return N();
}

N GCF_NN_N(const N &a, const N &b) {
  return N();
}

N LCM_NN_N(const N &a, const N &b) {
  return N();
}
