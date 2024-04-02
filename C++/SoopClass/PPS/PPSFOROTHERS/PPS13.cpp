#include <iostream>

class Square {
public:
  float a;
  Square() { std::cin >> a; }
  float area() { return a * a; }
  float perimeter() { return 4 * a; }
  void out() { std::cout << area() << perimeter() << '\n'; }
};

class Cube : public Square {

public:
  Cube() {}
  float area() { return a * a * a; }
  float perimeter() { return 6 * a * a; }
  void out() { std::cout << area() << perimeter() << '\n'; }
};

class Cuboid : public Cube {

public:
  float l, b;
  Cuboid() { std::cin >> l >> b; }
  float area() { return l * b * a; }
  float perimeter() { return 2 * (l * b + l * a + b * a); }
  void out() { std::cout << area() << perimeter() << '\n'; }
};

int main() {
  Square a;
  Cube b;
  Cuboid c;
  a.out();
  b.out();
  c.out();
}
