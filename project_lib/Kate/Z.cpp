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
 * Z-9
*/
Z operator/(const Z& z1, const Z& z2) {
  N n1 = z1;
  N n2 = z2;
  N div = n1 / n2;
  Z result;
  result.digits = div.digits;
  result.sign = (z1.sign != z2.sign);
  return result;
}

Z DIV_ZZ_Z(const Z& z1, const Z& z2) {
  return z1 / z2;
}
/*
 * End Kate
*/
