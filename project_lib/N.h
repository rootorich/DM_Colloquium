#include <vector>
#include <cstdint>
#include <utility>
#include <stdexcept>

#ifndef DM_COLLOQUIUM_N_H
#define DM_COLLOQUIUM_N_H

typedef struct N {
  std::vector <uint8_t> digits;
} N;

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
 * N-6
*/
N operator*(const uint8_t digit, const N& num);
N operator*(const N& num, const uint8_t digit);
N MUL_ND_N(const N& num, const uint8_t digit);

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
 * End Savranraskii Danila
*/



/*
 * Masha
 * N-4
*/
const N operator+(const N& n1, const N& n2);
N& operator+=(N& n1, const N& n2);
const N ADD_NN_N(const N& n1, const N& n2);

/*
 * N-3
*/
const N& operator++(N& num);
const N& ADD_1N_N(N& num);

/*
 * N-7
*/
const N operator<<(const N& num, const uint8_t k);
N& operator<<=(N& num, const uint8_t k);
const N MUL_Nk_N(const N& num, const uint8_t k);

/*
 *N-8
*/
const N operator*(const N& n1, const N& n2);
N& operator*=(N& n1, const N& n2);
const N MUL_NN_N(const N& n1, const N& n2);

/*
 * N-9
*/
const N SUB_NDN_N(const N& n1, const uint8_t d, const N& n2);

/*
 * End Masha
*/

#endif
