#include "Q.h"

#include "Q.h"
//Efimova
Q RED_Q_Q(const Q& ratio){

    Q q;

    N gcd = GCF_NN_N(ratio.z, ratio.n);

    q.z = (ratio.z/gcd);
    q.n = (ratio.n/gcd);

    return q;

}

bool INT_Q_B(const Q& ratio){

    if(ratio.n == 1) return true;
    return false;

}


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

Z TRANS_Q_Z(const Q& ratio){

    Z z;
    z = ratio.z;
    return z;
    
}



 Q& operator+(const Q& q1, const Q& q2){

    Q q;

    Q q3;
    Q q4;

    q.n = LCM_NN_N(q1.n, q2.n);

    q3.z = (q1.z*(q.n/q1.n));
    q4.z = (q2.z*(q.n/q2.n));

    q.z = q3.z + q4.z;

    return RED_Q_Q(q);


}

Q ADD_QQ_Q(const Q& q1, const Q& q2){

    return q1+q2;
}

//Efimova

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

Q operator-(const Q& q) {
    return q*(-1);
}