#include <stdio.h>
#include <stdlib.h>
#define SIZEOFARR 4
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  float *p;
  p = (float *)calloc(n, sizeof(float));
  for (int i = 0; i < n; i++) {
    scanf("%f", p + i);
  }
  for (int i = 0; i < n; i++) {
    printf("%.2f ", p[i]);
  }
  puts("");
  p = (float *)realloc(p, n * sizeof(float));
  for (int i = 0; i < n; i++) {
    scanf("%f", p + i + n);
  }
  for (int i = 0; i < n * 2; i++) {
    printf("%.2f ", p[i]);
  }
  free(p);
  return 0;
}
