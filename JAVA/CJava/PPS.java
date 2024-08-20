import java.util.*;

class PPS {

  public static void Q1() {
    Scanner sc = new Scanner(System.in);
    float principal, rate;
    int year = 0;
    principal = sc.nextFloat();
    rate = sc.nextFloat();
    year = sc.nextInt();

    float interest = principal * rate * year;
    System.out.printf("Simple interes is Rs. %.2f", interest);
    sc.close();
  }

  // test sre
  public static void Q2() {
    Scanner sc = new Scanner(System.in);
    int mark = sc.nextInt();
    sc.close();
    if (mark >= 90) {
      System.out.println("S");
      return;
    }
    if (mark >= 80) {
      System.out.println("A");
      return;
    }
    if (mark >= 70) {
      System.out.println("B");
      return;
    }
    if (mark >= 60) {
      System.out.println("C");
      return;
    }
    if (mark >= 50) {
      System.out.println("D");
      return;
    }
    if (mark < 50) {
      System.out.println("E");
      return;
    }
  }

  public static void Q3() {
    Scanner sc = new Scanner(System.in);
    int day = sc.nextInt();
    String days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", };
    System.out.println(days[day % days.length]);
    sc.close();
  }

  public static void Q4() {
    Scanner sc = new Scanner(System.in);
    float basicPay = sc.nextFloat();
    float salary = basicPay * 1.98f;
    System.out.printf("Salary is Rs %.2f", salary);
    sc.close();
  }

  public static void Q5() {
    int avg1 = 39;
    int n1 = 14;
    int avg2 = 31;
    int n2 = 12;
    int total = avg1 * n1 + avg2 * n2;
    float average = (float) total / (float) (n1 + n2);
    System.out.printf("Average is %f", average);
  }

  public static void Q6() {
    Scanner sc = new Scanner(System.in);
    int mark = sc.nextInt();
    sc.close();
    if (100 >= mark && mark > 90) {
      System.out.println("S");
      return;
    }
    if (mark > 80) {
      System.out.println("A");
      return;
    }
    if (mark > 60) {
      System.out.println("B");
      return;
    }
    if (mark >= 40) {
      System.out.println("E");
      return;
    } else {
      System.out.println("Invalid Mark Entry");
      return;
    }
  }

  public static void Q7() {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter Option");
    int ch = sc.nextInt();
    System.out.println("Enter the Number");
    int n = sc.nextInt();
    switch (ch) {
      case 1:
        System.out.println(Opt1(n));
        break;

      case 2:
        System.out.println(Opt2(n));
        break;

      case 3:
        System.out.println(Opt3(n));
        break;

      case 4:
        System.out.println(Opt4(n));
        break;

      default:
        break;
    }
    sc.close();
  }

  public static int Opt1(int n) {
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }

  public static int Opt2(int n) {
    int rev = 0;
    while (n > 0) {
      rev = rev * 10 + n % 10;
      n /= 10;
    }
    return rev;

  }

  public static int Opt3(int n) {
    int fir = n % 10;
    int las = n % 10;
    n /= 10;
    while (n > 10) {
      las = n % 10;
    }
    return las + fir;
  }

  public static String Opt4(int n) {
    int odd = 0, even = 0;
    while (n > 0) {
      odd += (n % 10) % 2;
      even += (n % 10 + 1) % 2;
      n /= 10;
    }
    return Integer.toString(odd) + " " + Integer.toString(even);
  }

  public static void Q8() {
    Scanner sc = new Scanner(System.in);
    int len = sc.nextInt();
    int max = sc.nextInt();
    int min = max;
    for (int i = 1; i < len; i++) {
      int inp = sc.nextInt();
      if (inp < min)
        min = inp;
      if (inp > max)
        max = inp;
    }
    System.out.printf("Max is %d, Min is %d", max, min);
    sc.close();
  }

  public static void Q9() {
    Scanner sc = new Scanner(System.in);
    int len = sc.nextInt();
    int arr[] = new int[len];

    for (int i = 0; i < len; i++) {
      int inp = sc.nextInt();
      if (inp % 5 == 0) {
        len--;
        i--;
        continue;
      }
      arr[i] = inp;
    }
    for (int i = 0; i < len; i++) {
      System.out.println(arr[i]);
    }
    sc.close();
  }

