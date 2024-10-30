#include "N.h"

uint8_t COM_NN_D(const N &n1, const N &n2) {
  if (n1 < n2) {
    return 1; 
  }
  if (n2 < n1) {
    return 2;
  }
  return 0;
}

// Тут можно было использовать vec == vec, но пофиг
bool operator==(const N &n1, const N &n2) {   
  if (n1.digits.size() != n2.digits.size()) {
    return false;
  }
  for (size_t i = 0; i < n1.digits.size(); ++i) {
    if (n1.digits[i] != n2.digits[i]) {
      return false;
    }
  }
  return true;
}
bool operator<(const N &n1, const N &n2) { 
  if (n1.digits.size() > n2.digits.size()) {
    return false;
  }
  if (n1.digits.size() < n2.digits.size()) {
    return true;
  }
  for (size_t i = n1.digits.size() - 1; i >= 0; --i) {
    if (n1.digits[i] > n2.digits[i]) {
      return false;
    }
    if (n1.digits[i] < n2.digits[i]) {
      return true;
    }
  }
  return false;
}