#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  srand(time(NULL));
  int begin = rand();
  long long int num = 0;
  long long int max = 0;
  long long int tmp = rand();
  while (begin != tmp) {
    tmp = rand();
    num++;
    max = (max > tmp) ? max : tmp;
  }
  printf("%llu\n", max);
}
