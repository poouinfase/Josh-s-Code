import java.util.*;
public class Atomint
{
    int ato[]; int sign=1;
   Atomint(String s){
    ato=new int[s.length()];
       if(s.charAt(s.length()-1)=='-'){
    sign=-1;s=s.substring(0,s.length()-1);}
    else
    sign=+1;
    for(int i=0;i<s.length();i++)
    ato[i]=(int)s.charAt(i)-(int)'0';
    }
   Atomint(){
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        if(s.charAt(s.length()-1)=='-'){
    sign=-1;s=s.substring(0,s.length()-1);}
    else
    sign=+1;
        ato=new int[s.length()];
    for(int i=0;i<s.length();i++)
    ato[i]=(int)s.charAt(i)-(int)'0';
    }
    void setato(int [] b){
    this.ato=b; carryshift();
    }
    void carryshift(){
    for (int i=0;i<ato.length-1;i++){
    ato[i+1]+=ato[i]/10;
    ato[i]=ato[i]%10;
    }
    }  
    int [] carryshift(int a[]){
    for (int i=0;i<a.length-1;i++){
    a[i+1]+=a[i]/10;
    a[i]=a[i]%10;
    }
    return a;
    }
   public Atomint add(Atomint a)
   {
       int l= Math.max(a.ato.length,this.ato.length);
       int ao[]=new int[l+1];
       for(int i=0;i<=l;i++){
        ao[i]=(i>=this.ato.length)?0:(this.ato[i]*this.sign)+ ((i>=a.ato.length)?0:(a.ato[i]*a.sign));
        }
       setato(ao);
       return this;
}
   public Atomint add(int [] a)
   {
       int l= Math.max(a.length,this.ato.length);
       int ao[]=new int[l+1];
       for(int i=l-1;i>=0;i--){
        ao[i]=(i>this.ato.length)?0:this.ato[i]*this.sign + ((i>a.length)?0:a[i]);
        }
       setato(ao);
       carryshift();
       return this;
}
void setsign(int a){sign= a>=0?1:-1;}
public Atomint multiply(Atomint a){
   int sina=a.sign;
   int sinthis=this.sign;
   this.setsign(1);
   a.setsign(1);
for (int i = 0 ; i< a.ato.length;i++){
    int temp[]=new int [a.ato.length+i];
    int k=0;
    for(int j=i;j<i+a.ato.length;j++)
    temp[j]=a.ato[k++];
for(int j=0;j<temp.length;j++) temp[j]*=a.ato[i];
this.add(temp);
}
   a.setsign(sina);
   this.setsign(sinthis*sina);
 return this;
}
public void disp(){
for(int i=ato.length-1;i>=0;i--)
System.out.print(ato[i]);
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

public static void main (String args[]){
Atomint a=new Atomint(rev("32000"));
Atomint b=new Atomint(rev("9000"));
a.disp();System.out.println("");
b.disp();System.out.println("");
a.add(b);
a.disp();
}
}