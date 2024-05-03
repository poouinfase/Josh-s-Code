#include <iostream>
#include <string.h>

class student {
public:
  char reg[50];
  char col[50];
};

int stcm(char *a, char *b) {
  while (*a != 0 && *b != 0) {
    if (*a == *b) {
      a++;
      b++;
      continue;
    }
    return *a - *b;
  }
  return 0;
}

int cmp(char *a, char *b) { return stcm(a, b) == 0; }

int cmp(int a, int b) { return a == b; }

int cmp(float a, float b) { return a == b; }

int cmp(char a, char b) { return a == b; }

int cmp(student a, student b) {
  return cmp(a.col, b.col) && a.reg[0] == b.reg[0] && a.reg[1] == b.reg[1];
}

int main() {
  int int1, int2;
  float float1, float2;
  char char1, char2;
  student st1, st2;
  std::cin >> int1 >> int2 >> float1 >> float2 >> char1 >> char2 >> st1.col >>
      st2.col >> st1.reg >> st2.reg;

  if (cmp(int1, int2))
    std::cout << "Same\n";
  else
    std::cout << "Different\n";

  if (cmp(float1, float2))
    std::cout << "Same\n";
  else
    std::cout << "Different\n";

  if (cmp(char1, char2))
    std::cout << "Same\n";
  else
    std::cout << "Different\n";

  if (cmp(st1.col, st2.col))
    std::cout << "Same\n";
  else
    std::cout << "Different\n";

  if (cmp(st1, st2))
    std::cout << "Same\n";
  else
    std::cout << "Different\n";
}
