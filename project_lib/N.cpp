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
 * N-4
*/
const N operator+(const N n1, const N n2) {
    N result, min;
    if (COM_NN_D(n1, n2) == 2) {
        result = n1;
        min = n2;
    } else {
        result = n2;
        min = n1;
    }
    uint8_t carry = 0;
    size_t i = 0;
    while (i < min.digits.size()) {
        result.digits[i] = (n1.digits[i] + n2.digits[i] + carry)%10; 
        carry = (n1.digits[i] + n2.digits[i] + carry)/10;
        i++;
    } 
    if (i == result.digits.size() && carry)
        result.digits.emplace_back(0);
    result.digits[i] += carry;
    return result;
}

void operator+=(N& n1, const N n2) {
    n1 = n1 + n2;
}

const N ADD_NN_N(const N n1, const N n2) {
    return n1 + n2;
}


/*
 * N-3
*/
const N operator++(N& num, int) {
    N old_num;
    old_num.digits = num.digits;
    N num_one{std::vector<uint8_t>{1}};
    num += num_one; 
    return old_num;
}

const N ADD_1N_N (N num) {
    num++;
    return num;
}


/*
 * N-7
*/
N operator<<(N num, const uint8_t k) {
  if (num != 0) {
    std::vector<uint8_t> zeros(k, 0);
    num.digits.insert(num.digits.begin(), zeros.begin(), zeros.end());
  }
  return num;
}

void operator<<=(N& num, const uint8_t k) {
  num = num << k;
}

N MUL_Nk_N(const N num, const uint8_t k) {
  return num << k;
}

/*
 * End Masha
*/