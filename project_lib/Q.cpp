#include "Q.h"

/*
 * Efimova
 * Q-1
*/
Q RED_Q_Q(const Q& q){
  Q result;

  N gcd = GCF_NN_N(q.z, q.n);

  result.z = (q.z / gcd);
  result.n = (q.n / gcd);

  return result;
}

/*
 * Q-2
*/
bool INT_Q_B(const Q& q){
  return q.n == 1;
}


/*
 * Q-3
*/
Q& Q::operator=(const Z& z1){
  z = z1;
  n.digits.emplace_back(1);

  return *this;
}

Q TRANS_Z_Q(const Z& z){
  Q q;
  q = z;

  return q;
}


/*
 * Q-4
*/
Z TRANS_Q_Z(const Q& q){
  Z z;
  z = q.z;

  return z;
}


/*
 * Q-5
*/
Q operator+(const Q& q1, const Q& q2){
  Q res;
  Q t1;
  Q t2;

  res.n = LCM_NN_N(q1.n, q2.n);

  t1.z = (q1.z * (res.n / q1.n));
  t2.z = (q2.z * (res.n / q2.n));

  res.z = t1.z + t2.z;

  return RED_Q_Q(res);
}

Q ADD_QQ_Q(const Q& q1, const Q& q2){
  return q1 + q2;
}

/*
 * End Efimova
*/
