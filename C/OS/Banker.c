#include <stdio.h>
#include <stdlib.h>

int src(int **Arr, int *Avail, int **Alloc, int Num_Proc, int Num_Res,
        int con) {
  int isSaf = 0;
  for (int i = 0; i < Num_Proc; i++) {
    if (Arr[(i + con) % Num_Proc] == NULL)
      continue;
    isSaf = 1;
    for (int j = 0; j < Num_Res; j++) {
      isSaf = isSaf && (Arr[(i + con) % Num_Proc][j] <= Avail[j]);
    }
    if (isSaf) {
      for (int j = 0; j < Num_Res; j++)
        Avail[j] += Alloc[(i + con) % Num_Proc][j];
      free(Arr[(i + con) % Num_Proc]);
      Arr[(i + con) % Num_Proc] = NULL;
      return i;
    }
  }
  return -1;
}

void xFree(int **Arr, int len) {
  for (int i = 0; i < len; i++) {
    free(Arr[i]);
  }
  free(Arr);
}

int main() {
  int Num_Proc, Num_Res;
  scanf("%d %d", &Num_Proc, &Num_Res);
  printf("%d %d\n", Num_Proc, Num_Res);
  int **ProcAllo = (int **)calloc(Num_Proc, sizeof(int *));
  int **ProcMaxi = (int **)calloc(Num_Proc, sizeof(int *));
  int **ProcNeed = (int **)calloc(Num_Proc, sizeof(int *));
  int *ProcAvail = (int *)calloc(Num_Res, sizeof(int));

  for (int i = 0; i < Num_Proc; i++) {
    ProcAllo[i] = (int *)calloc(Num_Res, sizeof(int));
    ProcMaxi[i] = (int *)calloc(Num_Res, sizeof(int));
    ProcNeed[i] = (int *)calloc(Num_Res, sizeof(int));
  }
  // INPUT TABLE
  for (int i = 0; i < Num_Proc; i++) {
    for (int j = 0; j < Num_Res; j++)
      scanf("%d", *(ProcAllo + i) + j);
    for (int j = 0; j < Num_Res; j++)
      scanf("%d", *(ProcMaxi + i) + j);
    for (int j = 0; j < Num_Res; j++)
      ProcNeed[i][j] = ProcMaxi[i][j] - ProcAllo[i][j];
  }
  // INPUT AVAIL
  for (int j = 0; j < Num_Res; j++) {
    scanf("%d", &ProcAvail[j]);
  }

  // OUTPUT TABLE
  puts("ALLOC\tMAX\tNEED");
  for (int i = 0; i < Num_Proc; i++) {
    for (int j = 0; j < Num_Res; j++)
      printf("%d ", ProcAllo[i][j]);

    putc('\t', stdout);
    for (int j = 0; j < Num_Res; j++)
      printf("%d ", ProcMaxi[i][j]);

    putc('\t', stdout);
    for (int j = 0; j < Num_Res; j++)
      printf("%d ", ProcNeed[i][j]);

    puts("");
  }
  int *n = malloc(8);
  int con = 0;
  for (int i = 0; i < 5; i++) {
    con = src(ProcNeed, ProcAvail, ProcAllo, Num_Proc, Num_Res, 0);
    printf("%d\n", con);
  }
  xFree(ProcAllo, Num_Proc);
  xFree(ProcNeed, Num_Proc);
  xFree(ProcMaxi, Num_Proc);
  free(ProcAvail);
  return 0;
}
