#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  pid_t pid = fork();
    if (!pid){
    printf("I am parent: %d\n",getpid());
    sleep(10);
    printf("PARENT Exit\n");
    exit(0);
  }
    printf("I am child: %d\n",getpid());
    printf("CHILD Exit\n");
    exit(0);
}
