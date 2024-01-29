import java.util.*;
public class squarematrixcalc
{
   int r, a[][],c[],diagn[][],sum;
   public void input (){
    Scanner sc = new Scanner(System.in);
    r= sc.nextInt();
    a= new int[r][r];
    diagn=new int [r][r];
    for (int i=0;i<r;i++){
    for(int j=0;j<r;j++){
    a[j][i]= sc.nextInt();
    diagn[i][j]=0;
    if(j==i)diagn[i][j]=a[i][j];
    if((j+i)==r-1)diagn[i][j]=a[i][j];
    }
    }
}
   public void sort(){
     int n = c.length;
     boolean chang=true;
        while(chang){
            chang=false;
            for (int j = 0; j < n-1; j++){
                if (c[j] > c[j+1]){
                    chang=true;
                    int temp = c[j];
                    c[j] = c[j+1];
                    c[j+1] = temp;
             }
            }
     }
}
public void calcsort(){
int coun=0;
c = new int [r*r];
coun=0;
for(int i=0;i<r;i++)
for(int j=0;j<r;j++){
c[coun]=a[i][j]; coun++;}
}
public void setter(){
  int coun=0;
for(int i=0;i<r;i++)
for(int j=0;j<r;j++){
a[i][j]=c[coun]; coun++;
}
}  
public void sumdiagnol(){
    for (int i=0;i<r;i++){
    for(int j=0;j<r;j++){
    diagn[i][j]=0;
    if(j==i)
    diagn[i][j]=a[j][i];
    if((j+i)==r-1)
    diagn[i][j]=a[j][i];
    }
    }
    sum=0;
    for (int i=0;i<r;i++){
    for(int j=0;j<r;j++){
    if(j==i)
    sum+=diagn[i][j];
    if(j+i==r-1)
    sum+=diagn[i][j];
    }
    }
    if(r%2!=0)
    sum-=a[(r+1)/2][(r+1)/2];
}
public void disp(String s){
System.out.println(s);
for (int i=0;i<r;i++){
for(int j=0;j<r;j++)
    System.out.print(a[j][i]+"\t");
System.out.println();
}
}
public void diagdisp(){
System.out.println("DIANGONAL ELEMENTS");
for (int i=0;i<r;i++){
    for(int j=0;j<r;j++)
    System.out.print((diagn[j][i]==0)?" \t":diagn[j][i]+"\t");
    System.out.println();
}
System.out.println("SUM OF THE DIANGONAL ELEMENTS="+ sum);
}
public static void main(String [] args){
squarematrixcalc worker =new squarematrixcalc();
worker.input();
worker.disp("ORIGINAL MATRIX");
worker.calcsort();
worker.sort();
worker.setter();
worker.sumdiagnol();
worker.disp("REARRANGED MATRIX");
worker.diagdisp();
}
}
