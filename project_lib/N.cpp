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
  if(digit == 0){
    return N{0};
  }

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
 * N-11
*/
N operator/(const N& num1, const N& num2) {
//  if (num2 == 0) {
//    throw std::invalid_argument("Division by zero");
//  }

  if (num1 < num2) {
    return N{0};
  }

  N n1 = num1;
  N res;

  while(n1 >= num2){
    N tmp = DIV_NN_Dk(n1, num2);
    n1 = n1 - (num2 * tmp);

    res += tmp;
  }

  return res;
}

N DIV_NN_N(const N& num1, const N& num2){
  return num1 / num2;
}

/*
 * N-12
*/
N operator%(const N& num1, const N& num2) {
  N res = num1 - (num2 * (num1 / num2));

  CLR_V_V(res);

  return res;
}

N MOD_NN_N(const N& num1, const N& num2){
  return num1 % num2;
}

/*
 * N-14
*/

N LCM_NN_N(const N& num1, const N& num2){
  return MUL_NN_N(num1, num2) / GCF_NN_N(num1, num2);
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
  N result;
  result.digits = n1.digits;
  int carry = 0;
  size_t i;

  for (i = 0; i < n2.digits.size(); ++i) {
    if (n1.digits[i] - carry < n2.digits[i]) {
      result.digits[i] = 10 + n1.digits[i] - carry - n2.digits[i];
      carry = 1;
    } else {
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

  CLR_V_V(result); // очистка незначащих нулей

  return result;
}

N SUB_NN_N(const N& n1, const N& n2) {
  return n1 - n2;
}

/*
 * N-10
*/
N DIV_NN_Dk(const N& n1, const N& n2) {
  size_t k = n1.digits.size() - n2.digits.size();

  N res = n2 << k;

  if (n1 < res) {
    k -= 1;
  }

  res = n2 << k;
  N sum = res;
  uint8_t i = 0;

  while (n1 >= sum) {
    sum = sum + res;
    ++i;
  }

  return N{i} << k;
}

/*
 * N-Dop-2.1 (str to N)
*/
N::N(const std::string& str) {
  for (auto ch = str.rbegin(); ch != str.rend(); ++ch) {
    digits.push_back(*ch - '0');
  }
}

/*
 * N-Dop-2.2 (vector to N)
*/
N::N(const std::vector<uint8_t>& vec) {
  digits = vec;
}

/*
 * N-Dop-2.3 (N to str)
*/
std::string N::to_str() {
  std::string str;
  for (auto digit = digits.rbegin(); digit != digits.rend(); ++digit) {
    str += char(*digit + '0');
  }
  return str;
}

/*
 * N-Dop-2.4 (digit to N)
*/
N::N(const uint8_t digit) {
  digits = {digit};
}

/*
 * End Savranraskii Danila
*/


/*
 * Masha
 * N-3
*/
void operator++(N& num) {
  N num_one{1};
  num += num_one;
}

N operator+(const N& n1, const uint8_t digit) {
  N n2 {digit};
  return n1 + n2;
}

N ADD_1N_N(const N& num) {
  return num + 1;
}

/*
 * N-4
*/
N operator+(const N& n1, const N& n2) {
  N result = n1;
  N min = n2;
  if (n1 < n2) {
    result = n2;
    min = n1;
  }
  uint8_t carry = 0;
  size_t i = 0;
  while (i < min.digits.size() || carry) {
    if (i == result.digits.size()) {
      result.digits.emplace_back(carry);
      break;
    }

    uint8_t digit = result.digits[i] + carry;

    if (i < min.digits.size()) {
      digit += min.digits[i];
    }

    result.digits[i] = digit%10;
    carry = digit/10;
    ++i;
  }

  return result;
}

void operator+=(N& n1, const N& n2) {
  n1 = n1 + n2;
}

N ADD_NN_N(const N& n1, const N& n2) {
  return n1 + n2;
}

/*
 * N-7
*/

N operator<<(const N& num, const uint8_t k) {
  N result = num;

  if (num != 0) {
    std::vector<uint8_t> zeros(k, 0);
    result.digits.insert(result.digits.begin(), zeros.begin(), zeros.end());
  }

  return result;
}

void operator<<=(N& num, const uint8_t k) {
  num = num << k;
}

N MUL_Nk_N(const N& num, const uint8_t k) {
  return num << k;
}

/*
 * N-8
*/
N operator*(const N& n1, const N& n2) {
  if (n2 == 0 || n1 == 0) {
    return (n2 == 0) ? n2 : n1;
  }

  N result;
  result.digits.emplace_back(0);

  for (size_t i = 0; i < n2.digits.size(); ++i) {
    result += (n1 * n2.digits[i]) << i; // скобки для более явного обозначения приоритета (хоть и * имеет выше приоритет, чем <<)
  }

  return result;
}

void operator*=(N& n1, const N& n2) {
  n1 = n1 * n2;
}


N MUL_NN_N(const N& n1, const N& n2) {
  return n1 * n2;
}

/*
 * N-9
*/
N SUB_NDN_N(const N& n1, const N& n2, const uint8_t d) {
  N n3 = d * n2;
//  if (n1 < n3)
//    throw std::invalid_argument("Subtrahend is bigger than number.");
  return n1 - n3;
}


/*
 * End Masha
*/


/*
 * Kate
 * N-13
*/
N GCF_NN_N(const N& n1, const N& n2) {
  N t1 = n1;
  N t2 = n2;

  while (t2 != 0) {
    if (t1 < t2) {
      std::swap(t1, t2);
    }
    t1 = t1 % t2;
  }

  return t1;
}

/*
 * N-Dop-1
*/
void CLR_V_V(N& num) {
  while (num.digits.size() > 1 && num.digits.back() == 0) {
    num.digits.pop_back();
  }
}

/*
 * End Kate
*/

