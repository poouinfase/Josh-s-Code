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

int absol(int X) {
  if (X > 0)
    return X;
  return -1 * X;
}

int main() {
  srand(time(NULL));

  uint32_t p = rand() % 10;
  std::vector<int> lis;

  int num = 1;

  for (int i = 0; i < 10; i += 1) {
    lis.push_back(num);
    num *= 10;
    num += rand() % 10;
  }

  int gues = 0;
  printf("GUESS [1-10]\n");
  std::cin >> gues;
  gues--;

  p *= gues;
  p %= 10;

  int dis = 10 - absol(p - gues) - 1;

  printf("You win Rs %d\n", lis[dis]);

  return 0;
}
