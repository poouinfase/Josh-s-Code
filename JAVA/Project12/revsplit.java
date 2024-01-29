import java.util.*;
public class revsplit
{
    String s;
    String [] separ(String str){
    int coun=1;
    for(int i=0;i<str.length();i++){
        if(str.charAt(i)==' ') coun++;
        }
    String out []=new String[coun];int k=0;
    for(int i=0;i<coun;i++)
    out[i]="";
    for(int i=0;i<str.length();i++){
    if(str.charAt(i)==' '){
        k++;if(k==out.length)break;continue;
    }
    out[k]=out[k]+str.charAt(i);
     }   
    for(int i=0;i<coun;i++)
    out[i]=rev(out[i]);
    return out;
    }
    public static String rev(String str){
    char ch=' '; String nstr=""; 
      for (int i=0; i<str.length(); i++)
      {
        ch= str.charAt(i); //extracts each character
        nstr= ch+nstr; //adds each character in front of the existing string
      }
      return nstr;
    }
    public static void disp(String in[]){
    for(int i=0;i<in.length;i++){
    System.out.print(in[i]+" ");
    }
    }
    void main(){
    Scanner sc=new Scanner(System.in);
    disp(separ(sc.nextLine()));
    }
}

