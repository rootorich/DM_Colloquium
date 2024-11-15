#include "test_Z.h"

/*
  Written by ?? & Muchnik Maria
*/

bool TEST_F_TRANS_Z_N() {
  Z z;
  z.digits = {1};
  z.sign = false;

  N n = TRANS_Z_N(z);

  if (z == n) {
    return 1;
  } else {
    return 0;
  }
}

bool TEST_F_POZ_Z_D() {
  Z z;
  z.digits = {1};
  z.sign = 0;

  bool t1 = POZ_Z_D(z) == 1;

  z.sign = 1;
  bool t2 = POZ_Z_D(z) == 2;

  z.digits[0] = 0;
  bool t3 = POZ_Z_D(z) == 0;

  if (t1 && t2 && t3) {
    return 1;
  } else {
    return 0;
  }
}

bool TEST_F_ABS_Z_Z() {
    // test 1
    Z val1("-23712");
    Z res1("23712");
    if (ABS_Z_Z(val1) != res1)
        return false;

    // test 2
    Z val2("385");
    Z res2("385");
    if (ABS_Z_Z(val2) != res2)
        return false;

    // test 3
    Z val3("-0");
    Z res3("0");
    if (ABS_Z_Z(val3) != res3)
        return false;

    return true;
}

bool TEST_F_MUL_ZM_Z() {
    // test 1
    Z val1("42");
    Z res1("-42");
    if (-val1 != res1)
        return false;

    // test 2
    Z val2("-10");
    Z res2("10");
    if (-val2 != res2)
        return false;

    // test 3
    Z val3("0");
    Z res3("0");
    if (-val3 != res3)
        return false;

    return true;
}

bool TEST_F_TRANS_N_Z() {
    // test 1
    N val1("23712");
    Z res1("23712");
    if (TRANS_N_Z(val1) != res1)
        return false;

    // test 2
    N val2("0");
    Z res2("0");
    if (TRANS_N_Z(val2) != res2)
        return false;

    return true;
}

bool TEST_F_ADD_ZZ_Z() {
    // test 1
    Z val1_1("-42");
    Z val1_2("11");
    Z res1("-31");
    if (val1_1 + val1_2 != res1)
        return false;

    // test 2
    Z val2_1("-10");
    Z val2_2("10");
    Z res2("0");
    if (val2_1 + val2_2 != res2)
        return false;

    // test 3
    Z val3_1("0");
    Z val3_2("2153");
    Z res3("2153");
    if (val3_1 + val3_2 != res3)
        return false;

    return true;
}

bool TEST_F_SUB_ZZ_Z() {
    // test 1
    Z val1_1("-42");
    Z val1_2("11");
    Z res1("-53");
    if (val1_1 - val1_2 != res1)
        return false;

    // test 2
    Z val2_1("-10");
    Z val2_2("-10");
    Z res2("0");
    if (val2_1 - val2_2 != res2)
        return false;

    // test 3
    Z val3_1("0");
    Z val3_2("2153");
    Z res3("-2153");
    if (val3_1 - val3_2 != res3)
        return false;

    return true;
}

bool TEST_F_MUL_ZZ_Z() {
    // test 1
    Z val1_1("-42");
    Z val1_2("11");
    Z res1("-462");
    if (val1_1 * val1_2 != res1)
        return false;

    // test 2
    Z val2_1("-10");
    Z val2_2("-66");
    Z res2("660");
    if (val2_1 * val2_2 != res2)
        return false;

    // test 3
    Z val3_1("0");
    Z val3_2("2153");
    Z res3("0");
    if (val3_1 * val3_2 != res3)
        return false;

    return true;
}

bool TEST_F_DIV_ZZ_Z() {
    // test 1
    Z val1_1("-42");
    Z val1_2("11");
    Z res1("-3");
    if (val1_1 / val1_2 != res1)
        return false;

    // test 2
    Z val2_1("-10");
    Z val2_2("10");
    Z res2("-1");
    if (val2_1 / val2_2 != res2)
        return false;

    // test 3
    Z val3_1("0");
    Z val3_2("2153");
    Z res3("0");
    if (val3_1 / val3_2 != res3)
        return false;

    return true;
}

bool TEST_F_MOD_ZZ_Z() {
    // test 1
    Z val1_1("-42");
    Z val1_2("11");
    Z res1("2");
    if (val1_1 % val1_2 != res1)
        return false;

    // test 2
    Z val2_1("-10");
    Z val2_2("10");
    Z res2("0");
    if (val2_1 % val2_2 != res2)
        return false;

    // test 3
    Z val3_1("2153");
    Z val3_2("2157");
    Z res3("2153");
    if (val3_1 % val3_2 != res3)
        return false;

    return true;
}

void ALL_TEST_Z() {
    bool pass = true;
    if (!TEST_F_TRANS_Z_N()) {
        std::cout << "n = z does't work ;-;" << std::endl;
        pass = false;
    }
    if (!TEST_F_POZ_Z_D()) {
        std::cout << "Check sign does't work ;-;" << std::endl;
        pass = false;
    }
    if (!TEST_F_ABS_Z_Z()) {
        puts("ABS_Z_Z doesn't work ;-;");
        pass = false;
    }
    if (!TEST_F_MUL_ZM_Z()) {
        puts("MUL_ZM_Z doesn't work ;-;");
        pass = false;
    }
    if (!TEST_F_TRANS_Z_N()) {
        puts("TRANS_Z_N doesn't work ;-;");
        pass = false;
    }
    if (!TEST_F_ADD_ZZ_Z()) {
        puts("ADD_ZZ_Z doesn't work ;-;");
        pass = false;
    }
    if (!TEST_F_SUB_ZZ_Z()) {
        puts("SUB_ZZ_Z doesn't work ;-;");
        pass = false;
    }
    if (!TEST_F_MUL_ZZ_Z()) {
        puts("MUL_ZZ_Z doesn't work ;-;");
        pass = false;
    }
    if (!TEST_F_DIV_ZZ_Z()) {
        puts("DIV_ZZ_Z doesn't work ;-;");
        pass = false;
    }
    if (!TEST_F_MOD_ZZ_Z()) {
        puts("MOD_ZZ_Z doesn't work ;-;");
        pass = false;
    }

    if (pass) {
        puts("All tests for Z passed!!");
    }
}