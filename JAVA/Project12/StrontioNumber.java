import java.util.*;  
public class StrontioNumber  
{  
public static void main(String args[])   
{  
Scanner sc=new Scanner(System.in);  
System.out.print("Enter the Range: ");
int s=sc.nextInt();int en=sc.nextInt();   
for(int i=s;i<=en;i++){   
int num=(i*2%1000)/10;     
if(num%10==num/10)   
System.out.println(i+ " is a strontio number.");  
else   
System.out.println(i+ " is not a strontio number.");  
}  
}  
}