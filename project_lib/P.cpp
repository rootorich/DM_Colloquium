#include "P.h"

/*
 * Efimova
 * P-1
*/
P operator+(const P& p1, const P& p2) {
  P result = (p1.a.size() >= p2.a.size()) ? p1 : p2;
  P min = (p1.a.size() < p2.a.size()) ? p1: p2;

  for (size_t i = 0; i < min.a.size(); ++i) {
    result.a[i] = result.a[i] + min.a[i];
  }

  return result;
}

P ADD_PP_P(const P& p1, const P& p2) {
  return p1 + p2;
}

/*
 * P-2
*/
P operator-(const P& p1) {
  P p = p1;

  for (auto & a : p.a){
    a = -a;
  }

  return p;
}

P operator-(const P& p1, const P& p2) {
  return p1 + (-p2);
}

P SUB_PP_P(const P& p1, const P& p2) {
  return p1 - p2;
}

/*
 * P-3
*/
P operator*(const P& p, const Q& q) {
  P result;

  for (const auto & a : p.a){
    result.a.push_back(a * q);
  }

  return result;
}

P MUL_PQ_P(const P& p, const Q& q) {
  return p * q;
}

/*
 * End Efimova
*/


/*
* Savranraskii Danila
* P-4
*/
P MUL_Pxk_P(const P &p, uint32_t k) {
  P result = p;

  Q zero = {Z("0"), N("1")};
  result.a.insert(result.a.begin(), k, zero);

  return result;
}

/*
 * P-5
*/
Q LED_P_Q(const P &p) {
  return p.a.back();
}

/*
 * P-6
*/
N DEG_P_N(const P &p) {
  return N(p.a.size() - 1);
}

/*
 * P-7
*/
Q FAC_P_Q(const P &p) {
  N GCF = N(1); // НОД
  N LCM = N(1); // НОК

  size_t i = 0;
  // Находим первую значащую цифру и приписываем ей НОК и НОД
  while (i < p.a.size()) {
    if (p.a[i].z != 0) {
      GCF = p.a[i].z;
      LCM = p.a[i].n;
      ++i;
      break;
    }
    ++i;
  }
  // Учитываем оставшиеся числа
  while (i < p.a.size()) {
    if (p.a[i].z != 0) {
      GCF = GCF_NN_N(GCF, p.a[i].z); // НОД всех числителей
      LCM = LCM_NN_N(LCM, p.a[i].n); // НОК всех знаменателей
    }
    ++i;
  }
  return Q{TRANS_N_Z(GCF), LCM};
}

/*
 * End Savranraskii Danila
*/