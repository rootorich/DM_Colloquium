#include "Q.h"

#ifndef DM_COLLOQUIUM_PROJECT_LIB_P_H_
#define DM_COLLOQUIUM_PROJECT_LIB_P_H_

struct P {
  std::vector<Q> a;
};

/*
 * Efimova
 * P-1
*/
P operator+(const P& p1, const P& p2);
P ADD_PP_P(const P& p1, const P& p2);

/*
 * P-2
*/
P operator-(const P& p1);
P operator-(const P& p1, const P& p2);
P SUB_PP_P(const P& p1, const P& p2);

/*
 * P-3
*/
P operator*(const P& p, const Q& q);
P MUL_PQ_P(const P& p, const Q& q);


/*
 * End Efimova
*/

/*
* Savranraskii Danila
* P-4
*/

P MUL_Pxk_P(const P &p, uint32_t k);

/*
 * P-5
*/

Q LED_P_Q(const P &p);

/*
 * P-6
*/

N DEG_P_N(const P &p);

/*
 * P-7
*/

Q FAC_P_Q(const P &p);

/*
 * End Savranraskii Danila
*/

#endif
