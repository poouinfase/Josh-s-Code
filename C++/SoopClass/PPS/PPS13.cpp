#include <iostream>

class square {
protected:
  float h;

public:
  square() { std::cin >> h; }
  float area() { return h * h; }
  float perimeter() { return 4 * h; }
  void out() {
    std::cout << "Square- ";
    std::cout << "Area= " << area() << ", Perimeter= " << perimeter()
              << std::endl;
  }
};

class cube : public square {

public:
  cube() {}
  float area() { return h * h * h; }
  float perimeter() { return 6 * h * h; }
  void out() {
    std::cout << "Cube- ";
    std::cout << "Volume= " << area() << ", Surface Area= " << perimeter()
              << std::endl;
  }
};

class cuboid : public cube {

protected:
  float l, b;

public:
  cuboid() { std::cin >> l >> b; }
  float area() { return l * b * h; }
  float perimeter() { return 2 * (l * b + l * h + b * h); }
  void out() {
    std::cout << "Cuboid- ";
    std::cout << "Volume= " << area() << ", Surface Area= " << perimeter()
              << std::endl;
  }
};

int main(int argc, char *argv[]) {

  std::cout << cube().area();
  return 0;
}
