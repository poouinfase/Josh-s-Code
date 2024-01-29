import java.util.*;
class vertistring{
    String word[];
    int leng;
    int arrleng;
public static char outchar(String s,int n){
    if(n>s.length () || n==s.length())
    return '.';
    
    return s.charAt(n);
    }
public void input(){
Scanner sc=new Scanner(System.in);
arrleng=sc.nextInt()+1;
if(arrleng>2&& arrleng<=10){
word = new String [arrleng];
for(int i=0;i<arrleng;i++){
word[i]=sc.nextLine();
if(leng < word[i].length())
leng=word[i].length();
}
}
else{
    System.out.println("Error invalid array length");
}
    }
public void display (){
    if(arrleng>2 && arrleng<=10){
for(int i=0;i<leng;i++){
for(int j=1;j<arrleng;j++){
System.out.print(outchar(word[j],i));
System.out.print("\t");
}
System.out.println("");
}
}
}
public static void main (String[] args){
vertistring worker=new vertistring();
worker.input();
worker.display();
}
}
