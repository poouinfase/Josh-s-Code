#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define fill(...) fill_handle((f_args){__VA_ARGS__})
typedef struct{
char* strin;
char fillchar;
int len;
}f_args;
char* fill_base(char* b, char a, int len){
for(int i=0;i<len;i++){
    *(b+i)=a;
}
return b;
}
char* fill_handle(f_args in){
   char a=in.fillchar?in.fillchar:'\0';
   int len=in.len?in.len:1;
   char *s =in.strin ?in.strin:(char*)malloc((len+1)*sizeof(char));
   return fill_base(s,a,len);
}
int main(){
    int l;
    char A;
    scanf("%d %c",&l,&A);
    char *s=fill(.fillchar=A,.len=l);
    *(s+l)='\0';
    for(char* i=s;*i!='\0';i++){
        printf("%c",*i);
    }
    return 0;
    free(s);
}
