#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define zero '0'

uint64_t stringtoint(char *s) {
  uint64_t out = 0;
  uint64_t len = strlen(s);
  for (uint64_t i = 0; i < len; i++)
    out = out * 10 + (uint64_t)(*(s + i) - zero);
  return out;
}

int search1(int *arr, int l, int r, int x) {
  while (l <= r) {
    int m = (l + r) / 2;
    if (arr[m] == x)
      return m;
    if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}

int search2(int *arr, int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x)
      return i;
  }
  return -1;
}

int main(int argc, char **argv) {
  // printf("%d\n", argc);
  uint64_t siz;
  siz = 1000000;
  if (argc == 2) {
    siz = stringtoint(*(argv + 1));
    // printf("SIz is now %ld\n", siz);
  }
  srand(time(NULL));

  short int choice;
  scanf_s("%d", &choice);
  int *numArr = (int *)calloc(siz, sizeof(int));
  *numArr = rand();
  for (uint64_t i = 0; i < siz; i++)
    numArr[i] = i + numArr[0];
  int findMe = numArr[rand() % siz];
  // LARGE_INTEGER freq;
  // LARGE_INTEGER before;
  // LARGE_INTEGER after;
  // long double interval;
  // QueryPerformanceFrequency(&freq);
  // QueryPerformanceCounter(&before);
  switch (choice) {
  case 1:
    printf("1\n%d\n", search1(numArr, 0, siz - 1, findMe));
    break;

    // QueryPerformanceCounter(&after);
    // interval = (long double)(after.QuadPart - before.QuadPart) /
    // freq.QuadPart; printf("%Lf\n", interval);
    // QueryPerformanceCounter(&before);
  case 2:
    printf("2\n%d\n", search2(numArr, siz, findMe));
    break;

    // QueryPerformanceCounter(&after);
    // interval = (long double)(after.QuadPart - before.QuadPart) /
    // freq.QuadPart; printf("%Lf\n", interval);
  }
  free(numArr);
}