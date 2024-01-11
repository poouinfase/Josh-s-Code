#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
  close(0);close(1);close(2);
  int fd = open("Bingus.txt",O_RDWR|O_APPEND);
  dup(fd);dup(fd);
  int a,b;
  scanf("%d %d",&a,&b);
  printf("%d\n",a+b);
}
