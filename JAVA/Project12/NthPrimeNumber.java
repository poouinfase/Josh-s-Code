import java.util.ArrayList;  
public class NthPrimeNumber  
{  
static int MAX_SIZE = 1000005;   
static ArrayList<Integer> primelist = new ArrayList<Integer>();   
static void findnthPrimeNumber()   
{    
boolean [] IsPrime = new boolean[MAX_SIZE];   
for(int i = 0; i < MAX_SIZE; i++)  
IsPrime[i] = true;  
for (int p = 2; p * p < MAX_SIZE; p++)   
{     
if (IsPrime[p] == true)   
{     
for (int i = p * p; i < MAX_SIZE; i += p)   
IsPrime[i] = false;   
}   
}   
for (int p = 2; p < MAX_SIZE; p++)   
if (IsPrime[p] == true)     
primelist.add(p);  
}   
public static void main (String args[])   
{   
findnthPrimeNumber();  
System.out.println("7th prime number is " + primelist.get(6));  
System.out.println("22nd prime number is " + primelist.get(21));  
System.out.println("10000th prime number is " + primelist.get(9999));  
}  
}   