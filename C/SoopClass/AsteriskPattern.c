#include <stdio.h>
int main() {
  int roSiz = 0;
  printf("ENTER ROWS: ");
  scanf_s("%d", &roSiz);
  int siz = 1;
  for (int i = 0; i < roSiz; i++) {
    for (int i = 0; i < siz; i++)
      printf("*");
    putc('\n', stdout);
    siz++;
  }
}
