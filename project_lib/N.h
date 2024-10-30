#include <vector>
#include <cstdint>
#include <utility>
#include <iostream>
#ifndef DM_COLLOQUIUM_N_H
#define DM_COLLOQUIUM_N_H

struct N {
    std::vector <uint8_t> digits;
};

bool operator==(const N& num, int zero);
bool operator==(int zero, const N& num);
bool operator!=(const N& num, int zero);
bool operator!=(int zero, const N& num);

#endif
