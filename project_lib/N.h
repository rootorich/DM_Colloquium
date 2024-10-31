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
bool operator==(const N& num, int digit);
bool operator==(int digit, const N& num);
bool operator!=(const N& num, int digit);
bool operator!=(int digit, const N& num);
bool NZER_N_B(const N& num);

/*
 * Savranraskii Danila
 * N-1
*/
bool operator==(const N& n1, const N& n2);
bool operator<(const N& n1, const N& n2);
uint8_t COM_NN_D(const N& n1, const N& n2);

/*
 * Efimova
 * N-6
*/
N operator*(const uint8_t digit, const N& num);
N operator*(const N& num, const uint8_t digit);
N MUL_ND_N(const N& num, const uint8_t digit);


#endif
