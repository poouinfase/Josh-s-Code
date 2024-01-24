#include <stdio.h>
int main() {
  int n, n1, rev = 0, digit;
  printf("Num:\t");
  scanf_s("%d", &n);
  n1 = n;
  while (n) {
    rev = rev * 10 + n % 10;
    n /= 10;
  }
  printf("Rev of %d is %d", n1, rev);
}
