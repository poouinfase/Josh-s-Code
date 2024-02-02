#include <stdio.h>

#define ROW 3
#define COL 3

void printtabl(int poin[ROW][COL]) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &poin[i][j]);
    }
  }
}
int main(int argc, char *argv[]) {
  int A[ROW][COL];
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  printf("\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      if (i + j + 1 == ROW || i == j)
        printf("%d", A[i][j]);
      else
        printf(" ");
    }
    printf("\n");
  }
}
