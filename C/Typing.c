#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// char randselect(char *s) { return s[rand() % strlen(s)]; }
char randLetter() { return "ABCDEFGHIJLKMNOPQRSTUVWXYZ"[rand() % 26]; }

void moveleft() {
  putc('\e', stdout);
  putc('[', stdout);
  putc('D', stdout);
}

int main(int argc, char *argv[]) {

  srand(time(NULL));
  char i;
  // char *s = "ABCDEFGHIJLKMNOPQRSTUVWXYZ";

  do {
    char tmp = randLetter();
    putchar(tmp);
    i = _getch();

    if ((i - 32) == (tmp))
      moveleft();
    else
      putchar('\n');
  } while (i && i != 3);
}
