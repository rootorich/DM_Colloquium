#include "test_N.h"
#include <iostream>
#include <functional>
using namespace std::rel_ops;

//Структура для тестов
struct Test {
    std::vector<std::string> in1;
    std::vector<std::string> in2;
    std::vector<uint8_t> k;
    std::vector<std::string> expect;
    bool is_in2; // Если входной параметр in2 задан
    bool is_k;   // Если параметр k задан
};

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

  N val1;
  int digit1;

  // test 1
  val1.digits = {0, 0, 0, 0, 1};
  digit1 = 0;
  if (digit1 == val1) {
    return false;
  }

  // test 2
  val1.digits = {5};
  digit1 = 0;
  if (digit1 == val1) {
    return false;
  }

  // test 3
  val1.digits = {0};
  digit1 = 0;
  if (!(digit1 == val1)) {
    return false;
  }

  return true;
}

bool TEST_OP_NEQU_N_DIGIT() {

  N val1;
  int digit;

  // test 1
  val1.digits = {0};
  digit = 0;

  if (val1 != digit) {
    return false;
  }

  // test 2
  val1.digits = {5};
  digit = 0;
  if (!(val1 != digit)) {
    return false;
  }

  // test 3
  val1.digits = {0, 0, 1};
  digit = 0;
  if (!(val1 != digit)) {
    return false;
  }

  return true;

}

bool TEST_OP_NEQU_DIGIT_N() {

  N val1;
  int digit;

  // test 1
  val1.digits = {0};
  digit = 0;

  if (digit != val1) {
    return false;
  }

  // test 2
  val1.digits = {5};
  digit = 0;
  if (!(digit != val1)) {
    return false;
  }

  // test 3
  val1.digits = {0, 0, 1};
  digit = 0;
  if (!(digit != val1)) {
    return false;
  }

  return true;
}

bool TEST_F_NZER_N_B() {
  N val1;
  int digit1;

   // test 1
  val1.digits = {1, 0, 1};

  if(!NZER_N_B(val1))
    return false;

  // test 2
  val1.digits = {0};

  if(NZER_N_B(val1))
    return false;

  // test 3
  val1.digits = {5};

  if(!NZER_N_B(val1))
    return false;

  return true;
}


bool TEST_OP_EQU_N_N() {

  N val1;
  N val2;

   // test 1
  val1.digits = {1, 0, 1};
  val2.digits = {1, 0, 1};

  if(!(val1 == val2))
    return false;

  // test 2
  val1.digits = {0, 0, 5};
  val2.digits = {0, 0, 6};

  if(val1 == val2)
    return false;

  // test 3
  val1.digits = {5};
  val2.digits = {5};

  if (!(val1 == val2))
    return false;

  return true;
}

bool TEST_OP_LT_N_N() {

  N val1;
  N val2;

   // test 1
  val1.digits = {1, 0, 1};
  val2.digits = {1, 0, 1};

  if(val1 < val2)
    return false;

  // test 2
  val1.digits = {5};
  val2.digits = {5, 6};

  if(!(val1 < val2))
    return false;

  // test 3
  val1.digits = {0};
  val2.digits = {5};

  if (!(val1 < val2))
    return false;


  return true;
}

bool TEST_F_COM_NN_D() {

    N val1;
    N val2;

    // test 1: val1 == val2
    val1.digits = {1, 0, 1};
    val2.digits = {1, 0, 1};
    if (COM_NN_D(val1, val2) != 0) return false; // Ожидаем 0, так как числа равны

    // test 2: val1 > val2
    val1.digits = {1, 0, 2}; // 102
    val2.digits = {1, 0, 1}; // 101
    if (COM_NN_D(val1, val2) != 2) return false; // Ожидаем 2, так как val1 больше val2

    // test 3: val1 < val2
    val1.digits = {2}; // 2
    val2.digits = {5, 6}; // 56
    if (COM_NN_D(val1, val2) != 1) return false; // Ожидаем 1, так как val1 меньше val2

    return true; // Если все тесты прошли, возвращаем true
}

