#include "RuntimeErrorStub.h"

#include "util/RuntimeError.h"

static const char * message = "No Error";
static int parameter = -1;
static const char * file = 0;
static int line = -1;

void RuntimeErrorStub_Reset(void) {
  message = "No Error";
  parameter = -1;
}

const char * RuntimeErrorStub_GetLastError(void) {
  return message;
}

int RuntimeErrorStub_GetLastParamter(void) {
  return parameter;
}

void RuntimeError(const char* m, int p, const char* f, int l) {
  message = m;
  parameter = p;
  file = f;
  line = l;
}

