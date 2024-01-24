#include <stdio.h>
int main() {
  int roSiz = 0;
  printf("ENTER ROWS: ");
  scanf_s("%d", &roSiz);
  for (int siz = 1; siz <= roSiz; siz++) {
    for (int j = 0; j < roSiz - siz; j++)
      putc(' ', stdout);
    for (int j = 0; j < siz; j++) {
      printf("* ");
    }
    putc('\n', stdout);
  }
}