// Перегрузка runTests для случая, когда is_in2 = false и is_k = true
bool runTests(const Test& testData, std::function<N(N, uint8_t)> func) {
    for (size_t i = 0; i < testData.in1.size(); ++i) {
        N res = func(N(testData.in1[i]), testData.k[i]); // in1 и k
        if (res != N(testData.expect[i])) {
            return false; // Возврат false, если результат не совпадает
        }
    }
    return true;
}

// Перегрузка runTests для случая, когда is_in2 = true и is_k = false
bool runTests(const Test& testData, std::function<N(N, N)> func) {
    for (size_t i = 0; i < testData.in1.size(); ++i) {
        N res = func(N(testData.in1[i]), N(testData.in2[i])); // in1 и in2
        if (res != N(testData.expect[i])) {
          std::cout << "in1 = " << testData.in1[i] << "\n";
          std::cout << "in2 = " << testData.in2[i] << "\n";
          std::cout << "result = " << res.to_str() << "\n";
          std::cout << "expect = " << testData.expect[i] << "\n";
          return false;
        }
    }
    return true;
}

// Перегрузка runTests для случая, когда is_in2 = false и is_k = false
bool runTests(const Test& testData, std::function<N(N)> func) {
    for (size_t i = 0; i < testData.in1.size(); ++i) {
        N res = func(N(testData.in1[i])); // только in1
        if (res != N(testData.expect[i])) {
            return false;
        }
    }
    return true;
}

// Перегрузка runTests для случая, когда is_in2 = true и is_k = true
bool runTests(const Test& testData, std::function<N(N, N, uint8_t)> func) {
    for (size_t i = 0; i < testData.in1.size(); ++i) {
        N res = func(N(testData.in1[i]), N(testData.in2[i]), testData.k[i]); // in1, in2 и k
        if (res != N(testData.expect[i])) {
            return false;
        }
    }
    return true;
}

bool runTests(const Test& testData, std::function<N(N, uint8_t, N)> func) {
    for (size_t i = 0; i < testData.in1.size(); ++i) {
        N res = func(N(testData.in1[i]), testData.k[i], N(testData.in2[i])); // in1, in2 и k
        if (res != N(testData.expect[i])) {
            return false;
        }
    }
    return true;
}

bool TEST_ADD_1N_N(){

      Test testData = {
        {"201", "505", "1"}, // in1
        {},         // in2
        {},              // k
        {"202", "506", "2"}, // Ожидаемые результаты
        false,                    // is_in2
        false                    // is_k
    };

    // Запускаем тесты для разных перегрузок
    if (!runTests(testData, ADD_1N_N)) {
        return false;
    }
    
    return true; // Успешное завершение всех тестов
}

bool TEST_ADD_NN_N(){

    Test testData = {
      {"201", "201", "201"}, // in1
      {"202", "0", "910"},         // in2
      {},              // k
      {"403", "201", "1111"}, // Ожидаемые результаты
      true,                    // is_in2
      false                     // is_k
  };

  // Запускаем тесты для разных перегрузок
  if (!runTests(testData, ADD_NN_N)) {
      return false;
  }
  
  return true; // Успешное завершение всех тестов

}


bool TEST_MUL_Nk_N() {
    Test testData = {
        {"561", "1", "5857458"}, // in1
        {},         // in2
        {2, 0, 10},              // k
        {"56100", "1", "58574580000000000"}, // Ожидаемые результаты
        false,                    // is_in2
        true                     // is_k
    };

    // Запускаем тесты для разных перегрузок
    if (!runTests(testData, MUL_Nk_N)) {
        return false;
    }
    
    return true; // Успешное завершение всех тестов
}

