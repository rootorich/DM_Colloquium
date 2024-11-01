#include "N.h"

using namespace std::rel_ops;

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
 * N-14
*/


N operator/(const N& num1, const N& num2) {

    // if (num2 == 0) {
    //     throw std::invalid_argument("Division by zero");
    // }

    N n1 = num1;
    N res;

    if (n1 < num2) res.digits.push_back(0);
    
    while(n1 >= num2){
        N tmp = DIV_NN_Dk(n1, num2);
        res.digits.push_back(tmp.digits[0]);
        n1 = n1 - (num2*tmp);
    }

    return res;

}


N operator%(const N& num1, const N& num2) {
  return num1 - (num1/num2);
}

N LCM_NN_N(const N& num1, const N& num2){
  return MUL_NN_N(num1, num2)/GCF_NN_N(num1, num2);
}

/*
 * N-11
*/

N DIV_NN_N(const N& num1, const N& num2){
    return num1/num2;
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
* N-5
*/

N operator-(const N& n1, const N& n2) {
  if (n1 < n2) {
    return N{{0}};
  }

  N result;
  result.digits = n1.digits;
  int carry = 0;
  size_t i = 0;

  for (i = 0; i < n2.digits.size(); ++i) {
    if (n1.digits[i] - carry < n2.digits[i]) {
      result.digits[i] = 10 + n1.digits[i] - carry - n2.digits[i];
      carry = 1;
    }
    else {
      result.digits[i] = n1.digits[i] - carry - n2.digits[i];
      carry = 0;
    }
  }

  while (carry && i < n1.digits.size()) {
    if (n1.digits[i] == 0) {
      result.digits[i] = 10 + n1.digits[i] - carry;
      carry = 1;
    }
    else {
      result.digits[i] = n1.digits[i] - carry;
      carry = 0;
    }
    ++i;
  }

  while (result.digits.size() > 1 && result.digits.back() == 0) {
    result.digits.pop_back();
  }
  return result;
}

N SUB_NN_N(const N& n1, const N& n2) {
  if (n1 < n2) {
    return n2 - n1;
  }
  return n1 - n2;
}

/*
 * N-10
*/

// Не тестил пока сложения нет
N DIV_NN_Dk(const N& n1, const N& n2) {
  N a, b;
  if (n2 < n1) {
    a.digits = n1.digits;
    b.digits = n2.digits;
  }
  else {
    a.digits = n2.digits;
    b.digits = n1.digits;
  }
  int k = a.digits.size() - b.digits.size();
  uint8_t D;
  if (a.digits.back() > b.digits.back()) {
    D = a.digits.back() / b.digits.back();
    return N{{D}} << k;
  }
  k -= 1;
  b = b << k;
  N sum;
  sum.digits = b.digits;
  uint8_t i = 0;
  while (a > sum) {
    sum = sum + b;
    ++i;
  }
  return N{{i}} << k;
}

/*
 * End Savranraskii Danila
*/



/*
 * Masha
 * N-4
*/
N operator+(const N& n1, N n2) {
  N result = n1;
  if (COM_NN_D(n1, n2) == 1) {
    result = n2;
    n2 = n1;
  }
  uint8_t carry = 0;
  size_t i = 0;
  while (i < n2.digits.size() || carry) {
    if (i == result.digits.size()) {
      result.digits.emplace_back(carry);
      break;
    }
    uint8_t digit = result.digits[i] + carry;
    if (i < n2.digits.size()) {
      digit += n2.digits[i];
    }
    result.digits[i] = digit%10;
    carry = digit/10;
    ++i;
  }
  return result;
}

N& operator+=(N& n1, const N& n2) {
  n1 = n1 + n2;
  return n1;
}

N ADD_NN_N(const N& n1, const N& n2) {
  return n1 + n2;
}


/*
 * N-3
*/
const N& operator++(N& num) {
  N num_one{std::vector<uint8_t>{1}};
  num += num_one;
  return num;
}

const N ADD_1N_N(N num) {
  return ++num;
}

/*
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
