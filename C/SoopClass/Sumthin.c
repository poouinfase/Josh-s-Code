#include <stdio.h>

int main(int argc, char *argv[]) {
  char s[50];
  int sum = 0;
  scanf_s("%[^\n]s", s);
  for (char *i = s; *i != 0; i++) {
    sum += *i;
  }
  printf("%d\n", sum);
}
