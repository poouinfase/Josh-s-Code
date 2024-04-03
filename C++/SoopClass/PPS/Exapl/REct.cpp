#ifdef DEBUG

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
#else
#include <iostream>

using namespace std;
class Rectangle {
  int length, width;

public:
  int Area, Perimeter;
  void getdata() {
    cout << "length =";
    cin >> length;
    cout << " width = ";
    cin >> width;
  }
  float getArea() {
    if (length > 0 && width > 0) {
      Area = length * width;
      return Area;
    } else {
      cout << "Area = Invalid" << endl;
      return -1;
    }
  }
  float getPerimeter() {
    if (length > 0 && width > 0) {
      Perimeter = 2 * (length + width);
      return Perimeter;
    } else {
      cout << "Perimeter = Invalid" << endl;
      return -1;
    }
  }
};
int main() {
  Rectangle aa;
  aa.getdata();
  cout << "Area is " << aa.getArea() << endl;
  cout << "Perimeter is " << aa.getPerimeter();
  return 0;
}
#endif // DEBUG
