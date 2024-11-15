#include <iostream>

#include "test_P.h"

/* written by Masha */

bool TEST_ADD_PP_P() {
    // test 1
    P val1_1("13x^100 + 2/5x^12 - x + 1/8");
    P val1_2("23/5x^22 + 13x");
    P res1("13x^100 + 23/5x^22 + 2/5x^12 + 12x + 1/8");
    if (val1_1 + val1_2 != res1)
        return false;

    // test 2
    P val2_1("-32000x");
    P val2_2("32000x");
    P res2("0");
    if (val2_1 + val2_2 != res2)
        return false;

    // test 3
    P val3_1("-x - 1111111");
    P val3_2("1111111");
    P res3("-x");
    if (val3_1 + val3_2 != res3)
        return false;

    return true;
}

bool TEST_SUB_PP_P() {
    P val1_1("13x^100 + 2/5x^12 - x + 1/8");
    P val1_2("23/5x^22 + 13x");
    P res1("13x^100 - 23/5x^22 + 2/5x^12 - 14x + 1/8");
    if (val1_1 - val1_2 != res1)
        return false;

    // test 2
    P val2_1("-32000x");
    P val2_2("32000x");
    P res2("-64000x");
    if (val2_1 - val2_2 != res2)
        return false;

    // test 3
    P val3_1("-x");
    P val3_2("0");
    P res3("-x");
    if (val3_1 - val3_2 != res3)
        return false;

    return true;
}

bool TEST_MUL_PQ_P() {
    // test 1
    P val1_1("-32000x");
    Q val1_2("32000", "1");
    P res1("-1024000000x");
    if (val1_1 * val1_2 != res1)
        return false;

    // test 2
    P val2_1("-x");
    Q val2_2("0", "1");
    P res2("0");
    if (val2_1 * val2_2 != res2)
        return false;

    // test 3
    P val3_1("13x^100 + 2/5x^12 - x + 1/8");
    Q val3_2("1", "2");
    P res3("13/2x^100 + 1/5x^12 - 1/2x + 1/16");
    if (val3_1 * val3_2 != res3)
        return false;

    return true;
}

bool TEST_MUL_Pxk_P() {
    // test 1
    P val1_1("-32000x");
    uint8_t val1_2 = 16;
    P res1("-32000x^17");
    if (MUL_Pxk_P(val1_1, val1_2) != res1)
        return false;

    // test 2
    P val2_1("-x^12 + 13x^4 - x - 1");
    uint8_t val2_2 = 4;
    P res2("-x^16 + 13x^8 - x^5 - x^4");
    if (MUL_Pxk_P(val2_1, val2_2) != res2)
        return false;

    // test 3
    P val3_1("13x^100 + 2/5x^12 - x + 1/8");
    uint8_t val3_2 = 0;
    P res3("13x^100 + 2/5x^12 - x + 1/8");
    if (MUL_Pxk_P(val3_1, val3_2) != res3)
        return false;

    return true;
}

bool TEST_LED_P_Q() {
    // test 1
    P val1_1("-32000x + 12 + 24x^12");
    Q res1("24", "1");
    if (LED_P_Q(val1_1) != res1)
        return false;

    // test 2
    P val2_1("0");
    Q res2("0", "1");
    if (LED_P_Q(val2_1) != res2)
        return false;

    // test 3
    P val3_1("13/124x^101 + 2/5x^12 - x + 1/8");
    Q res3("13", "124");
    if (LED_P_Q(val3_1) != res3)
        return false;

    return true;
}

bool TEST_DEG_P_N() {
    // test 1
    P val1_1("-32000x + 12 + 24x^12");
    N res1("12");
    if (DEG_P_N(val1_1) != res1)
        return false;

    // test 2
    P val2_1("-1");
    N res2("0");
    if (DEG_P_N(val2_1) != res2)
        return false;

    // test 3
    P val3_1("13x^101 + 2/5x^12 - x + 1/8");
    N res3("101");
    if (DEG_P_N(val3_1) != res3)
        return false;

    return true;
}

bool TEST_FAC_P_Q() {
    // test 1
    P val1_1("-32000x + 24/49x^12 + 12/7");
    Q res1("4", "49");
    if (FAC_P_Q(val1_1) != res1)
       return false;

    // test 2
    P val2_1("-x + 17");
    Q res2("1", "1");
    if (FAC_P_Q(val2_1) != res2)
        return false;

    // test 3
    P val3_1("13x^101 + 2/5x^12 - x + 1/8");
    Q res3("1", "40");
    if (FAC_P_Q(val3_1) != res3)
        return false;

    return true;
}

bool TEST_MUL_PP_P() {
    // test 1
    P val1_1("-32000x");
    P val1_2("32000x");
    P res1("-1024000000x^2");
    if (val1_1 * val1_2 != res1)
        return false;

    // test 2
    P val2_1("-x");
    P val2_2("0");
    P res2("0");
    if (val2_1 * val2_2 != res2)
        return false;

    // test 3
    P val3_1("13x^100 + 2/5x^12 - x + 1/8");
    P val3_2("23/5x^22 + 13x");
    P res3("299/5x^122 + 169x^101 + 46/25x^34 - 23/5x^23 + 23/40x^22 + 26/5x^13 - 13x^2 + 13/8x");
    if (val3_1 * val3_2 != res3)
        return false;

    return true;
}

