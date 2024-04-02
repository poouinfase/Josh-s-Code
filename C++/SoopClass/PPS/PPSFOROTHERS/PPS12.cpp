#include <iostream>

class circle {
protected:
  float r;

public:
  circle(){std::cin >> r};
  float are() { return 3.14 * r * r; }
  float vol() { return 3.14 * r * 2; }
  float dia() { return r * 2; }
  void out() { std::cout << dia() << '\n' << are() << '\n' << vol() << '\n'; }
};

class sphere : public circle {

public:
  float are() { return 4 * 3.14 * r * r; }
  float vol() { return (4.0 / 3.0) * 3.14 * r * r * r; }
  void out() {
    circle::out();
    std::cout << are() << '\n' << vol() << '\n';
  }
};

int main() { sphere().out(); }
