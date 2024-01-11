#include <stdio.h>
union s {
  char chra;
  int num;
};
void dispchar(char);

int main(int argv, char **argc) {
  for (int i = 1; i < argv; i++) {
    for (char *c = *(argc + i); *c != '\0'; c++)
      dispchar(*c);
    printf("\n");
  }
}

void dispchar(char c) {
  static union s var1;
  var1.chra = c;
  printf("%d\t%c\n", var1.chra, var1.num);
}
