#include <stdio.h>

int f(int n) {
  int outFac = 1;
  while (n > 0) {
    outFac *= n--;
  }
  return outFac;
}
int main(int argc, char *argv[]) {
  int (*func)(int);
  func = &f;
  printf("%d", func(5));
}