bool TEST_DIV_PP_P() {
    // test 1
    P val1_1("-32000x");
    P val1_2("32000x");
    P res1("-1");
    if (val1_1 / val1_2 != res1)
        return false;

    // test 2
    P val2_1("-x^2 + x - 1");
    P val2_2("- x - 1");
    P res2("-x + 2");
    if (val2_1 / val2_2 != res2)
        return false;

    // test 3
    P val3_1("13x^100 + 2/5x^12 - x + 1/8");
    P val3_2("23/5x^22 + 13x");
    P res3("65/23x^78 - 4225/529x^27 + 274625/12176x^36 - 17850625/279841x^15");
    if (val3_1 / val3_2 != res3)
        return false;

    return true;
}
 
bool TEST_MOD_PP_P() {
    // test 1
    P val1_1("-32000x");
    P val1_2("32000x");
    P res1("0");
    if (val1_1 % val1_2 != res1)
        return false;

    // test 2
    P val2_1("-x^2 + x - 1");
    P val2_2("- x - 1");
    P res2("-3");
    if (val2_1 % val2_2 != res2)
        return false;

    // test 3
    P val3_1("13x^100 + 2/5x^12 - x + 1/8");
    P val3_2("23/5x^22 + 13x");
    P res3("232058125/279841x^16 + 2/5x^12 - x + 1/8");
    if (val3_1 % val3_2 != res3)
        return false;

    return true;
}

bool TEST_GCF_PP_P() {
    // test 1
    P val1_1("-32000x");
    P val1_2("32000x");
    P res1("32000x");
    if (GCF_PP_P(val1_1, val1_2) != res1)
        return false;

    // test 2
    P val2_1("-x^2 + 2x - 1");
    P val2_2("- 23x - 23");
    P res2("x - 1");
    if (GCF_PP_P(val2_1, val2_2) != res2)
        return false;

    // test 3
    P val3_1("13x^100 + 2/5x^12 - x + 1/8");
    P val3_2("23/5x^22 + 13x");
    P res3("1");
    if (GCF_PP_P(val3_1, val3_2) != res3)
        return false;
    return true;
}

bool TEST_DER_P_P() {
    // test 1
    P val1_1("-32000x");
    P res1("-32000");
    if (DER_P_P(val1_1) != res1)
        return false;

    // test 2
    P val2_1("1");
    P res2("0");
    if (DER_P_P(val2_1) != res2)
        return false;

    // test 3
    P val3_1("13x^100 + 2/5x^12 - x + 1/8");
    P res3("1300x^99 + 24/5x^11 - 1");
    if (DER_P_P(val3_1) != res3)
        return false;
    return true;
}

bool TEST_NMR_P_P() {
    // test 1
    /*P val1_1("-32000x");
    P res1("32000x");
    if (NMR_PP_P(val1_1) != res1)
        return false;

    // test 2
    P val2_1("x^4 - 5x^3 - x^2 + 17x + 12");
    P res2("x^3 - 6x^2 + 5x + 12");
    if (NMR_PP_P(val2_1) != res2)
        return false;

    // test 3
    P val3_1("x^8");
    P res3("x");
    if (NMR_PP_P(val3_1) != res3)
        return false;*/

    return true;
}

void ALL_TEST_P() {
    bool pass = true;
    if (!TEST_ADD_PP_P()) {
        puts("ADD_PP_P doesn't work т.т");
        pass = false;
    }
    if (!TEST_SUB_PP_P()){
        puts("SUb_PP_P doesn't work т.т");
        pass = false;
    }
    if (!TEST_MUL_PQ_P()) {
        puts("MUL_PQ_P doesn't work т.т");
        pass = false;
    }
    if (!TEST_MUL_Pxk_P()) {
        puts("MUL_Pxk_P doesn't work т.т");
        pass = false;
    }
    if (!TEST_LED_P_Q()) {
        puts("LED_P_Q doesn't work т.т");
        pass = false;
    }
    if (!TEST_DEG_P_N()) {
        puts("DEG_P_N doesn't work т.т");
        pass = false;
    }
    if (!TEST_FAC_P_Q()) {
        puts("FAC_P_Q doesn't work т.т");
        pass = false;
    }
    if (!TEST_MUL_PP_P()) {
        puts("MUL_PP_P doesn't work т.т");
        pass = false;
    }
    if (!TEST_DIV_PP_P()) {
        puts("DIV_PP_P doesn't work т.т");
        pass = false;
    }
    if (!TEST_MOD_PP_P()) {
        puts("MOD_PP_P doesn't work т.т");
        pass = false;
    }
    if (!TEST_GCF_PP_P()) {
        puts("GCF_PP_P doesn't work т.т");
        pass = false;
    }
    if (!TEST_DER_P_P()) {
        puts("DER_PP_P doesn't work т.т");
        pass = false;
    }
    if (!TEST_NMR_P_P()) {
        puts("NMR_PP_P doesn't work т.т");
        pass = false;
    }

    if (pass)
        puts("All tests for P passed!!");
}