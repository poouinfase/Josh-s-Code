#include <stdio.h>
void f() { printf("HELLO WORLD\n"); }
int main(int argc, char *argv[]) {
  void (*func)(void);
  func = &f;
  func();
}
