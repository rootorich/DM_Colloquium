#include "N.h"

/*
 * Efimova
 * N-2
*/
bool operator==(const N& num, int digit) {
  return num.digits.size() == 1 && num.digits[0] == digit;
}

bool operator==(int digit, const N& num) {
  return num == digit;
}

bool operator!=(const N& num, int digit) {
  return !(num == digit);
}

bool operator!=(int digit, const N& num) {
  return !(num == digit);
}

bool NZER_N_B(const N& num) {
  return num != 0;
}

/*
 * Efimova
 * N-6
*/

N operator*(const N& num, const uint8_t digit){
    N result;
    uint8_t carry = 0;
    for (size_t i = 0; i < num.digits.size(); ++i){
        int product = (num.digits[i] * digit)+carry;
        result.digits.emplace_back(product%10);
        carry = product / 10;
    }

    if (carry > 0) {
        result.digits.emplace_back(carry);
    }
    return result;
}

N operator*(const uint8_t digit, const N& num){
    return num*digit;
}

N MUL_ND_N(const N& num, const uint8_t digit){
    return num*digit;
}


/*
 * Savranraskii Danila
 * N-1
*/
bool operator==(const N &n1, const N &n2) {
  return n1.digits == n2.digits;
}

bool operator<(const N &n1, const N &n2) {
  if (n1.digits.size() > n2.digits.size()) {
    return false;
  }

  if (n1.digits.size() < n2.digits.size()) {
    return true;
  }

  size_t i = n1.digits.size() - 1;
  while (true) {
    if (n1.digits[i] > n2.digits[i]) {
      return false;
    }
    if (n1.digits[i] < n2.digits[i]) {
      return true;
    }

    if (i == 0) {
      break;
    }

    --i;
  }

  return false;
}

uint8_t COM_NN_D(const N &n1, const N &n2) {
  if (n1 < n2) {
    return 1;
  }
  if (n2 < n1) {
    return 2;
  }
  return 0;
}


