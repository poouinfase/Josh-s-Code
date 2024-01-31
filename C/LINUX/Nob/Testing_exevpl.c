#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(int argc, char * argv[]) {
  char **arv;
  arv=(char**)malloc(3*sizeof(char*));
  // *(arv+1)="--rec";
  *(arv+0)="../../..";
  if(execvp("ls",arv)==-1)printf("ERROR\n %s",(char*)strerror(errno));
  free(arv);
  return EXIT_SUCCESS;
}
