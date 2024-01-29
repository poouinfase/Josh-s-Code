import java.util.*;
//To take a random word and play hangman
class Hangman{
    String word;
    boolean hit;
    char[] out;
    int lives,con;
    Hangman(){        
        hit=false;
      con=0;
        String[] wordbank={"foxglove","frazzled","frizzled","fuchsia","funny","gabby","galaxy","galvanize","gazebo","giaour","gizmo","glowworm","glyph","gnarly","gnostic","gossip","grogginess","haiku","haphazard","hyphen","iatrogenic","icebox","injury","ivory","ivy","jackpot","jaundice","jawbreaker","jaywalk","jazziest","jazzy","jelly","jigsaw","jinx","jiujitsu","jockey","jogging","joking","jovial","joyful","juicy","jukebox","jumbo","kayak","kazoo","keyhole","khaki","kilobyte","kiosk","kitsch","kiwifruit","klutz","knapsack","larynx","lengths","lucky","luxury","lymph","marquis","matrix","megahertz","microwave","mnemonic","mystify","naphtha","nightclub","nowadays","numbskull","nymph","onyx","ovary","oxidize","oxygen","pajama","peekaboo","phlegm","pixel","pizazz","pneumonia","polka","pshaw","psyche","puppy","puzzling","quartz","queue","quips","quixotic","quiz","quizzes","quorum","razzmatazz","rhubarb","rhythm","rickshaw","schnapps","scratch","shiv","snazzy","sphinx","spritz","squawk","staff","strength","strengths","stretch","stronghold","stymied","subway","swivel","syndrome","thriftless","thumbscrew","topaz","transcript","transgress","transplant","triphthong","twelfth","twelfths","unknown","unworthy","unzip","uptown","vaporize","vixen","vodka","voodoo","vortex","voyeurism","walkway","waltz","wave","wavy","waxy","wellspring","wheezy","whiskey","whizzing","whomever","wimpy","witchcraft","wizard","woozy","wristwatch","wyvern","xylophone","yachtsman","yippee","yoked","youthful","yummy","zephyr","zigzag","zigzagging","zilch","zipper","zodiac","zombie"};
    //all words of the wordbank
    int a=(int)((int)100*Math.random())%213;//random word is chosen
    word=wordbank[a];
    out=new char[word.length()];//the word that is printed
    for(int i=0;i<word.length();i++){
    out[i]='_';//to print uknown letters
    }
    lives=6;///lives

    }
    public static void main (String[] args){
        Scanner sc=new Scanner(System.in);
       Hangman h=new Hangman();
        h.calculater();
    while(h.lives>0&&h.con!=h.word.length()){
    h.display();
    System.out.println("\n Guess");
    char a=sc.next().charAt(0);
    h.calculate(a);
    }
    if(h.lives==0){
        displayLives(0);
        System.out.println("The word was "+h.word);
        
    }
    if(h.con==h.word.length())
    System.out.println("Correct");
    }
    void calculate(char guess){
    for(int i=0;i<word.length();i++){
    if(guess==word.charAt(i)){
        out[i]=guess;
        hit=true;con++;
    }
    }
    if(hit==false){
    lives--;//if incorrect lives are lost
    }
    hit=false;//hit is reset
    }
   void calculater(){
       //to show vowels
    for(int j=0;j<5;j++){
        char gues[]={'a','e','i','o','u'};
    for(int i=0;i<word.length();i++){
    if(gues[j]==word.charAt(i)){
        out[i]=gues[j];
        con++;
    }
    }
         }
         }
public static void displayLives(int a){
if(a==6){
    System.out.println(""); 
System.out.println("  +---+");
System.out.println("  |   |");
System.out.println("      |");
System.out.println("      |");
System.out.println("      |");
System.out.println("      |");
System.out.println("=========''', '''");
}
if(a==5){
    System.out.println(""); 
System.out.println("  +---+");
System.out.println("  |   |");
System.out.println("  O   |");
System.out.println("      |");
System.out.println("      |");
System.out.println("      |");
System.out.println("=========''', '''");
}
if(a==4){
    System.out.println(""); 
System.out.println("  +---+");
System.out.println("  |   |");
System.out.println("  O   |");
System.out.println("  |   |");
System.out.println("      |");
System.out.println("      |");
System.out.println("=========''', '''");
}
if(a==3){
    System.out.println(""); 
System.out.println("  +---+");
System.out.println("  |   |");
System.out.println("  O   |");
System.out.println(" /|   |");
System.out.println("      |");
System.out.println("      |");
System.out.println("=========''', '''");
}
if(a==2){
    System.out.println(""); 
System.out.println("  +---+");
System.out.println("  |   |");
System.out.println("  O   |");
System.out.println(" /|\\  |");
System.out.println("      |");
System.out.println("      |");
System.out.println("=========''', '''");
}
if(a==1){
    System.out.println(""); 
System.out.println("  +---+");
System.out.println("  |   |");
System.out.println("  O   |");
System.out.println(" /|\\  |");
System.out.println(" /    |");
System.out.println("      |");
System.out.println("=========''', '''");
}
if(a==0){
System.out.println("");    
System.out.println("  +---+");
System.out.println("  |   |");
System.out.println("  O   |");
System.out.println(" /|\\  |");
System.out.println(" / \\  |");
System.out.println("      |");
System.out.println("=========''']");
}
}
    void display(){
        System.out.println("Number of lives left "+lives);
        displayLives(lives);
        for(int i=0;i<word.length();i++){
    System.out.print(out[i]);
    }
    }
    
}