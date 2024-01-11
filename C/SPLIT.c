#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define fill(...) fill_handle((fill_args){__VA_ARGS__})
#define split(...) split_handle((split_args){__VA_ARGS__})
typedef struct{
  char* strin;
  char fillchar;
  int len;
}fill_args;

typedef struct{
  char* strin;
  char sep;
}split_args;

int wier_wrds_count(char strin[],char sep){
int words=(int)(strin[strlen(strin)-1]!=sep);
 bool isrep=0;
    for(int i=0;strin[i]!='\0';i++){
        if(strin[i]==sep){
           if(isrep) words++;
           isrep=0;
            continue;
        }
        isrep=1;
    }
return words;
}


char* fill_base(char* b, char a, int len){
for(int i=0;i<len;i++){
    *(b+i)=a;
}
return b;
}

char* fill_handle(fill_args in){
   char a=in.fillchar?in.fillchar:'\0';
   int len=in.len?in.len:1;
   char *s =in.strin ?in.strin:(char*)malloc((len+1)*sizeof(char));
   return fill_base(s,a,len);
}

char** slightlyLessShitSplit(char strin[], char sep){
   int magi=strlen(strin)+2;
    bool fix=strin[strlen(strin)]!=sep;
    char **out=(char**)calloc(magi,sizeof(char*));
    int j=0;int l=0;
    *out=fill(.len=magi);
    for(int i=0;strin[i]!='\0';i++){
        if (strin[i]==sep){
            //out[j]=realloc(out[j],sizeof(char)*(l+2));
            if(l!=0){out[j][l]='\0';j++;}
            magi+=-l-1;
            //else{free(out[j]);}
            l=0;
       
            out[j]=fill(.len=magi);
            //printf("j= %d\n",j);
            continue;
        }
        out[j][l]=strin[i];
        //printf("l=%d c=%c\n",l,strin[i]);
        l++;
    }
out[j+fix]=fill(0);
    return out;
}


char** split_base(char strin[], char sep){
int i=0;
int l=0;
for (i=0;strin[i]!='\0';i++){
    if (strin[i]==sep)
        l++;
}
l+=strin[i-1]==sep?0:1;
char ** out=(char*) malloc(l*sizeof(char*)+sizeof(int))+sizeof(char);
*out=l;
*(out+l+1)='\0';
printf("%d %d",l,i);
}
char** split_handle(split_args in){
char sep=in.sep?sep:' ';
return slightlyLessShitSplit(in.strin,sep);
}

int main(){
char* s="I am innocent and lord unbroken";
split_base(s,' ');

}
/*
char** shit=split(.strin=s);
for(char**i=shit;**i!='\0';i++){
    printf("%s\n",*i);
}
free(shit);
    int fix=strin[strlen(strin)-1]==sep;
    int len=wier_wrds_count(strin,sep);
    char** out=(char**)malloc(sizeof(char*)*len+fix);
    //if(fix){out[len]=(char*)malloc(sizeof(char));out[len][0]=sep;}
    int l=0; char** j=out;
    for(char* i=strin;*i!='\0';i++){
        if(*i==sep){*j=fill(.len=l);l=0;j++;continue;}
        l++;
    }
    return out;
*/
