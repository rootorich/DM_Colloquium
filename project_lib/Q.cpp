#include "Q.h"

Q RED_Q_Q(const Q& ratio){

    Q q;

    N gcd = GCF_NN_N(ratio.z, ratio.n);

    q.z = (ratio.z/gcd);
    q.n = (ratio.n/gcd);

    return q;

}
