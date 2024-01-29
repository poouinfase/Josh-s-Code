import java.util.*;
public class pueue
{ int a[]; int r,f,l;
pueue( int len){
a= new int[len];f=-1;r=-1;l=len;
}
int deque(){
    if(f==r){
        int temp=a[f];
        f=0;r=0;
    return temp;
}
return this.a[f++];
}
void queue(int in){
    if(f==l-1){System.out.println("Queue Full");return;}
 if(f==-1){
     r=0;f=0;
}
if(f==r){f=0;a[f]=a[r];r=0;}
a[r]=in;
r++;
}
void display(){
for(int i=f;i<r;i++)
System.out.print(a[i]+" ");
}
}