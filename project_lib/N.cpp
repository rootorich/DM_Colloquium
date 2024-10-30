#include "N.h"

uint8_t COM_NN_D(const N &n1, const N &n2) {
  if (n1.digits.size() > n2.digits.size()) {
    return 2;
  }
  if (n1.digits.size() < n2.digits.size()) {
    return 1;
  }
  for (size_t i = n1.digits.size() - 1; i >= 0; i--) {
    if (n1.digits[i] > n2.digits[i]) {
      return 2;
    }
    if (n1.digits[i] < n2.digits[i]) {
      return 1;
    }
  }
  return 0;
}

bool operator==(const N &n1, const N &n2) { return COM_NN_D(n1, n2) == 0; }
bool operator<(const N &n1, const N &n2) { return COM_NN_D(n1, n2) == 1; }