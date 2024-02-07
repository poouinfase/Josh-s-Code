#include <stdio.h>
#include <stdlib.h>
#define SIZEOFARR 4

int main(int argc, char *argv[]) {
  float *p;
  int i, n;
  scanf("%d", &n);
  p = (float *)malloc(sizeof(float) * n);
  for (i = 0; i < n; i++)
    scanf("%f", p + i);
  for (i = 0; i < n; i++)
    printf("%.2f ", *(p + i));
  free(p);
}
