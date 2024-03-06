#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int firsFit(int *Arr, int len, int Tofit);
int bestFit(int *Arr, int len, int Tofit);
int worsFit(int *Arr, int len, int Tofit);

int main() {
  int NumOfBlocks = 0;
  printf("Number of blocks: ");
  if (0 == scanf("%d", &NumOfBlocks))
    return -1;
  putchar('\n');

  assert(NumOfBlocks);

  int *Arr = (int *)malloc(NumOfBlocks * sizeof(int));
  printf("Enter blocks:\n");
  for (int i = 0; i < NumOfBlocks; i++) {
    if (0 == scanf("%d", Arr + i))
      return -1;
  }
  putchar('\n');

  int Tofit = 0;
  printf("Enter request: ");
  if (0 == scanf("%d", &Tofit))
    return -1;
  putchar('\n');

  printf("FirstFit: %d\nBestFit: %d\nWorstFit: %d",
         Arr[firsFit(Arr, NumOfBlocks, Tofit)],
         Arr[bestFit(Arr, NumOfBlocks, Tofit)],
         Arr[worsFit(Arr, NumOfBlocks, Tofit)]);
  free(Arr);
}

int firsFit(int *Arr, int len, int Tofit) {
  for (int i = 0; i < len; i++) {
    if (Arr[i] >= Tofit)
      return i;
  }
  return -1;
}

int bestFit(int *Arr, int len, int Tofit) {
  assert(len > 0);
  int minWaste = firsFit(Arr, len, Tofit);
  for (int i = 0; i < len; i++) {
    if (((Arr[i] - Tofit) < (Arr[minWaste] - Tofit)) && (Arr[i] >= Tofit))
      minWaste = i;
  }
  return minWaste;
}

int worsFit(int *Arr, int len, int Tofit) {
  assert(len > 0);
  int maxWaste = firsFit(Arr, len, Tofit);
  for (int i = 0; i < len; i++) {
    if (((Arr[i] - Tofit) > (Arr[maxWaste] - Tofit)) && (Arr[i] >= Tofit))
      maxWaste = i;
  }
  return maxWaste;
}
