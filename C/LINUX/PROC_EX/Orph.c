#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  pid_t pid = fork();
  
  if(pid){
    fprintf(stderr,"Gonna go get some milk\n");
    exit(0);
  }
  sleep(5);
    fprintf(stderr, "Dad?\n");
}
