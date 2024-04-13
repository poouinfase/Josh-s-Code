#include <stdio.h>

class Complex {

private:
  double re, imi;

public:
  Complex() {
    this->re = 0.0;
    this->imi = 0.0;
  }

  Complex(double re, double imi) {
    this->re = re;
    this->imi = imi;
  }

  Complex operator+(Complex add) { return Complex(re + add.re, imi + add.imi); }

  void display() {
    if (imi > 0)
      printf("%.2f+%.2fi\n", re, imi);
    else
      printf("%.2f-%.2fi\n", re, -1 * imi);
  }
  ~Complex() {
    printf("Killed: ");
    display();
  }
};

void jin() { (Complex(1, 2) + Complex(3, 5)).display(); }

int main() { jin(); }
