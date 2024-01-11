#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  pid_t pid = fork();

  if(pid == -1){
    printf("Error\n");
    exit(0);
  }

  if(pid){
    printf("I AM THE FATHER %d\n", getpid());
    wait(NULL);
    exit(0);
  }

  if(pid == 0){
    printf("I AM THE CHILD: %d\nTHIS IS MY FATHER: %d\n",getpid(),getppid());
    exit(0);
  }
}