bool TEST_SUB_NN_N(){

   Test testData = {
        {"202", "201", "901"}, // in1
        {"201", "199", "901"},         // in2
        {},              // k
        {"1", "2", "0"}, // Ожидаемые результаты
        true,                    // is_in2
        false                     // is_k
    };

    // Запускаем тесты для разных перегрузок
    if (!runTests(testData, SUB_NN_N)) {
        return false;
    }
    
    return true; // Успешное завершение всех тестов

}

bool TEST_MUL_NN_N(){

     Test testData = {
        {"561", "0", "45"}, // in1
        {"561", "1", "5857458"},  // in2
        {},              // k
        {"314721", "0", "263585610"}, // Ожидаемые результаты
        true,                    // is_in2
        false                     // is_k
    };

    // Запускаем тесты для разных перегрузок
    if (!runTests(testData, MUL_NN_N)) {
        return false;
    }
    
    return true; // Успешное завершение всех тестов

}


bool TEST_MUL_ND_N(){

    Test testData = {
      {"201", "5", "115"}, // in1
      {},  // in2
      {8, 5, 0},              // k
      {"1608", "25", "0"}, // Ожидаемые результаты
      false,                    // is_in2
      true                     // is_k
  };

  // Запускаем тесты для разных перегрузок
  if (!runTests(testData, MUL_ND_N)) {
    return false;
  }

  return true; // Успешное завершение всех тестов

}


bool TEST_SUB_NDN_N(){

    Test testData = {
      {"201", "5", "115"}, // in1
      {"5", "1", "12"},  // in2
      {8, 5, 9},              // k
      {"161", "0", "7"}, // Ожидаемые результаты
      true,                    // is_in2
      true                     // is_k
  };

  // Запускаем тесты для разных перегрузок
  if (!runTests(testData, SUB_NDN_N)) {
    return false;
  }

  return true; // Успешное завершение всех тестов

}

bool TEST_DIV_NN_Dk(){

  Test testData = {
      {"11500", "403", "11700", "20000", "2010"}, // in1
      {"5", "20", "30", "10", "10"},  // in2
      {},              // k
      {"2000", "20", "300", "2000", "200"}, // Ожидаемые результаты
      true,                    // is_in2
      false                     // is_k
  };

  if (!runTests(testData, DIV_NN_Dk)) {
    return false;
  }

  return true; 

}

bool TEST_DIV_NN_N(){

    Test testData = {
      {"11500", "403", "11721","2010", "784378783"}, // in1
      {"5", "20", "30", "10", "7433"},  // in2
      {},              // k
      {"2300", "20", "390", "201", "105526"}, // Ожидаемые результаты
      true,                    // is_in2
      false                     // is_k
  };

  if (!runTests(testData, DIV_NN_N)) {
    return false;
  }
  return true; 

}

bool TEST_MOD_NN_N(){

  Test testData = {
    {"11500", "403", "11721","201", "784378783"}, // in1
    {"5", "20", "30", "10", "7433"},  // in2
    {},              // k
    {"0", "3", "21", "1", "4025"}, // Ожидаемые результаты
    true,                    // is_in2
    false                     // is_k
  };

    if (!runTests(testData, MOD_NN_N)) {
      return false;
    }
    return true; 

}

bool TEST_GCF_NN_N(){
  
    Test testData = {
    {"11500", "403", "11721","201"}, // in1
    {"5", "20", "30", "10"},  // in2
    {},              // k
    {"5", "1", "3", "1"}, // Ожидаемые результаты
    true,                    // is_in2
    false                     // is_k
  };

    if (!runTests(testData, GCF_NN_N)) {
      return false;
    }
    return true; 

}

bool TEST_LCM_NN_N(){
  
    Test testData = {
    {"11500", "403", "11721", "201"}, // in1
    {"5", "20", "30", "10"},  // in2
    {},              // k
    {"11500", "8060", "117210", "2010"}, // Ожидаемые результаты
    true,                    // is_in2
    false                     // is_k
  };

    if (!runTests(testData, LCM_NN_N)) {
      return false;
    }
    return true; 

}