  public static void Q10() {
    int Pop = 9870;
    float rateGrowth = 1.1f;
    int year = 0;
    System.out.printf("Year: %d Population: %d\n", 0, Pop);
    while (30_000 > Pop) {
      year++;
      Pop *= rateGrowth;
      System.out.printf("Year: %d Population: %d\n", year, Pop);
    }
    System.out.printf("%d years to exceed 30,000\n", year);
  }

  public static void Q11() {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter Registration number");
    String reg = sc.nextLine();

    switch (reg.charAt(0)) {
      case '1':
        System.out.println("First Year");
        break;

      case '2':
        System.out.println("Second Year");
        break;

      case '3':
        System.out.println("Third Year");
        break;

      case '4':
        System.out.println("Final Year");
        break;

      default:
        System.out.println("Year not available");
        break;
    }
    if (reg.charAt(2) == 'B')
      System.out.println("Welcome to Computer Science and Engineering School ");
    else
      System.out.println("You are not from Computer Science and Engineering School");
    sc.close();
  }

  public static Student Q12Max(Student[] arr) {
    int max = 0;
    for (int i = 1; i < arr.length; i++) {
      if (arr[i].average > arr[max].average)
        max = i;
    }
    return arr[max];
  }

  public static void Q12() {
    Student arr[] = new Student[5];
    for (int i = 0; i < 5; i++) {
      arr[i] = new Student();
      arr[i].input();
    }

    Student max = Q12Max(arr);
    System.out.printf("Highest: %.2f by Roll: %s\n", max.average, max.regNo);

    for (int i = 0; i < 5; i++) {
      if (!arr[i].hasFailed())
        continue;
      System.out.printf("Roll: %s Failed\n", arr[i].regNo);
    }
  }

  public static void Q13() {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter dimensions of matrix");
    int n = sc.nextInt();
    int m = sc.nextInt();
    int matrix[][] = new int[n][m];

    System.out.println("Enter elements of matrix");
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[i].length; j++) {
        matrix[i][j] = sc.nextInt();
      }
    }

    System.out.println("Enter target of matrix");
    int target = sc.nextInt();
    sc.close();
    System.out.println("Element found at: " + findElement(matrix, target));

  }

  public static Coordinate findElement(int[][] matrix, int target) {
    Coordinate out = new Coordinate();
    for (int i = 0; i < matrix.length; i++) {
      for (int j = 0; j < matrix[i].length; j++) {
        if (matrix[i][j] == target) {
          out.x = i;
          out.y = j;
          return out;
        }
      }
    }
    return out;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int ch = sc.nextInt();
    System.out.println("Enter choice [1-13]");
    switch (ch) {
      case 1:
        Q1();
        break;

      case 2:
        Q2();
        break;

      case 3:
        Q3();
        break;

      case 4:
        Q4();
        break;

      case 5:
        Q5();
        break;

      case 6:
        Q6();
        break;

      case 7:
        Q7();
        break;

      case 8:
        Q8();
        break;

      case 9:
        Q9();
        break;

      case 10:
        Q10();
        break;

      case 11:
        Q11();
        break;

      case 12:
        Q12();
        break;

      case 13:
        Q13();
        break;

      default:
        System.out.println("Not a valid choice");
        break;
    }
    sc.close();
  }

}

class Student {
  private int n1;
  private int n2;
  private int n3;
  private int n4;
  private int n5;

  public float average;
  public String regNo;

  public void input() {
    Scanner sc = new Scanner(System.in);
    System.out.print("Registration No: ");
    this.regNo = sc.next();

    System.out.println("Enter marks for five subjects");
    this.n1 = sc.nextInt();
    this.n2 = sc.nextInt();
    this.n3 = sc.nextInt();
    this.n4 = sc.nextInt();
    this.n5 = sc.nextInt();

    this.average = (this.n1 + this.n2 + this.n3 + this.n4 + this.n5) / 5f;
  }

  public boolean hasFailed() {
    return this.average < 40;
  }
}

class Coordinate {
  public int x = -1;
  public int y = -1;

  public String toString() {
    return "(" + x + ", " + y + ")";
  }
}
