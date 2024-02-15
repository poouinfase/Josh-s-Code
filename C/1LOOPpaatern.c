#include <stdio.h>

int main() {
  int n = 5;
  char lin = 0;
  int cp = 0;
  int ca = 1;
  for (int i = 0; i < n * (n + 1) / 2; i++) {
    if (i == cp) {
      printf("%c", lin);
      lin = '\n';
      cp += ca++;
    }
    printf("*");
  }
}
