#include "Z.h"

/*
 * Kate
 * Z-3
*/
Z Z::operator-() const {
  Z result;
  result.digits = digits;
  result.sign = !sign;
  return result;
}

Z ABS_Z_Z(const Z& z) {
  if (z.sign == 0) {
    return z;
  } else {
    return -z;
  }
}

N TRANS_Z_N(const Z&z) {
  N n;
  n.digits = z.digits;
  return n;
}
/*
 * End Kate
*/