#include "N.h"

N operator*(const N& num, const uint8_t digit){
    N result;
    result.digits.resize(num.digits.size() + 1);
    int carry = 0;
    for (size_t i = 0; i < num.digits.size(); ++i){
        int product = (num.digits[i] * digit)+carry;
        result.digits[i] = product % 10;
        carry = product / 10;
    }

    if (carry > 0) {
        result.digits[num.digits.size()] = carry;
    }
    else{
        result.digits.resize(num.digits.size());
    }
    return result;
}

N operator*(const uint8_t digit, const N& num){
    N result;
    result.digits.resize(num.digits.size() + 1);
    int carry = 0;
    for (size_t i = 0; i < num.digits.size(); ++i){
        int product = (num.digits[i] * digit)+carry;
        result.digits[i] = product % 10;
        carry = product / 10;
    }

    if (carry > 0) {
        result.digits[num.digits.size()] = carry;
    }
    else{
        result.digits.resize(num.digits.size());
    }
    return result;
}



N MUL_ND_N(const N& num, const uint8_t digit){
    return num*digit;
}
