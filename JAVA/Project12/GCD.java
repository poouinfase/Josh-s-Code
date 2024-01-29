import java.util.*;
public class GCD 
{  
void main(){
Scanner sc= new Scanner(System.in);   
int len=sc.nextInt();//Number of Operands
int out=sc.nextInt();
for(int i=0;i<len-1;i++){
out=gdc(out,sc.nextInt());//Find gcd of previus gcd and current number
}
System.out.println(out);
    }
public static int gdc(int n1,int n2)   
{  
while(n1!=n2)   //if equal n1,n2 is gcd
{  
if(n1>n2)  
n1=n1-n2;  
else  
n2=n2-n1;  
}  
return n2;  
}  
} 