#include "Z.h"

//Efimova Z-4
Z& Z:: operator=(const N& rhs) {

    digits = rhs.digits; 
    sign = 0;
    return *this;
}

Z TRANS_N_Z(const N& n){

    Z z;
    z = n;
    return z;
}

//Efimova Z-8
Z MUL_ZZ_Z(const Z& z1, const Z& z2){

    Z result;
    result = z1*z2;
    result.sign = (z1.sign == z2.sign) ? 0 : 1;
    return result;

}



