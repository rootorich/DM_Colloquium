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


Q& Q:: operator=(const Z& z1){

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
//Efimova
