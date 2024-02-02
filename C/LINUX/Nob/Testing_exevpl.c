#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  char** const arv=calloc(6, sizeof(char));
  arv[0]="gcc";
  arv[1]="-g";
  arv[2]="-o";
  arv[2]="Bingus";
  arv[2]="Testing_exevpl.c";
  arv[3]="\0";

  if (execvp("ls", arv) == -1)
    printf("ERROR\n %s", (char *)strerror(errno));
  return EXIT_SUCCESS;
}
