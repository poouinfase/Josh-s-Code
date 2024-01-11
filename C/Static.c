#include <stdlib.h>
#include <stdio.h>
#include <immintrin.h>
int b(){
    int i=0;
    int c= _rdseed32_step(&i);
    return i;
}
int main(){
for (int i=0;i<10;i++)
printf("%d\n",b());
return 0;
}