#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_OF_TYPING 26

char randselect(char *s, int len) { return s[rand() % len]; }

void moveleft() {
  putc('\e', stdout);
  putc('[', stdout);
  putc('D', stdout);
}

int main(int argc, char *argv[]) {
  char i;
  srand(time(NULL));
  char *s = "ABCDEFGHIJLKMNOPQRSTUVWXYZ";
  do {
    char tmp = randselect(s, SIZE_OF_TYPING);
    putc(tmp, stdout);
    i = _getch();
    if ((i - 32) == (tmp))
      moveleft();
    else
      puts("");
  } while (i && i != 3);
}
