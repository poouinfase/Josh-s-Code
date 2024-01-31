#include <stdio.h>

int isvowel(char c) {
  switch (c) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
    return 1;
  default:
    return 0;
  }
}

int main(int argc, char *argv[]) {
  char s[50];
  scanf_s("%[^\n]s", s);
  int coun = 0;
  for (char *i = s; *i != 0; i++)
    coun += isvowel(*i);
  printf("%d", coun);
  return 0;
}
