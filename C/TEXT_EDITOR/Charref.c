#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int chrc = 0;
  for (unsigned char i = _getch(); i != '\0'; i = _getch()) {
    printf("%c %d\n", i, i);
    chrc++;
  }
  printf("\n%d\n", chrc);
  return EXIT_SUCCESS;
}
