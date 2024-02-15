#include <stdio.h>

int main() {
  int n = 0;
  if (0 == scanf("%d", &n))
    return -1;
  int cp = 1;
  int ca = 2;
  for (int i = 0; i < n * (n + 1) / 2; i++) {
    if (!cp) {
      printf("\n");
      cp = ca++;
    }
    cp--;
    printf("*");
  }
}
