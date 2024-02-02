#include <stdio.h>

int reverse(int n) {
  int re = 0;
  while (n) {
    re = re * 10 + n % 10;
    n /= 10;
  }
  return re;
}
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d %d", n, reverse(n));
}
