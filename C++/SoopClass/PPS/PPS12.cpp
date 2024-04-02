#include <iostream>

class circle {
protected:
  float r;
  static constexpr float pi = 3.14;

public:
  circle();
  float are();
  float vol();
  float dia();
  void in();
  void out();
};

circle::circle() { in(); }
void circle::out() {
  std::cout << "Diameter= " << dia() << std::endl
            << "Area= " << are() << std::endl
            << "Circumference= " << vol() << std::endl;
}
void circle::in() { std::cin >> r; }
float circle::are() { return pi * r * r; }
float circle::vol() { return pi * r * 2; }
float circle::dia() { return r * 2; }

class sphere : public circle {

public:
  float are() { return 4 * pi * r * r; }
  float vol() { return (4.0 / 3.0) * pi * r * r * r; }
  void out() {
    circle::out();
    std::cout << "Surface Area= " << are() << std::endl
              << "Volume = " << vol() << std::endl;
  }
};

int main() { sphere().out(); }
