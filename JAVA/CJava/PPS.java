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

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int ch = sc.nextInt();
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

      default:
        System.out.println("Not a valid choice");
        break;
    }
    sc.close();
  }

}
