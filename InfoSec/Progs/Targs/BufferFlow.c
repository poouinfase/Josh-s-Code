#include <stdio.h>
#include <sys/unistd.h>

// #define sec

int secure() {
  char buff[200];
  buff[0] = 0;
  int input = read(STDIN_FILENO, buff, 200);
  printf("\n[+] user supplied: %d-bytes!", input);
  printf("\n[+] Buffer content --> %s", buff);
  return 0;
}

int overflow() {
  char buff[200];
  buff[0] = 0;
  int input = read(STDIN_FILENO, buff, 400);
  printf("\n[+] user supplied: %d-bytes!", input);
  printf("\n[+] Buffer content --> %s", buff);
  return 0;
}

int main(int argc, char *argv[]) {
#ifdef sec
  secure();
#else
  overflow();
#endif
  return 0;
}
