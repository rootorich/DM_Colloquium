#include "test_N.h"


bool TEST_OP_EQU_N_DIGIT() {
  N val1;
  int digit1;

  // test 1
  val1.digits = {0, 0, 0, 0, 1};
  digit1 = 0;
  if (val1 == digit1) {
    return false;
  }

  // test 2
  val1.digits = {5};
  digit1 = 0;
  if (val1 == digit1) {
    return false;
  }

  // test 3
  val1.digits = {0};
  digit1 = 0;
  if (!(val1 == digit1)) {
    return false;
  }

  return true;
}

bool TEST_OP_EQU_DIGIT_N() {
  return false;
}

bool TEST_OP_NEQU_N_DIGIT() {
  return false;
}

bool TEST_OP_NEQU_DIGIT_N() {
  return false;
}

bool TEST_F_NZER_N_B() {
  return false;
}



bool TEST_OP_EQU_N_N() {
  return false;
}

bool TEST_OP_LT_N_N() {
  return false;
}

bool TEST_F_COM_NN_D() {
  return false;
}





void ALL_TEST_N() {

  if (TEST_OP_EQU_N_DIGIT()) {
    std::cout << "N == DIGIT is work";
  } else {
    std::cout << "N == DIGIT does't work";
  }
  std::cout << "\n";
  // ...
}