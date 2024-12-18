#include <vector>
#include <cstdint>
#include <utility>
#include <string>
#include <algorithm>

#ifndef DM_COLLOQUIUM_N_H
#define DM_COLLOQUIUM_N_H

struct N {
  std::vector <uint8_t> digits;

  N() = default;
  explicit N(uint8_t digit);
  explicit N(const std::string& str);
  explicit N(const std::vector<uint8_t>& vec);

  std::string to_str();
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
N operator*(uint8_t digit, const N& num);
N operator*(const N& num, uint8_t digit);
N MUL_ND_N(const N& num, uint8_t digit);

/*
 * N-11
*/
N operator/(const N& num1, const N& num2);
N DIV_NN_N(const N& num1, const N& num2);

/*
 * N-12
*/
N operator%(const N& num1, const N& num2);
N MOD_NN_N(const N& num1, const N& num2);

/*
 * N-14
*/
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
 * N-3
*/
void operator++(N& num);
N operator+(const N& n1, uint8_t digit);
N ADD_1N_N(const N& num);

/*
 * N-4
*/
N operator+(const N& n1, const N& n2);
void operator+=(N& n1, const N& n2);
N ADD_NN_N(const N& n1, const N& n2);

/*
 * N-7
*/
N MUL_Nk_N(const N& num, uint8_t k);
N operator<<(const N& num, uint8_t k);
void operator<<=(N& num, uint8_t k);

/*
 *N-8
*/
N operator*(const N& n1, const N& n2);
void operator*=(N& n1, const N& n2);
N MUL_NN_N(const N& n1, const N& n2);

/*
 * N-9
*/
N SUB_NDN_N(const N& n1, const N& n2, uint8_t d);

/*
 * End Masha
*/


/*
 * Kate
 * N-13
*/
N GCF_NN_N(const N& n1, const N& n2);
void CLR_V_V(N& num);
/*
 * End Kate
*/

#endif

