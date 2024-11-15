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
  Z t1;
  Z t2;

  res.n = LCM_NN_N(q1.n, q2.n);

  t1 = (q1.z * (res.n / q1.n));
  t2 = (q2.z * (res.n / q2.n));

  res.z = t1 + t2;

  return RED_Q_Q(res);
}

Q ADD_QQ_Q(const Q& q1, const Q& q2){
  return q1 + q2;
}

/*
 * End Efimova
*/



/*
 * Kate
 * Q-6
*/
Q operator-(const Q& q) {
  Q result = q;
  result.z = -result.z;

  return result;
}

Q operator-(const Q& q1, const Q& q2) {
  return RED_Q_Q(q1 + (-q2));
}

Q SUB_QQ_Q(const Q& q1, const Q& q2) {
  return q1 - q2;
}

/*
 * Q-7
*/
Q operator*(const Q& q1, const Q& q2) {
  Q result;
  result.z = q1.z * q2.z;
  result.n = q1.n * q2.n;

  return RED_Q_Q(result);
}

Q operator*(const Q& q, const uint8_t digit) {
  return RED_Q_Q(q * Q(digit));
}

Q MUL_QQ_Q(const Q& q1, const Q& q2) {
  return q1 * q2;
}

/*
 * End Kate
*/


/*
 * Q-8
*/
Q operator/(const Q& q1, const Q& q2) {
  Q temp = q2;

  std::swap(temp.z.digits, temp.n.digits);

  return q1 * temp;
}

Q DIV_QQ_Q(const Q& q1, const Q& q2) {
  return q1 / q2;
}


/*
 * Q-Dop-1.1
*/
Q::Q(uint8_t digit) {
  z = Z(digit);
  n = N(1);
}

/*
 * Q-Dop-1.2
*/
Q::Q(const Z& t_z, const N& t_n) {
  z = t_z;
  n = t_n;
}

/*
 * Q-Dop-2.1
*/
bool operator<(const Q& q1, const Q& q2) {
  Q lcn;
  Z t1;
  Z t2;

  lcn.n = LCM_NN_N(q1.n, q2.n);

  t1 = (q1.z * (lcn.n / q1.n));
  t2 = (q2.z * (lcn.n / q2.n));

  return t1 < t2;
}

/*
 * Q-Dop-2.1
*/
bool operator==(const Q& q1, const Q& q2) {
  Q lcn;
  Z t1;
  Z t2;

  lcn.n = LCM_NN_N(q1.n, q2.n);

  t1 = (q1.z * (lcn.n / q1.n));
  t2 = (q2.z * (lcn.n / q2.n));

  return t1 == t2;
}
bool operator==(const Q& q, const uint8_t digit) {
  return q.z == digit && q.n == 1;
}

