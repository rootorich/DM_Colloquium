// includes
#include <vector>
#include <stdint.h>

// for test. delete this
#include <iostream>

#ifndef DM_COLLOQUIUM_N_H
#define DM_COLLOQUIUM_N_H

struct test {
  std::vector<uint8_t> test;
};

test Test2(const test& t);

void Test();

#endif
