#include "P.h"

using namespace std::rel_ops;


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

void operator+=(P& p1, const P& p2) {
  p1 = p1 + p2;
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

P operator*(const P& p, const uint8_t digit) {
  return p * Q(digit);
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
P operator<<(const P &p, const uint32_t k) {
  P result = p;

  Q zero = Q(0);
  result.a.insert(result.a.begin(), k, zero);

  return result;
}

P MUL_Pxk_P(const P &p, const uint32_t k) {
  return p << k;
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
  return Q(TRANS_N_Z(GCF), LCM);
}

/*
 * End Savranraskii Danila
*/


/*
 * Efimova
 * P-8
*/
P operator*(const P& p1, const P& p2){
  P product;
  product.a.emplace_back(0);

  if((p1.a.size() == 1 && p1.a[0].z == 0 )||
    (p2.a.size() == 1 && p2.a[0].z == 0 )){
    return product;
  }

  for (size_t i = 0; i < p2.a.size(); ++i) {
    if(p2.a[i].z != 0){
      product += (p1 *p2.a[i]) << i;
    }
  }

  return product;
}

P MUL_PP_P(const P& p1, const P& p2) {
  return p1 * p2;
}

/*
 * End Efimova
*/


/*
 * Masha
 * P-11
*/
P GCF_PP_P(const P& p1, const P& p2) {
  P t1 = p1;
  P t2 = p2;

  while (t1 != 0) {
    if (t1 < t2) {
      std::swap(t1, t2);
    }
    t1 = t1 % t2;
  }

  return t2;
}

/*
 P-12
*/
P DER_P_P(const P& p) {
  P res;

  for (uint8_t i = 1; i < p.a.size(); i++) {
    res.a.emplace_back(p.a[i] * i);
  }

  return res;
}

/*
 * End Masha
*/


/*
 * P-Dop-1.1
*/
bool operator<(const P& p1, const P& p2) {
  if (DEG_P_N(p1) < DEG_P_N(p2)) {
    return true;
  } else if (DEG_P_N(p1) > DEG_P_N(p2)) {
    return false;
  } else {
    return (p1.a.back() < p2.a.back());
  }
}

/*
 * P-Dop-1.2
*/
bool operator==(const P& p1, const P& p2) {
  if (DEG_P_N(p1) == DEG_P_N(p2)) {
    size_t i = p1.a.size() - 1;

    while (true) {
      if (p1.a[i] != p2.a[i]) {
        return false;
      }
      if (i == 0) {
        break;
      }

      --i;
    }

    return true;
  } else {
    return false;
  }
}

bool operator==(const P& p, const uint8_t digit) {
  if (DEG_P_N(p) == 0) {
    if (p.a.back() == digit) {
      return true;
    }
  }

  return false;
}

