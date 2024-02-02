#include <stdio.h>

#define ROW 2
#define COL 3

void printtabl(int poin[ROW][COL]) {

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &poin[i][j]);
    }
  }
}
void add(int A[ROW][COL], int B[ROW][COL], int C[ROW][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}
int main(int argc, char *argv[]) {
  int A[ROW][COL];
  int B[ROW][COL];
  int C[ROW][COL];
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      scanf("%d", &B[i][j]);
    }
  }
  add(A, B, C);
  printtabl(C);
}
