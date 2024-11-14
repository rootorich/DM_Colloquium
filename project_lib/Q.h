#include "Z.h"

#ifndef DM_COLLOQUIUM_PROJECT_LIB_Q_H_
#define DM_COLLOQUIUM_PROJECT_LIB_Q_H_

struct Q {
  Z z;
  N n;

  Q() = default;
  explicit Q(uint8_t digit);
  explicit Q(const Z& z, const N& n);
  Q& operator=(const Z& z1);
  explicit Q(const std::string& str_a, const std::string& str_b);

  std::string to_str();
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
Q operator*(const Q& q1, const uint8_t digit);
Q MUL_QQ_Q(const Q& q1, const Q& q2);

/*
 * End Kate
*/



/*
 * Q-Dop-2.1
*/
bool operator<(const Q& q1, const Q& q2);

/*
 * Q-Dop-2.2
*/
bool operator==(const Q& q1, const Q& q2);

/*
 * Q-Dop-2.3
*/
bool operator==(const Q& q1, const uint8_t digit);

#endif
