#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  size_t len;
  char *string;
} StrView;

int main() {
  StrView *p;
  p = (StrView *)malloc(sizeof(StrView));

  p->string = malloc(12 * sizeof(char));
  strcpy(p->string, "HELLO WORLD!");
  p->len = strlen(p->string);

  printf("%d %.*s", p->len, p->len, p->string);

  free(p->string);
  free(p);
}
