#include <stdio.h>
int main(){
  char *s;
  if (!scanf("%[^\n]s",&s)){
    puts("ERROR");
    return 1;
  }
  puts(s);
  return 0;
}
