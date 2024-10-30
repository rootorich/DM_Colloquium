#ifndef DM_COLLOQUIUM_N_H
#define DM_COLLOQUIUM_N_H

#include <vector>
#include <cstdint>

struct N {
  std::vector<uint8_t> digits;
};

uint8_t MUL_Nk_N(const N &n1, const N &n2);
N operator<<(N num, const uint8_t k);
void operator<<=(N& num, const uint8_t k);

#endif
