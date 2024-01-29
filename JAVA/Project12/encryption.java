import java.util.*;
public class encryption
{
    String key;
    String arr[];
    private long trukey;//used to contiain actual key generated from key
    encryption(){
        Scanner sc=new Scanner(System.in);
        arr=sc.nextLine().split("");
        key=sc.nextLine();
}
void enc(){
        for(int i=0;i<key.length();i++)
        trukey=(int)key.charAt(i); //generate trukey
        for(int i=0;i<arr.length;i++){
        arr[i]= ((int)arr[i].charAt(0)* trukey) +"";//multiplies each characters ascii code with trukey
    }
    trukey=1;
}
void denc(String ke){
for(int i=0;i<ke.length();i++)
        trukey=(int)ke.charAt(i);//generate trukey
for(int i=0;i<arr.length;i++){
        arr[i]= (char) (Integer.parseInt(arr[i])/trukey) +"";
    }//divides each characters encrypted vallue by the newly generated trukey
}
void show(){
            for(int i=0;i<arr.length;i++){
        System.out.print(arr[i]);//displays the current word
    }
    System.out.println();
}
public static void main (String args[]){
encryption a= new encryption();
Scanner sc=new Scanner(System.in);
//System.out.println("Word before encryption");
//a.show();
a.enc();//encryption
System.out.println("Word after encryption");
a.show();
System.out.println("Give decryption key");
a.denc(sc.nextLine());//give correct key
System.out.println("Decrypted word");
a.show();
}
}