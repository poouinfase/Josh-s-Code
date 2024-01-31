#include <stdio.h>

int main(int argc, char *argv[]) {
  char s[50];
  char cChek = 'O', cRep = 'E';
  scanf("%s %c %c", s, &cChek, &cRep);
  printf("%s\nCHEK: %d\nREP: %d\n", s, cChek, cRep);
  for (char *i = s; *i != 0; i++) {
    if (*i == cChek)
      *i = cRep;
  }
  printf("%s\n", s);
}
