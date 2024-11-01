#include "Z.h"

/*
 * Masha
 * Z-2
*/
uint8_t POZ_Z_D(const Z num) {
    if (num.digits.size() == 1 && num.digits[0] == 0)
        return 0;
    return num.sign + 1; 
}

/*
 * Z-6
*/
const Z operator+(const Z& z1, const Z& z2) {
    N n1{z1.digits};
    N n2{z2.digits};

    Z result;
    if (z1.sign == z2.sign) {
        result.digits = (n1 + n2).digits;
        result.sign = z1.sign;
    } else {
        result.digits = SUB_NN_N(n1, n2).digits;
        result.sign = (n1 < n2) ? z2.sign : z1.sign;
    }
    return result;
}

Z& operator+=(Z& z1, const Z& z2) {
    z1 = z1 + z2;
    return z1;
}

const Z ADD_NN_N(const Z& z1, const Z& z2) {
    return z1 + z2;
}

/*
 * Z-10
*/
const Z operator%(const Z& z1, const Z& z2) {
    return z1 - z2*(z1/z2);
}

Z& operator%=(Z& z1, const Z& z2) {
    z1 = z1%z2;
    return z1;
}

const Z MOD_ZZ_Z(const Z& z1, const Z& z2) {
    return z1%z2;
}
/*
 * End Masha
*/