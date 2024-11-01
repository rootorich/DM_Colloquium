#include "N.h"

#ifndef DM_COLLOQUIUM_Z_H
#define DM_COLLOQUIUM_Z_H

typedef struct Z : N {
    bool sign;
} Z;


/*
 * Masha
 * Z-2
*/
uint8_t POZ_Z_D(const Z num);

/*
 * Z-6
*/
const Z operator+(const Z& z1, const Z& z2);
Z& operator+=(Z& z1, const Z& z2);
const Z ADD_NN_N(const Z& z1, const Z& z2);

/*
 * Z-10
*/
const Z operator%(const Z& z1, const Z& z2);
Z& operator%=(Z& z1, const Z& z2);
const Z MOD_ZZ_Z(const Z& z1, const Z& z2);
/*
 * End Masha
*/

#endif
