#include "N.h"

#ifndef DM_COLLOQUIUM_Z_H
#define DM_COLLOQUIUM_Z_H

struct Z : N {
  bool sign;


  Z& operator=(const N& n);
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
 * Masha
 * Z-2
*/
uint8_t POZ_Z_D(const Z& num);

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
