#include "N.h"

#ifndef DM_COLLOQUIUM_Z_H
#define DM_COLLOQUIUM_Z_H

struct Z : N {
  bool sign;

  Z& operator=(const N& n);
  Z& operator+=(const Z& z);
  Z& operator%=(const Z& z2);

  Z() = default;
  Z(const std::string& str);

  std::string to_str();
};

/*
 * Kate
 * Z-1
*/
Z ABS_Z_Z(const Z& z);

/*
 * Z-3
*/
Z operator-(const Z& z);
Z MUL_ZM_Z(const Z& z);

/*
 * Z-5
*/
N TRANS_Z_N(const Z& z);

/*
 * End Kate
*/

/*
 * Savranraskii Danila
 * Z-7
*/

Z operator-(const Z& z1, const Z& z2);
void operator-=(Z& z1, const Z& z2);
Z SUB_ZZ_Z(Z const &z1, Z const &z2);

/*
 * End Savranraskii Danila
*/


/*
 * Masha
 * Z-2
*/
uint8_t POZ_Z_D(const Z& num);

/*
 * Z-6
*/
Z operator+(const Z& z1, const Z& z2);
Z ADD_NN_N(const Z& z1, const Z& z2);

/*
 * Z-10
*/
Z operator%(const Z& z1, const Z& z2);
Z MOD_ZZ_Z(const Z& z1, const Z& z2);

/*
 * End Masha
*/

/*
 * Efimova
 * Z-4
*/
Z TRANS_N_Z(const N& n);

/*
 * Z-8
*/
Z MUL_ZZ_Z(const Z& z1, const Z& z2);

/*
 * End Efimova
*/

#endif
