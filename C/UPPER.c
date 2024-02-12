#include <stdio.h>
#include <stdlib.h>

void Toupper(char *s);

int main(int argc, char *argv[]) {
  char *s = malloc(50 * sizeof(char));
  scanf("%[^\n]s", s);
  Toupper(s);
  puts(s);
  return 0;
}

void Toupper(char *s) {
  while (*s) {
    if (*s == '_') {
      s++;
      continue;
    }
    *s = *s & (~32);
    s++;
  }
}

void Tolower(char *s) {
  while (*s) {
    if (*s == '_') {
      s++;
      continue;
    }
    *s = *s | (32);
    s++;
  }
}
