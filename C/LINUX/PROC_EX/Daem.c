#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define REP_LIM 5
int main(void)
{
  daemon(0,0);
  int i=REP_LIM;
  while(i){
    i+=-1;
    sleep(1);
  }
  exit(EXIT_SUCCESS);
}

