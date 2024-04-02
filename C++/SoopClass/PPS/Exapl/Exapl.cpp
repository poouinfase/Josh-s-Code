#include <iostream>

class cuboid {

protected:
  float l, b, h;

public:
  cuboid() { std::cin >> l >> b >> h; }
  float area() { return l * b * h; }
  float perimeter() { return 2 * (l * b + l * h + b * h); }
  void out() {
    std::cout << "Cuboid- ";
    std::cout << "Volume= " << area() << ", Surface Area= " << perimeter()
              << std::endl;
  }
};

int main(int argc, char *argv[]) {
  cuboid c = cuboid();
  std::cout << c.area() << std::endl;
  c.out();
  return 0;
}
