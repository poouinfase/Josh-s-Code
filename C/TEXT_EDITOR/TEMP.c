
#include <conio.h>
#include <stdio.h>
#define LEN 10

int main() {
  char s[LEN + 1];
  for (int i = 0; i < LEN; i++) {
    s[i] = _getch();
    putchar(s[i]);
  }
  s[LEN] = '\0';
  FILE *fptr = fopen("DATest.txt", "w");
  fprintf(fptr, s);
  fclose(fptr);
}
