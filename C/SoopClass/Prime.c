#include <stdio.h>
int isPrime(int in) {
  switch (in) {
  case 0:
  case 1:
    return 0;
  default:
    for (int i = 2; i <= in / 2; i++)
      if (in % i == 0) {
        return 0;
      }
    return 1;
  }
}
int main() {
  int beg, en;
  printf("ENTER RANGE: ");
  scanf_s("%d %d", &beg, &en);
  for (int i = beg; i <= en; i++)
    if (isPrime(i))
      printf("%d is PRIME\n", i);
    else
      printf("%d is NOT PRIME\n", i);
}
