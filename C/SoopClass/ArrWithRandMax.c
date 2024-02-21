#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randfill(int *Arr, int len);
void printabl(int *Arr, int len);
int max(int *Arr, int len);

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int n = 0;
  scanf("%d", &n);
  int *Arr = (int *)malloc(n * sizeof(int));
  randfill(Arr, n);
  printabl(Arr, n);
}

void randfill(int *Arr, int len) {
  for (int i = 0; i < len; i++) {
    Arr[i] = rand();
  }
}

void printabl(int *Arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", Arr[i]);
  }
  putchar('\n');
  printf("%d ", max(Arr, len));
  putchar('\n');
}

int max(int *Arr, int len) {
  if (0 == len)
    return -1;
  int max = Arr[0];
  for (int i = 1; i < len; i++) {
    if (max < Arr[i])
      max = Arr[i];
  }
  return max;
}
