#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <stdio.h>

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

class Numbers {
private:
  int *lis;
  int len;

public:
  Numbers(int len = 2) {
    this->len = len;
    lis = (int *)malloc(this->len * sizeof(int));
  }

  void operator+=(Numbers a) {
    for (int i = 0; i < len; i++) {
      lis[i] += a.lis[i];
    }
  }

  void input() {
    for (int i = 0; i < len; i++) {
      std::cin >> lis[i];
    }
  }
  void output() {
    for (int i = 0; i < len; i++) {
      std::cout << lis[i];
    }
    std::cout << std::endl;
  }
  ~Numbers() { free(lis); }
};

int main() {
  int l1, l2;

  std::cin >> l1;
  Numbers a(l1);
  a.input();

  std::cin >> l2;
  Numbers b(l2);
  b.input();

  a += b;

  a.output();
}
