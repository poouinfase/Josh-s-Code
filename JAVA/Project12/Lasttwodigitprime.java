import java.util.*;
class Lasttwodigitprime{
public static boolean prime(int a){
    int ldig=a%100;//extracts last two digits of a
    int count=0; //Number of factors
    for (int j=1;j<=ldig;j++){
    if(ldig%j==0) count++;//Counts Factors
    }
    return count==2;//Determines if the last two digits a  is prime
    }
public static void main(String[] args){
Scanner sc= new Scanner(System.in);
 int m=sc.nextInt(),n=sc.nextInt(),count=0;//m and n are the range of numbers
 if(m<n){
 int primnum[]=new int [n-m+3];//this is the array of all unique numbers between n and m
 for (int i=m;i<=n;i++){ 
 if(prime(i)){
     primnum[count]=i;
     count++;
 }
}
if(count>0){
System.out.print("The numbers are "+primnum[0]); //outputs the start of the statement and the first number
for(int j=1;j<count;j++){
System.out.print(","+primnum[j]);//outputs all remaining numbers;
}
}
else{
System.out.println("No numbers found");
}
System.out.println();System.out.println("Frequency: "+count);
}
else{
    System.out.println("Invalid range");
}
}
}
