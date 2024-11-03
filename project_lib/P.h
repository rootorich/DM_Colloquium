#include "Q.h"

//Efimova
struct P {
    std::vector<Q> a;

};

P operator-(const P& p1);
P operator+(const P& p1, const P& p2);
P operator-(const P& p1, const P& p2);
P operator*(const P& p, const Q& q);
P MUL_PQ_P(const P& p, const Q& q);
P ADD_PP_P(const P& p1, const P& p2);
P SUB_PP_P(const P& p1, const P& p2);

//Efimova


/*
 * Masha
 * P-11
*/
P GCF_PP_P(const P& poly1, const P& poly2);

/*
 P-12
*/
P DER_P_P(const P& poly);

/*
 * P-13
*/
P NMR_P_P(const P& poly);
/*
 * End Mash
*/