#include "Q.h"

#ifndef DM_COLLOQUIUM_PROJECT_LIB_P_H_
#define DM_COLLOQUIUM_PROJECT_LIB_P_H_

struct P {
  std::vector<Q> a;

  P() = default;
  explicit P(uint8_t digit);
};

/*
 * Efimova
 * P-1
*/
P operator+(const P& p1, const P& p2);
void operator+=(P& p1, const P& p2);
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
P operator<<(const P &p, const size_t k);
P MUL_Pxk_P(const P &p, const size_t k);

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


/*
 * Efimova
 * P-8
*/
P operator*(const P& p1, const P& p2);
P operator*(const P& p1, const uint8_t digit);

P MUL_PP_P(const P& p1, const P& p2);

/*
 * End Efimova
*/


/*
 * Kate
 * P-9
*/
P operator/(const P& p1, const P& p2);

P DIV_PP_P(const P& p1, const P& p2);

/*
 * P-10
*/
P operator%(const P& p1, const P& p2);

P MOD_PP_P(const P& p1, const P& p2);

/*
 * End Kate
*/


/*
 * Masha
 * P-11
*/
P GCF_PP_P(const P& p1, const P& p2);

/*
 P-12
*/
P DER_P_P(const P& p);

/*
 * End Masha
*/



/*
 * P-Dop-1.1
*/
bool operator<(const P& p1, const P& p2);

/*
 * P-Dop-1.2
*/
bool operator==(const P& p1, const P& p2);

/*
 * P-Dop-1.3
*/
bool operator==(const P& p, const uint8_t digit);

#endif
