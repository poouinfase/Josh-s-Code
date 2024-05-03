#include <iostream>
#include <string.h>

class student {
public:
  char reg[50];
  friend std::istream &operator>>(std::istream &in, student &c);
};

std::istream &operator>>(std::istream &in, student &c) {
  in >> c.reg;
  return in;
}

int stcm(char *s1, char *s2) {
  while (*s1 && *s2) {
    if (*s1 == *s2) {
      s1++;
      s2++;
      continue;
    }
    return *s1 - *s2;
  }
  return 0;
}

int compare(char *s1, char *s2) { return stcm(s1, s2) == 0; }

int compare(int s1, int s2) { return s1 == s2; }

int compare(float s1, float s2) { return s1 == s2; }

int compare(char s1, char s2) { return s1 == s2; }

int compare(student s1, student s2) {
  return s1.reg[0] == s2.reg[0] && s1.reg[1] == s2.reg[1];
}

template <typename T> void cmp() {
  T a, b;
  std::cin >> a >> b;
  if (compare(a, b))
    std::cout << "Same";
  else
    std::cout << "Different";

  std::cout << std::endl;
}

int main() {
  cmp<int>();
  cmp<float>();
  cmp<char>();
  cmp<char[50]>();
  cmp<student>();

  return 0;
}

/* int Oldmain() { */
/*   int i1, i2; */
/*   float f1, f2; */
/*   char c1, c2; */
/*   student st1, st2; */
/*   std::cin >> i1 >> i2 >> f1 >> f2 >> c1 >> c2 >> st1.col >> st2.col >> */
/*       st1.reg >> st2.reg; */
/**/
/*   if (compare(i1, i2)) */
/*     std::cout << "Same"; */
/*   else */
/*     std::cout << "Different"; */
/**/
/*   std::cout << std::endl; */
/**/
/*   if (compare(f1, f2)) */
/*     std::cout << "Same"; */
/*   else */
/*     std::cout << "Different"; */
/**/
/*   std::cout << std::endl; */
/**/
/*   if (compare(c1, c2)) */
/*     std::cout << "Same"; */
/*   else */
/*     std::cout << "Different"; */
/**/
/*   std::cout << std::endl; */
/**/
/*   if (compare(st1.col, st2.col)) */
/*     std::cout << "Same"; */
/*   else */
/*     std::cout << "Different"; */
/*   std::cout << std::endl; */
/**/
/*   if (compare(st1, st2)) */
/*     std::cout << "Same"; */
/*   else */
/*     std::cout << "Different"; */
/* } */
