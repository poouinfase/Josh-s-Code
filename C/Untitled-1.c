#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define bool unsigned short int
#define true 1
#define false 0


void Q1(){
char* strin[]={"a","b","c","d","e","f","g","h","i","j"};
char* num[]={"1","2","3","4","5","6","7","8","9","10"};
int numarr=0;
int strinarr=0;
int i=0;
char* s[5][5];
for(int col=0;col<5;col++){
    for(int row=0;row<5;row++){
        if(row>i){
            s[row][col]=num[numarr++];
        }
        if(row<i){
            s[row][col]=strin[strinarr++];
        }
        if(row==i)
        s[row][col]="0";
    }
    i++;
}

for(int col=0;col<5;col++){
    for(int row=0;row<5;row++){
        printf("%s\t",s[row][col]);
    }
    printf("\n");
}
}

float Q2(){
float fan=0.0;
float lig=0.0;
scanf("%f\n%f",&lig,&fan);
float disfan=0.0;
float dislights=5/100;
float sum=fan+lig;
if( sum>500 && sum<=1000){
disfan=5.0/100.0;
dislights=10.0/100.0;
}
else if (1000<sum && sum<=5000)
{
disfan=10.0/100.0;
dislights=15.0/100.0;
}
else{
    disfan=15.0/100.0;
    dislights=25.0/100.0;
    }

float out=(fan*disfan)+(lig*dislights);
return sum-out;

}


int main(){
    //Q1();
    printf("%f ",Q2());
    return 0;
}