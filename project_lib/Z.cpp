#include "Z.h"

/*
 * Kate
 * Z-1
*/
Z ABS_Z_Z(const Z& z) {
  if (z.sign == 0) {
    return z;
  } else {
    return -z;
  }
}

/*
 * Z-3
*/
Z operator-(const Z& z) {
  Z result;
  result.digits = z.digits;
  result.sign = !z.sign;

  return result;
}

Z MUL_ZM_Z(const Z& z) {
  return -z;
}

/*
 * Z-5
*/
N TRANS_Z_N(const Z& z) {
  N n;
  n = z;
  return n;
}

/*
 * End Kate
*/



/*
 * Masha
 * Z-2
*/
uint8_t POZ_Z_D(const Z& num) {
  if (num.digits.size() == 1 && num == 0) {
    return 0;
  } else {
    return num.sign + 1;
  }
}

/*
 * End Masha
*/


/*
 * Efimova
 * Z-4
*/
Z& Z:: operator=(const N& rhs) {
  digits = rhs.digits;
  sign = 0;
  return *this;
}

Z TRANS_N_Z(const N& n) {
  Z z;
  z = n;
  return z;
}

/*
 * Z-8
*/
Z MUL_ZZ_Z(const Z& z1, const Z& z2) {
  Z result;
  result = z1*z2;
  result.sign = z1.sign != z2.sign;

  return result;
}

/*
 * End Efimova
*/
