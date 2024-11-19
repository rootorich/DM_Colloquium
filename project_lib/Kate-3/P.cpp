#include "P.h"
// Kate
// P-9
P operator/(const P& p1, const P& p2) {
  P quotient;
  P remainder = p1;

  quotient.a.resize(p1.a.size() - p2.a.size() + 1);

  for (size_t i = p1.a.size() - 1; i >= (p2.a.size()) - 1; --i) {
    if (remainder.a.size() <= i) continue;
    Q new_q = remainder.a[i] / p2.a.back();
    size_t shift = i - p2.a.size() + 1;
    quotient.a[shift] = new_q;
    for (size_t j = 0; j < p2.a.size(); ++j) {
      remainder.a[shift + j] = remainder.a[shift + j] - new_q * p2.a[j];
    }
  }

  return quotient;
}

// P-10
P operator%(const P& p1, const P& p2) { return p1 - ((p1 / p2) * p2); }

P DIV_PP_P(const P& p1, const P& p2) { return p1 / p2; }

P MOD_PP_P(const P& p1, const P& p2) { return p1 % p2; }
// End Kate