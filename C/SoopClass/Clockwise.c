#include <stdio.h>

#define ROW 4
#define COL 3

void printrow(int row, int poin[ROW][COL]) {
  for (int i = 0; i < COL; i++)
    printf("%d ", poin[row][i]);
  printf("\n");
}
void printcol(int col, int poin[ROW][COL]) {
  for (int i = 0; i < ROW; i++)
    printf("%d ", poin[i][col]);
  printf("\n");
}
int main(int argc, char *argv[]) {
  int A[ROW][COL];
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      scanf("%d", &A[i][j]);
    }
  }
  printf("\n");
  printrow(0, A);       // print top
  printcol(COL - 1, A); // print right
  printrow(ROW - 1, A); // print bottow
  printcol(0, A);       // print left
}
