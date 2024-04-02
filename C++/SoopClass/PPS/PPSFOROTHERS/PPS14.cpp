#include <cmath>
#include <iostream>

class circle {
protected:
  float r;
  static constexpr float pi = 3.14;

public:
  circle() { std::cin >> r; }
  void out() { std::cout << area() << '\n' << vol() << '\n'; }
  float are() { return pi * r * r; }
  float vol() { return pi * r * 2; }
};

class cone : public circle {
protected:
  float l, h;

public:
  cone() { std::cin >> h; }

  float area() {
    l = sqrt(r * r + h * h);
    return pi * r * l;
  }
  float vol() { return (1.0 / 3.0) * pi * r * r * h; }
  void out() { std::cout << area() << '\n' << vol() << '\n'; }
};

class hemisphere : public circle {
public:
  hemisphere() {}
  float area() { return pi * r * r * 3; }
  float vol() { return (2.0 / 3.0) * pi * r * r * r; }
  void out() { std::cout << area() << '\n' << vol() << '\n'; }
};

class cylinder : public circle {
protected:
  float h;

public:
  cylinder() { std::cin >> h; }
  float area() { return 2 * pi * r * (r + h); }
  float vol() { return pi * r * r * h; }
  void out() { std::cout << area() << '\n' << vol() << '\n'; }
};

int main() {
  circle a;
  a.out();
  cone b;
  b.out();
  hemisphere c;
  c.out();
  cylinder d;
  d.out();
}
