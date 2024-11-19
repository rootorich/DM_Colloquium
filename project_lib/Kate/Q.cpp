#include "Q.h"
/*
 * Kate
 * Q-6
*/
Q Q::operator-() const {
  Q result = *this;
  result.z.sign = (!result.z.sign);
  return result;
}

Q operator+(const Q& q1, const Q& q2) {
  Q result;
  result.n = LCM_NN_N(q1.n, q2.n);
  result.z = ((q1.z * (result.n / q1.n)) + (q2.z * (result.n / q2.n)));
  return RED_Q_Q(result);
}

Q operator-(const Q& q1, const Q& q2) {
  return RED_Q_Q(q1 + (-q2));
}

Q operator*(const Q& q1, const Q& q2) {
  Q result;
  result.z = q1.z * q2.z;
  result.n = q1.n * q2.n;
  return RED_Q_Q(result);
}

Q SUB_QQ_Q(const Q& q1, const Q& q2) {
  return q1 - q2;
}

Q MUL_QQ_Q(const Q& q1, const Q& q2) {
  return q1 * q2;
}
/*
 * End Kate
*/