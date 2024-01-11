#include <stdio.h>

typedef struct RICK {
  int firs;
  int seco;
  int thrio;
} RICK;

int main() {
  RICK a;
  a = (RICK){.firs = 1, .seco = 2, .thrio = 3};
  printf("%d %d %d", a.firs, a.seco, a.thrio);
  return 0;
}
