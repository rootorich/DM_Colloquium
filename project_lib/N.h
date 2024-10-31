// includes
#include <vector>
#include <cstdint>
#ifndef DM_COLLOQUIUM_N_H
#define DM_COLLOQUIUM_N_H

struct test {
  std::vector<uint8_t> test;
};

N operator*(const uint8_t digit, const N& num);
N operator*(const N& num, const uint8_t digit);
N MUL_ND_N(const N& num, const uint8_t digit);

#endif
