#include <stdio.h>
#include <stdlib.h>

int fibof(int *, int);
int *fibLis(int);

int main(int argc, char *argv[]) {
  int n = 0;
  if (0 == scanf("%d", &n))
    return -1;

  int *Fib = fibLis(n);

  for (int i = 0; i < n; i++)
    printf("%d ", Fib[i]);
  putchar('\n');

  free(Fib);
}

int *fibLis(int n) {
  int *Fib = (int *)malloc(sizeof(int) * (1 + n));
  for (int i = 0; i < n; i++)
    Fib[i] = 0;
  Fib[1] = 1;
  fibof(Fib, n);
  return Fib;
}

int fibof(int *Fib, int n) {
  if (!Fib[n] && n)
    Fib[n] = fibof(Fib, n - 1) + fibof(Fib, n - 2);
  return Fib[n];
}
