#include <vector>
#include <cstdint>
#include <utility>

#ifndef DM_COLLOQUIUM_N_H
#define DM_COLLOQUIUM_N_H

struct N {
  std::vector <uint8_t> digits;

  N& operator*=(const N& n);
};

/*
 * Efimova
 * N-2
*/
bool operator==(const N& num, uint8_t digit);
bool operator==(uint8_t digit, const N& num);
bool operator!=(const N& num, uint8_t digit);
bool operator!=(uint8_t digit, const N& num);
bool NZER_N_B(const N& num);

/*
 *  N-6
*/
N operator*(const uint8_t digit, const N& num);
N operator*(const N& num, const uint8_t digit);
N MUL_ND_N(const N& num, const uint8_t digit);

/*
 * N-11
*/
N DIV_NN_N(const N& num1, const N& num2);

/*
 * N-14
*/
N operator%(const N& num1, const N& num2);
N operator/(const N& num1, const N& num2);
N LCM_NN_N(const N& num1, const N& num2);

/*
 * End Efimova
*/


/*
 * Savranraskii Danila
 * N-1
*/
bool operator==(const N& n1, const N& n2);
bool operator<(const N& n1, const N& n2);
uint8_t COM_NN_D(const N& n1, const N& n2);

/*
 * N-5
*/
N operator-(const N& n1, const N& n2);
N SUB_NN_N(const N& n1, const N& n2);

/*
 * N-10
*/
N DIV_NN_Dk(const N& n1, const N& n2);


/*
 * End Savranraskii Danila
*/


/*
 * Masha
 * N-4
*/
N operator+(const N& n1, N n2);
N& operator+=(N& n1, const N& n2);
N ADD_NN_N(const N& n1, const N& n2);

/*
 * N-3
*/
const N& operator++(N& num);
const N ADD_1N_N(N num);

/*
 * N-7
*/
N MUL_Nk_N(const N& num, const uint8_t k);
N operator<<(N num, const uint8_t k);
void operator<<=(N& num, const uint8_t k);

/*
 *N-8
*/
N operator*(const N& n1, const N& n2);
N MUL_NN_N(const N& n1, const N& n2);

/*
 * N-9
*/
N SUB_NDN_N(const N& n1, const uint8_t d, const N& n2);


/*
 * End Masha
*/


/*
 * Kate
 * N-13
*/
N GCF_NN_N(N& n1, N& n2);
void CLR_V_V(N& num);
/*
 * End Kate
*/

#endif

