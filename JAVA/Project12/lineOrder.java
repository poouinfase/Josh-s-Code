import java.util.*;
class lineOrder
{
    String sorg,s; boolean sentend; String a[];
lineOrder (){
   Scanner sc = new Scanner(System.in);
   s= sc.nextLine();
   char chk=s.charAt(s.length()-1);
   if (chk =='.' || chk =='?' || chk =='!' ){
       sentend= true;
    }
    sorg=s;
   a=new String[s.length()];
}
public void arrange(){
 ArrayList<String> temp = new ArrayList<String>(s.length());
for(int i=0;i<s.length()-1;i++){
temp.add(i,""+ s.charAt(i));
}
for(int i=0;i<s.length()-1;i++){
    int chgreater=0;
for(int j=0;j<s.length()-1;j++){
if(chgreater<temp.get(j).length()){
chgreater=j;
}
}
a[i]=temp.get(chgreater);
}
}
public void display(){
String fir= ""+sorg.charAt(0);
String o= fir.toUpperCase()+sorg.substring(1);
System.out.println(o);
fir= ""+s.charAt(0);
o= fir.toUpperCase()+s.substring(1);
System.out.println(o);
}
public void main(String [] args){
lineOrder a= new lineOrder();
if(sentend){
a.arrange();
a.display();
}    
else{System.out.println("Error no sentence terminator found");} 
}
}
