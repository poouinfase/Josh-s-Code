import java.util.*;
public class vowel_word_start
{
public static void printword(String s,int len){
while(len<s.length()&&s.charAt(len)!=' '){    
    System.out.print(s.charAt(len));
    len++;
    }
    System.out.println("");
}
   public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        String str =" "+ sc.nextLine().trim();
        int count=0;
        for(int i=0;i<str.length()-1;i++){
        if(str.charAt(i)==' '){
            if(str.charAt(i+1)=='A'){
                printword(str,i+1);
                count++;
        }
          if(str.charAt(i+1)=='E'){
                printword(str,i+1);
                count++;
        }
          if(str.charAt(i+1)=='I'){
                printword(str,i+1);
                count++;
        }
          if(str.charAt(i+1)=='O'){
                printword(str,i+1);
                count++;
        }
          if(str.charAt(i+1)=='U'){
                printword(str,i+1);
                count++;
        }
        }
}
System.out.println("Number of words ="+ count);
}
}
