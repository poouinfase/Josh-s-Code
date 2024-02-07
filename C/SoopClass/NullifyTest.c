#include <stdio.h>
#include <stdlib.h>
#define SIZEOFARR 4
void Nullify(int **p) {
  free(*p);
  *p = NULL;
  return;
}
int main(int argc, char *argv[]) {
  int *p = malloc(sizeof(int) * 3);
  printf("%zu\n", p);
  Nullify(&p);
  printf("%zu\n", p);
  return 0;
}
