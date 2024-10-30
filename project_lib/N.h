// includes
#include <vector>
#include <stdint.h>

#ifndef DM_COLLOQUIUM_N_H
#define DM_COLLOQUIUM_N_H

struct N {
  std::vector<uint8_t> digits;
};

uint8_t COM_NN_D(const N &n1, const N &n2);

bool operator==(const N &n1, const N &n2);
bool operator<(const N &n1, const N &n2);

#endif
