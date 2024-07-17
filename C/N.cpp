#include <stdio.h>
int main() {
  char name[10];
  scanf("%s", name);
  int i = 0;
  while (name[i] != '\0') {
    printf("%c", name[i]);
    i++;
  }
  printf("\n");
  return 0;
}
