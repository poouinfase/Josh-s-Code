import java.util.*;  
public class Autobio
{  
public static void main(String args[])   
{  
Scanner sc=new Scanner(System.in);  
System.out.print("Enter the number you want to check: ");  
int num = sc.nextInt();      
int n = num;    
String str = String.valueOf(num);  
int a[] = new int[str.length()];  
for(int i = a.length - 1; i >= 0; i--)  
{      
a[i] = n % 10;   
n = n/10;  
}  
boolean isbool = true;  
for(int i = 0; i < a.length; i++)  
{  
int coun = 0;  
for(int j = 0; j < a.length; j++)  
{  
if(i == a[j])  
coun++;  
}  
if(coun != a[i])  
{  
isbool = false;  
break;  
}  
}  
if(isbool)  
System.out.println(num + " is an autobiographical number.");  
else  
System.out.println(num + " is not an autobiographical number.");  
}  
}  