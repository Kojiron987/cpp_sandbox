#include <cstdio>
#include <cstring>

#include "CppUTest/TestHarness.h"

TEST_GROUP(sprintf) {
  char output[100];
  const char* expected;

  void setup() {
    memset(output, 0xaa, sizeof(output));
    expected = "";
  }

  void teardown() {
  }

  void expect(const char* s) {
    expected = s;
  }

  void given(int charsWritten) {
    LONGS_EQUAL(strlen(expected), charsWritten);
    BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    STRCMP_EQUAL(expected, output);
  }
};

TEST(sprintf, NoFormatOperations) {
  expect("hey");
  given(sprintf(output, "hey"));
}

TEST(sprintf, InsertString) {
  expect("Hello World\n");
  given(sprintf(output, "Hello %s\n", "World"));
}
