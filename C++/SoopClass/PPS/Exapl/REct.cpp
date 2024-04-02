#include <iostream>
using namespace std;
class Rectangle {
  int length, width;

public:
  int Area, Perimeter;
  void getdata() {
    cout << "length = ";
    cin >> length;
    cout << "width = ";
    cin >> width;
  }
  int calcArea() {
    if (length > 0 && width > 0) {
      return length * width;
    } else {
      cout << "Area = Invalid" << endl;
      return -1;
    }
  }
  int calcPerimeter() {
    if (length > 0 && width > 0) {
      return 2 * (length + width);
    } else {
      cout << "Perimeter = Invalid" << endl;
      return -1;
    }
  }

  void out() {
    cout << "Area = " << calcArea() << endl;
    cout << "Perimeter = " << calcPerimeter() << endl;
  }
};
int main() {
  Rectangle aa;
  aa.getdata();
  aa.out();
  return 0;
}
