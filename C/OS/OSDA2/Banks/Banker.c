#include <stdio.h>
#include <stdlib.h>

int searchNexSaf(int **Need, int *Avail, int **Alloc, int Num_Proc, int Num_Res,
                 int con) {
  int isSaf = 0;
  for (int i = 0; i < Num_Proc; i++) {
    int ind = (i + con) % Num_Proc;
    if (Need[ind] == NULL)
      continue;
    isSaf = 1;
    for (int j = 0; j < Num_Res; j++) {
      isSaf = isSaf && (Need[ind][j] <= Avail[j]);
    }
    if (isSaf) {
      for (int j = 0; j < Num_Res; j++)
        Avail[j] += Alloc[ind][j];
      free(Need[ind]);
      Need[ind] = NULL;
      return ind;
    }
  }
  puts("");
  return -1;
}

int prinSafSeq(int **ProcNeed, int **ProcAllo, int *ProcAvail, int Num_Proc,
               int Num_Res, char *prompt) {
  puts("");
  int con = -1;
  int Seq[Num_Proc];
  for (int i = 0; i < Num_Proc; i++) {
    con =
        searchNexSaf(ProcNeed, ProcAvail, ProcAllo, Num_Proc, Num_Res, con + 1);
    if (con == -1) {
      return -1;
    }
    Seq[i] = con;
  }
  puts(prompt);
  for (int i = 0; i < Num_Proc; i++) {
    printf("P%d", Seq[i]);
    if (i != Num_Proc - 1)
      printf("->");
  }
  return 0;
}

void printTable(int **AR1, int **AR2, int **AR3, int Rows, int Col) {
  puts("ALLOC\tMAX\tNEED");
  for (int i = 0; i < Rows; i++) {
    for (int j = 0; j < Col; j++)
      printf("%d ", AR1[i][j]);

    putc('\t', stdout);
    for (int j = 0; j < Col; j++)
      printf("%d ", AR2[i][j]);

    putc('\t', stdout);
    for (int j = 0; j < Col; j++)
      printf("%d ", AR3[i][j]);

    puts("");
  }
}

void xFree(int **Arr, int len) {
  for (int i = 0; i < len; i++) {
    free(Arr[i]);
  }
  free(Arr);
}

int main() {
  int Num_Proc, Num_Res;
  int AddResInd = -1;
  scanf("%d %d", &Num_Proc, &Num_Res);
  int **ProcAllo = (int **)calloc(Num_Proc, sizeof(int *));
  int **ProcMaxi = (int **)calloc(Num_Proc, sizeof(int *));
  int **ProcNeed = (int **)calloc(Num_Proc, sizeof(int *));
  int *ProcAvail = (int *)calloc(Num_Res, sizeof(int));
  int *ProcAvailCpy = (int *)calloc(Num_Res, sizeof(int));

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
    ProcAvailCpy[j] = ProcAvail[j];
  }
  // OUTPUT TABLE
  printTable(ProcAllo, ProcMaxi, ProcNeed, Num_Proc, Num_Res);
  // OUTPUTSEQ
  if (prinSafSeq(ProcNeed, ProcAllo, ProcAvail, Num_Proc, Num_Res,
                 "SAFE SEQUENCE:")) {
    puts("ERROR NO SAFE SEQUENCE");
    goto ERR;
  }

  ProcNeed = (int **)calloc(Num_Proc, sizeof(int *));
  for (int i = 0; i < Num_Proc; i++) {
    ProcNeed[i] = (int *)calloc(Num_Res, sizeof(int));
    for (int j = 0; j < Num_Res; j++) {
      ProcNeed[i][j] = ProcMaxi[i][j] - ProcAllo[i][j];
    }
  }
  // INPUT AddResInd
  if (scanf("%d", &AddResInd) != EOF) {
    int temp;
    for (int j = 0; j < Num_Res; j++) {
      scanf("%d", &temp);
      ProcNeed[AddResInd][j] += temp;
    }
  }

  if (AddResInd != -1 && prinSafSeq(ProcNeed, ProcAllo, ProcAvailCpy, Num_Proc,
                                    Num_Res, "ADDITIONAL RESOURCE:")) {
    puts("ADDITIONAL RESOURCE CANNOT BE GRANTED");
  }
ERR:
  xFree(ProcAllo, Num_Proc);
  xFree(ProcMaxi, Num_Proc);
  free(ProcNeed);
  free(ProcAvail);
  free(ProcAvailCpy);
  return 0;
}
