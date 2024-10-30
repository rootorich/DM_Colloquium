#include "N.h"
//Efimova

bool operator==(const N& num, int zero) {
    return num.digits.size() == 1 && num.digits[0] == zero;
}

bool operator==(int zero, const N& num) {
    return num == zero; 
}

bool operator!=(const N& num, int zero) {
    return !(num == zero);
}

bool operator!=(int zero, const N& num) {
    return !(num == zero);
}

bool NZER_N_B(const N& num) {
    return num != 0;
}
