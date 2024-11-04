#include "Z.h"

#ifndef DM_COLLOQUIUM_PROJECT_LIB_Q_H_
#define DM_COLLOQUIUM_PROJECT_LIB_Q_H_

struct Q {
  Z z;
  N n;

  Q& operator=(const Z& z1);
};

/*
 * Efimova
 * Q-1
*/
Q RED_Q_Q(const Q& q);

/*
 * Q-2
*/
bool INT_Q_B(const Q& q);

/*
 * Q-3
*/
Q TRANS_Z_Q(const Z& z);

/*
 * Q-4
*/
Z TRANS_Q_Z(const Q& q);

/*
 * Q-5
*/
Q operator+(const Q& q1, const Q& q2);
Q ADD_QQ_Q(const Q& q1, const Q& q2);

/*
 * End Efimova
*/


/*
 * Kate
 * Q-6
*/
Q operator-(const Q& q);
Q operator-(const Q& q1, const Q& q2);
Q SUB_QQ_Q(const Q& q1, const Q& q2);

/*
 * Q-7
*/
Q operator*(const Q& q1, const Q& q2);
Q MUL_QQ_Q(const Q& q1, const Q& q2);

/*
 * End Kate
*/

#endif
