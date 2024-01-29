import java.util.*;
class Matrixtranspose{
int x,y;
int a[][];
Matrixtranspose(int m,int n){
x=m;y=n;
a=new int[x][y];
Scanner sc= new Scanner(System.in);
for(int i=0;i<y;i++){
for(int j=0;j<x;j++)
a[j][i]=sc.nextInt();
}
}
public void rotato(){
int m=0;int n=y-1;int swap=0;
while(m<x){
    n=y-1;
while(n>=0){
a[y-n-1][m]=a[m][n];
n--;
}
m++;
}
}
public void show(){
for(int i=0;i<y;i++){
for(int j=0;j<x;j++)
System.out.print(a[j][i]);
System.out.println();
}
}
public static void main(String[]args){
Scanner sc= new Scanner(System.in);
    Matrixtranspose a=new Matrixtranspose(sc.nextInt(),sc.nextInt());
a.rotato();a.show();
}
}
