#include "N.h"

test Test2(const test& t) {
  test result;

  for (size_t i = 0; i < t.test.size(); ++i) {
    if (t.test[i] >= t.test[2]) {
      result.test.emplace_back(t.test[i]);
    } else {
      result.test.emplace_back(t.test[3] + t.test[1] * 5);
    }
  }

  return result;
}
//Efimova

//Перегрузка оператора == для сравнения N == 0
bool operator==(const test& t, int zero) {
    return t.test.size() == 1 && t.test[0] == 0;
}

// Перегрузка оператора == для сравнения 0 == N
bool operator==(int zero, const test& t) {
    return t == zero; // Используем предыдущую перегрузку
}
// Перегрузка оператора != для сравнения с N!=0
bool operator!=(const test& t, int zero) {
    return !(t == zero);
}
//Перегрузка оператора != для сравнения 0 != N
bool operator!=(int zero, const test& t) {
    return !(t == zero); // Позволяет сравнивать с 0 в обоих направлениях
}

//Функция для проверки, не равно ли число нулю
bool NZER_N_B(const test& t) {
    return t != 0; // Возвращаем результат сравнения с нулем
}

//Efimova

void Test() {
  test t;

  std::vector<size_t> in = {1,2,3,4};

  for (size_t i = 0; i < in.size(); ++i) {
    t.test.emplace_back(in[i]);
  }

  for (auto el : in) {
    t.test.emplace_back(el);
  }

  test t2 = Test2(t);

  std::cout << "num like uint8_t unreadable\n";
  std::cout << "but it is usable\n";
  std::cout << "For example\n\n";
  for (auto el : t2.test) {
    std::cout << "size is " << sizeof(el) << "\n";
    std::cout << "value is " << (size_t)el << "\n";
    el = el * 2;
    std::cout << "value after change " << (size_t)el << "\n";
    std::cout << "size if use size_t " << sizeof((size_t)el) << "\n\n";
  }
}
