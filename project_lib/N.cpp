#include "N.h"

// MUL_Nk_N
N operator<<(N num, const uint8_t k) {
    if (num != 0)    // if num equal to zero don't change it
        num.digits.resize(num.digits.size()+k);
    return num;
}

void operator<<=(N& num, const uint8_t k) {
    if (num != 0)
        num.digits.resize(num.digits.size()+k);
}

N MUL_Nk_N(const N num, const uint8_t k) {
    return num<<k;
}
