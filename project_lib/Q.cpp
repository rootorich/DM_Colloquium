#include "Q.h"

Q RED_Q_Q(const Q& ratio){

    Q q;

    N gcd = GCF_NN_N(ratio.z, ratio.n);

    q.z = (q.z/gcd);
    q.n = (q.n/gcd);

    return q;

}
