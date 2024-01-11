#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  pid_t pid = fork();
    if (!pid){
    printf("I am parent: %d\n",getpid());
    sleep(10);
    printf("Exit");
  }
  exit(0);
}
