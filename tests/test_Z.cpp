#include "test_Z.h"

bool TEST_F_TRANS_Z_N() {
  Z z;
  z.digits = {1};
  z.sign = false;

  N n = TRANS_Z_N(z);

  if (z == n) {
    return 1;
  } else {
    return 0;
  }
}

bool TEST_F_POZ_Z_D() {
  Z z;
  z.digits = {1};
  z.sign = 0;

  bool t1 = POZ_Z_D(z) == 1;

  z.sign = 1;
  bool t2 = POZ_Z_D(z) == 2;

  z.digits[0] = 0;
  bool t3 = POZ_Z_D(z) == 0;

  if (t1 && t2 && t3) {
    return 1;
  } else {
    return 0;
  }
}


void ALL_TEST_Z() {
  if (TEST_F_TRANS_Z_N()) {
    std::cout << "n = z is work";
  } else {
    std::cout << "n = z does't work";
  }
  std::cout << "\n";


  if (TEST_F_POZ_Z_D()) {
    std::cout << "Check sign is work";
  } else {
    std::cout << "Check sign does't work";
  }
  std::cout << "\n";

}