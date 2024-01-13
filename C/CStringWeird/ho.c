#include <stdio.h>

// #define Tes

#include <stdlib.h>

#ifndef Tes

// #define Firs

#ifdef Firs
int main() {
  printf("Firs\n");
  int *s = malloc(5 * sizeof(char));
#define char1 'L'
#define char2 'O'
#define char3 'L'
#define char4 'O'
#define char5 'I'
  *s = char1;
  *(s + 1) = char2;
  *(s + 2) = char3;
  *(s + 3) = char4;
  *(s + 4) = char5;
  printf("%d %d %d %d %d\n", *s, *(s + 1), *(s + 2), *(s + 3), *(s + 4));
  printf("%c %c %c %c %c\n", *s, *(s + 1), *(s + 2), *(s + 3), *(s + 4));
  printf("%d\n", *s);
  free(s);
}

#else
#include <stdio.h>
int main() {
  printf("Seco\n");
  int *s = calloc(4, sizeof(char));
  scanf("%s", s);
  printf("%d\n", *s);
  printf("%s\n", s);
  free(s);
}
#endif

#else

int main() {
  printf("Tes\n");
  char *s = (char *)malloc(2 * sizeof(char));
  *s = 'h';
  *(s + 1) = 'i';
  printf("%d\n", *s);
  free(s);
}
#endif
