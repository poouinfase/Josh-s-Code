#include <stdint.h>
#include <stdio.h>

union Log2 {
  float Num;
  int32_t log2;
};

int main() {
  union Log2 N;
  N.Num = -8;
  printf("%u\n", N.log2);
}
