#include "Z.h"

using namespace std::rel_ops;

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
 * Z-6
*/
Z operator+(const Z& z1, const Z& z2) {
  N n1{z1.digits};
  N n2{z2.digits};

  Z result;
  if (z1.sign == z2.sign) {
    result.digits = (n1 + n2).digits;
    result.sign = z1.sign;
  } else {
    if (n1 > n2) {
      result.digits = (n1 - n2).digits;
      result.sign = z1.sign;
    } else {
      result.digits = (n2 - n1).digits;
      result.sign = z2.sign;
    }
  }
  return result;
}

Z& Z::operator+=(const Z& z) {
  *this = *this + z;
  return *this;
}

Z ADD_NN_N(const Z& z1, const Z& z2) {
  return z1 + z2;
}

/*
 * Z-10
*/
Z operator%(const Z& z1, const Z& z2) {
  return z1 - (z2 * (z1 / z2));
}

Z& Z::operator%=(const Z& z2) {
  *this = *this % z2;
  return *this;
}

Z MOD_ZZ_Z(const Z& z1, const Z& z2) {
  return z1 % z2;
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
Z operator*(const Z& z1, const Z& z2) {
  N n1 = z1;
  N n2 = z2;
  Z result;
  result = n1 * n2;
  result.sign = z1.sign != z2.sign;

  return result;
}

Z MUL_ZZ_Z(const Z& z1, const Z& z2) {
  return z1 * z2;
}

/*
 * End Efimova
*/
