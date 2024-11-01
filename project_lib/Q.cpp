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
//Efimova
