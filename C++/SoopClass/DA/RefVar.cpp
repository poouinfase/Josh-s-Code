#include <stdio.h>
void changeAddr(int *ref) { (*ref)++; }
void change(int val) { val++; }

int main(int argc, char *argv[]) {
  int n = 90;
  printf("%d\n", n);
  change(n); // Change not carried into main
  printf("%d\n", n);
  changeAddr(&n); // Change is done to n
  printf("%d\n", n);
  return 0;
}
