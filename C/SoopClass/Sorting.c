#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_ARR 5

#define SWAP(A, B)                                                             \
  do {                                                                         \
    if ((A) == (B))                                                            \
      break;                                                                   \
    (A) ^= (B);                                                                \
    (B) ^= (A);                                                                \
    (A) ^= (B);                                                                \
  } while (0)

void prinArr(int *v, int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", v[i]);
  puts("");
}

int minn(int *n, int len, int at) {
  int smalles = at;
  for (int i = at; i < len; i++) {
    smalles = (n[smalles] < n[i]) ? smalles : i;
  }
  return smalles;
}

void sort(int *n, int len) {
  for (int i = 0; i < len; i++) {
    int minun = minn(n, len, i);
    SWAP(n[i], n[minun]);
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  printf("HELLO WORLD\n");
  int *n = (int *)calloc(SIZE_ARR, sizeof(int));
  for (int i = 0; i < SIZE_ARR; i++)
    n[i] = rand();
  prinArr(n, SIZE_ARR);
  sort(n, SIZE_ARR);
  puts("\nSORTED ARRAY:");
  prinArr(n, SIZE_ARR);

  free(n);
  return EXIT_SUCCESS;
}
