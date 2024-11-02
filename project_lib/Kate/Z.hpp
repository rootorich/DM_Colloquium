#include "N.h"

struct Z : public N {
  bool sign;

  Z operator-() const;
};

Z ABS_Z_Z(const Z& z);

N TRANS_Z_N(const Z&z);