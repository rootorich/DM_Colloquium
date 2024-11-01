#include "Z.h"

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


