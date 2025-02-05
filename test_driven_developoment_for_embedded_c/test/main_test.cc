
#include "CppUTest/TestHarness.h"

// テスト対象の関数
int add(int a, int b) {
  return a + b;
}

TEST_GROUP(Addition) {};

TEST(Addition, PositiveNumbers) {
    CHECK(add(1, 2) == 3);
}

TEST(Addition, NegativeNumbers) {
    CHECK(add(-1, -2) == -3);
}
