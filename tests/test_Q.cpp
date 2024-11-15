#include "test_Q.h"

#include <iostream>

/* 
 * written by Masha 
*/

bool TEST_RED_Q_Q() {
    // test 1
    Q val1("-32000", "1");
    Q res1("-32000", "1");
    if (RED_Q_Q(val1) != res1)
        return false;

    // test 2
    Q val2("3200", "15");
    Q res2("640", "3");
    if (RED_Q_Q(val2) != res2)
        return false;

    // test 3
    Q val3("-32000", "32000");
    Q res3("-1", "1");
    if (RED_Q_Q(val3) != res3)
        return false;

    // test 4
    Q val4("-32000", "17");
    Q res4("-32000", "17");
    if (RED_Q_Q(val4) != res4)
        return false;
    
    return true;
}


bool TEST_INT_Q_B() {
    // test 1
    Q val1("-32000", "1");
    bool res1 = true;
    if (INT_Q_B(val1) != res1)
        return false;

    // test 2
    Q val2("640", "3");
    bool res2 = false;
    if (INT_Q_B(val2) != res2)
        return false;

    return true;
}

bool TEST_TRANS_Z_Q() {
    // test 1
    Z val1("-32000");
    Q res1("-32000", "1");
    if (TRANS_Z_Q(val1) != res1)
        return false;

    // test 2
    Z val2("640");
    Q res2("640", "1");
    if (TRANS_Z_Q(val2) != res2)
        return false;

    return true;
}

bool TEST_TRANS_Q_Z() {
    // test 1
    Z res1("-32000");
    Q val1("-32000", "1");
    if (TRANS_Q_Z(val1) != res1)
        return false;

    // test 2
    Z res2("640");
    Q val2("640", "1");
    if (TRANS_Q_Z(val2) != res2)
        return false;

    return true;
}

bool TEST_ADD_QQ_Q() {
    // test 1
    Q val1_1("-32000", "1");
    Q val1_2("10", "1");
    Q res1("-31990", "1");
    if (val1_1 + val1_2 != res1)
        return false;

    // test 2
    Q val2_1("-32000", "243");
    Q val2_2("-1240", "15");
    Q res2("-52088", "243");
    if (val2_1 + val2_2 != res2)
        return false;

    // test 3
    Q val3_1("-1111111", "10");
    Q val3_2("1111111", "10");
    Q res3("0", "1");
    if (val3_1 + val3_2 != res3)
        return false;

    return true;
}

bool TEST_SUB_QQ_Q() {
    // test 1
    Q val1_1("-32000", "1");
    Q val1_2("10", "1");
    Q res1("-32010", "1");
    if (val1_1 - val1_2 != res1)
        return false;

    // test 2
    Q val2_1("-32000", "243");
    Q val2_2("-1240", "15");
    Q res2("-11912", "243");
    if (val2_1 - val2_2 != res2)
        return false;

    // test 3
    Q val3_1("-1111111", "10");
    Q val3_2("1111111", "10");
    Q res3("-2222222", "10");
    if (val3_1 - val3_2 != res3)
        return false;

    return true;
}

bool TEST_MUL_QQ_Q() {
    // test 1
    Q val1_1("-32000", "1");
    Q val1_2("10", "1");
    Q res1("-320000", "1");
    if (val1_1 * val1_2 != res1)
        return false;

    // test 2
    Q val2_1("-32000", "243");
    Q val2_2("-1240", "15");
    Q res2("-7936000", "729");
    if (val2_1 * val2_2 != res2)
        return false;

    // test 3
    Q val3_1("-1", "124681274");
    Q val3_2("124681274", "1");
    Q res3("-1", "1");
    if (val3_1 * val3_2 != res3)
        return false;

    // test 4
    Q val4_1("0", "124681274");
    Q val4_2("124681274", "12412");
    Q res4("0", "1");
    if (val3_1 * val3_2 != res3)
        return false;

    return true;
}

bool TEST_DIV_QQ_Q() {
    // test 1
    Q val1_1("-32000", "1");
    Q val1_2("10", "1");
    Q res1("-3200", "1");
    if (val1_1 / val1_2 != res1)
        return false;

    // test 2
    Q val2_1("-32000", "243");
    Q val2_2("-1240", "15");
    Q res2("4000", "2511");
    if (val2_1 / val2_2 != res2)
        return false;

    // test 3
    Q val3_1("-1", "124681274");
    Q val3_2("63", "124681274");
    Q res3("-1", "63");
    if (val3_1 / val3_2 != res3)
        return false;

    return true;
}


void ALL_TEST_Q() {
    bool pass = true;
    if (!TEST_RED_Q_Q()) {
        puts("RED_Q_Q doesn't work =(");
        pass = false;
    }
    if (!TEST_INT_Q_B()) {
        puts("INT_Q_B doesn't work =(");
        pass = false;
    }
    if (!TEST_TRANS_Z_Q()) {
        puts("TRANS_Z_Q doesn't work =(");
        pass = false;
    }
    if (!TEST_TRANS_Q_Z()) {
        puts("TRANS_Q_Z doesn't work =(");
        pass = false;
    }
    if (!TEST_ADD_QQ_Q()) {
        puts("ADD_QQ_Q doesn't work =(");
        pass = false;
    }
    if (!TEST_SUB_QQ_Q()) {
        puts("SUB_QQ_Q doesn't work =(");
        pass = false;
    }
    if (!TEST_MUL_QQ_Q()) {
        puts("MUL_QQ_Q doesn't work =(");
        pass = false;
    }
    if (!TEST_DIV_QQ_Q()) {
        puts("DIV_QQ_Q doesn't work =(");
        pass = false;
    }

    if (pass)
        puts("All tests for Q passed!!");
}