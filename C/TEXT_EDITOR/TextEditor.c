#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void keymove(char *i) {
  *i = _getch();
  putc(0x1B, stdout);
  putc('[', stdout);
  switch (*i) {
  case 'H':
    *i = 'A';
    break;
  case 'K':
    *i = 'D';
    break;
  case 'P':
    *i = 'B';
    break;
  case 'M':
    *i = 'C';
    break;
  }
}

void backspace() {
  putc(8, stdout);
  putc(' ', stdout);
}

int main(int argc, char *argv[]) {
  int chrc = 0;
  for (char i = _getch(); i != '\0'; i = _getch()) {
    if (i == 13)
      i = '\n';
    if (i == -32)
      keymove(&i);
    if (i == 8)
      backspace();
    putc(i, stdout);
    chrc++;
  }
  printf("\n%d\n", chrc);
  return EXIT_SUCCESS;
}
