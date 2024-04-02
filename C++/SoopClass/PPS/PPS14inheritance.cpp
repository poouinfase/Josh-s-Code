#include <cmath>
#include <iostream>

class circle {
protected:
  float r;
  static constexpr float pi = 3.14;

public:
  circle();
  float are();
  float vol();
  void in();
  void out();
};

circle::circle() { in(); }
void circle::out() {
  std::cout << "Area= " << area() << std::endl
            << "Circumference= " << vol() << std::endl;
}
void circle::in() { std::cin >> r; }

float circle::are() { return pi * r * r; }
float circle::vol() { return pi * r * 2; }

class cone : public circle {
protected:
  float l, h;

public:
  cone();
  void in();
  float area();
  float vol();
  void out();
};

cone::cone() {
  in();
  l = sqrt(r * r + h * h);
}

float cone::area() { return pi * r * l; }
float cone::vol() { return (1.0 / 3.0) * pi * r * r * h; }
void cone::out() {
  std::cout << "Surface Area= " << area() << std::endl
            << "Volume= " << vol() << std::endl;
}
void cone::in() { std::cin >> h; }

class hemisphere : public circle {
public:
  hemisphere();
  void in();
  float area();
  float vol();
  void out();
};

hemisphere::hemisphere() {}

float hemisphere::area() { return pi * r * r * 3; }
float hemisphere::vol() { return (2.0 / 3.0) * pi * r * r * r; }
void hemisphere::out() {
  std::cout << "Surface Area= " << area() << std::endl
            << "Volume= " << vol() << std::endl;
}

class cylinder : public circle {
protected:
  float h;

public:
  cylinder();
  void in();
  float area();
  float vol();
  void out();
};

cylinder::cylinder() { in(); }

float cylinder::area() { return 2 * pi * r * (r + h); }
float cylinder::vol() { return pi * r * r * h; }
void cylinder::out() {
  std::cout << "Surface Area= " << area() << std::endl
            << "Volume= " << vol() << std::endl;
}
void cylinder::in() { std::cin >> h; }

int main() {
  circle().out();
  cone().out();
  hemisphere().out();
  cylinder().out();
}