void ALL_TEST_N(){

    if (TEST_OP_EQU_N_DIGIT()) {
        std::cout << "N == DIGIT is work";
    } else {
        std::cout << "N == DIGIT does't work";
    }
    std::cout << "\n";
    
    if (TEST_OP_EQU_DIGIT_N()) {
        std::cout << "DIGIT == N is work";
    } else {
        std::cout << "DIGIT == N does't work";
    }
    std::cout << "\n";


    if (TEST_OP_NEQU_N_DIGIT() ) {
        std::cout << "DIGIT != N is work";
    } else {
        std::cout << "DIGIT != N  does't work";
    }

    std::cout << "\n";

    if (TEST_OP_NEQU_DIGIT_N()) {
        std::cout << "N != DIGIT is work";
    } else {
        std::cout << "N != DIGIT does't work";
    }
    std::cout << "\n";

    if (TEST_F_NZER_N_B()) {

        std::cout << "N != 0 is work";
    } else {
        std::cout << "N != 0 does't work";
    }

    std::cout << "\n";

    if (TEST_OP_EQU_N_N()) {

        std::cout << "N == N is work";
    } else {
        std::cout << "N == N does't work";
    }

    std::cout << "\n";

    if (TEST_OP_LT_N_N()) {

        std::cout << "N < N is work";
    } else {
        std::cout << "N < N does't work";
    }

    std::cout << "\n";


    if (TEST_F_COM_NN_D()) {

        std::cout << "N >= N is work";
    } else {
        std::cout << "N >= N does't work";
    }

    std::cout << "\n";

    if (TEST_ADD_1N_N()) {

        std::cout << "N == N+1 is work";
    } else {
        std::cout << "N == N+1 does't work";
    }

    std::cout << "\n";

    if (TEST_ADD_NN_N()) {

        std::cout << "N1+N2 is work";
    } else {
        std::cout << "N1+N2 does't work";
    }

    std::cout << "\n";


    if (TEST_SUB_NN_N()) {

        std::cout << "N1-N2 is work";
    } else {
        std::cout << "N1-N2 does't work";
    }

    std::cout << "\n";

    if (TEST_MUL_ND_N()) {

        std::cout << "N*DIGIT is work";
    } else {
        std::cout << "N*DIGIT does't work";
    }
    std::cout << "\n";


    if (TEST_MUL_Nk_N()) {

        std::cout << "N*10^k is work";
    } else {
        std::cout << "N*10^k does't work";
    }
    std::cout << "\n";


    if (TEST_MUL_NN_N()) {
        std::cout << "N1*N2 is work";
    } else {
        std::cout << "N1*N2 does't work";
    }
    std::cout << "\n";

    if (TEST_SUB_NDN_N()) {
        std::cout << "N1-(N2*digit) is work";
    } else {
        std::cout << "N1-(N2*digit) does't work";
    }
    std::cout << "\n";


    if (TEST_DIV_NN_Dk()) {
        std::cout << "FIRST_DIGIT*10^k is work";
    } else {
        std::cout << "FIRST_DIGIT*10^k does't work";
    }
    std::cout << "\n";

    if (TEST_DIV_NN_N()) {
        std::cout << "QUOTIENT is work";
    } else {
        std::cout << "QUOTIENT does't work";
    }
    std::cout << "\n";


    if(TEST_MOD_NN_N()) {
        std::cout << "REMAINDER is work";
    } else {
        std::cout << "REMAINDER does't work";
    }
    std::cout << "\n";


    if(TEST_GCF_NN_N()) {
        std::cout << "GCD is work";
    } else {
        std::cout << "GCD does't work";
    }
    std::cout << "\n";


    if(TEST_LCM_NN_N()) {
        std::cout << "LCM is work";
    } else {
        std::cout << "LCM does't work";
    }
    std::cout << "\n";


}
