#include <cstddef>
#include <cstdio>
#include <iostream>
#include <locale.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

template <typename T> class Vec {
private:
  T *lis;
  size_t at;
  size_t len;

public:
  Vec(int64_t len = 2) {
    at = -1;
    this->len = len;
    lis = (T *)malloc(this->len * sizeof(T));
  }

  void VecExp(int Se = 0) {
    len *= 1.5;
    len = max(Se, len);
    this->lis = (T *)realloc(lis, len * sizeof(T));
    for (int i = at + 1; i < len; i++)
      lis[i] = 0;
  }

  void push(T a) {
    at++;
    if (at >= len)
      VecExp(at + 1);
    lis[at] = a;
  }

  void prin() {
    for (int i = 0; i <= at; ++i) {
      std::cout << lis[i] << " ";
    }
    std::cout << std::endl;
  }

  T pop() { return lis[at--]; }

  T &operator[](const size_t ind) {
    if (ind >= len)
      VecExp(ind + 1);
    return lis[ind];
  }
  ~Vec() { free(lis); }
};

int absol(int X) {
  if (X > 0)
    return X;
  return -1 * X;
}

#define GUESSLIM 10
int main() {
  srand(time(NULL));

  uint32_t p = rand();
  Vec<int> lis(2);

  int num = 1;

  for (int i = 0; i < GUESSLIM; i += 1) {
    lis.push(num);
    num *= 10;
    num += rand() % 10;
  }

  int gues = 0;
  printf("GUESS [1-%d] ", GUESSLIM);
  std::cin >> gues;
  gues--;
  /* lis.prin(); */

  p *= gues;
  p %= GUESSLIM;
  /* std::cout << p << std::endl; */

  int dis = GUESSLIM - absol(p - gues) - 1;

  printf("You win Rs %d\n", lis[dis]);

  return 0;
}
