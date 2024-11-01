#include <vector>
#include <cstdint>
#include <utility>

#ifndef DM_COLLOQUIUM_N_H
#define DM_COLLOQUIUM_N_H

struct N {
  std::vector <uint8_t> digits;
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
 * N-7
*/
N MUL_Nk_N(const N& num, const uint8_t k);
N operator<<(N num, const uint8_t k);
void operator<<=(N& num, const uint8_t k);

/*
 * End Masha
*/

#endif

