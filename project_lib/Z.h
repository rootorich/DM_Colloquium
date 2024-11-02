#include "N.h"

#ifndef DM_COLLOQUIUM_Z_H
#define DM_COLLOQUIUM_Z_H

struct Z : N {
  bool sign;

  Z operator-() const;
};

/*
 * Kate
 * Z-1
*/
Z ABS_Z_Z(const Z& z);

/*
 * Z-3
*/
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


#endif
