#include "N.h"

/*
 * Efimova
 * N-2
*/
bool operator==(const N& num, uint8_t digit) {
  return num.digits.size() == 1 && num.digits[0] == digit;
}

bool operator==(uint8_t digit, const N& num) {
  return num == digit;
}

bool operator!=(const N& num, uint8_t digit) {
  return !(num == digit);
}

bool operator!=(uint8_t digit, const N& num) {
  return !(num == digit);
}

bool NZER_N_B(const N& num) {
  return num != 0;
}

/*
 * N-6
*/
N operator*(const N& num, const uint8_t digit){
  N result;
  uint8_t carry = 0;
  for (uint8_t numDigit : num.digits) {
    uint8_t product = (numDigit * digit) + carry;
    result.digits.emplace_back(product % 10);
    carry = product / 10;
  }

  if (carry > 0) {
    result.digits.emplace_back(carry);
  }
  return result;
}

N operator*(const uint8_t digit, const N& num){
  return num * digit;
}

N MUL_ND_N(const N& num, const uint8_t digit){
  return num * digit;
}

/*
 * End Efimova
*/


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

/*
 * End Savranraskii Danila
*/



/*
 * Masha
 * N-7
*/

N operator<<(N num, const uint8_t k) {
  if (num != 0) {
    num.digits.resize(num.digits.size() + k);
  }
  return num;
}

void operator<<=(N& num, const uint8_t k) {
  if (num != 0) {
    num.digits.resize(num.digits.size() + k);
  }
}

N MUL_Nk_N(const N& num, const uint8_t k) {
  return num << k;
}

/*
 * End Masha
*/