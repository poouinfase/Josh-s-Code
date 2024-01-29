// to input the isbn of a book and check if it is valid
import java.util.*;
public class Isbn
{
public static void main(String args[])
{

Scanner sc = new Scanner(System.in); 
System.out.print("Enter ISBN: ");
String s=sc.nextLine(); //input
int sleng=s.length();
if(sleng==10)
{
char ch;
int d=0, sum=0, k=10;
for(int i=0; i<sleng; i++)
{
ch=s.charAt(i);
if(ch=='X')
 d=10;
else
 d=ch-48;
sum=sum+d*k;
k--;
}
//verification formula is standard
//generate the sumto verify isbn
System.out.println("Out = "+sum);
if(sum%11==0)
System.out.println("Valid Code");
else
System.out.println("Invalid Code");
}
else
System.out.println("Invalid Code");
//output
}
//end
}