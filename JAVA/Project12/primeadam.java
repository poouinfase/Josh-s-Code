//Finds numbers that are prime numbers and adam nubers
import java.util.*;
public class primeadam
{
   static int rev(int a){
    int r=0;
       while(a>0){
           r=(r*10)+a%10;
           a/=10;
    }
    //reverses the number a
    //System.out.println(r); //used for debugging
    return r;
    } 
   static boolean adam(int a){
    int d=rev(a);
     return (a*a==d*d);//checks if square of number is equal to square of the reverses
    }
   static boolean prime(int a){
    int count =0;
    for(int i=1;i<=a;i++){
    if(a%i==0)
    count++;
    }
    //counts factors
    return count==2;//checks if prime
    }
     public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the value of m: ");
        int m = in.nextInt();//input begining of range
        System.out.print("Enter the value of n: ");
        int n = in.nextInt();//input endingof range
        int count = 0;  
        if (m >= n) {
            System.out.println("Invalid");
            return;
        }      
        System.out.println("The Prime Adam Integers: ");
        for (int i = m; i <= n; i++) {
                if (prime(i)&&adam(i)) {
                    System.out.print(i + " ");
                    count++;
                    //check of prime adam
}  
}
System.out.println("\n Count = "+count);
}
}