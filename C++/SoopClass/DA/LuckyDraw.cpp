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
    lis = (T *)realloc(lis, len);
    for (int i = at + 1; i < len; i++)
      lis[i] = 0;
  }

  void push_back(T a) {
    at++;
    lis[at] = a;
  }

  T pop_back() { return lis[at--]; }

  T &operator[](const size_t ind) {
    if (ind >= len)
      VecExp(ind);
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

  uint32_t p = rand() % GUESSLIM;
  Vec<int> lis;

  int num = 1;

  for (int i = 0; i < GUESSLIM; i += 1) {
    lis.push_back(num);
    num *= 10;
    num += rand() % 10;
  }

  int gues = 0;
  printf("GUESS [1-%d] ", GUESSLIM);
  std::cin >> gues;
  gues--;

  p *= gues;
  p %= GUESSLIM;
  std::cout << p << std::endl;

  int dis = GUESSLIM - absol(p - gues) - 1;

  printf("You win Rs %d\n", lis[dis]);

  return 0;
}
