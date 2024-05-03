#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <stdio.h>

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

template <typename T> class List {
private:
  T *lis;
  size_t at;
  size_t len;

public:
  List(int64_t len = 2) {
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

  void operator+=(List<T> a) {
    for (int i = 0; i < len; i++) {
      lis[i] += a.lis[i];
    }
  }

  template <typename t>
  friend std::istream &operator>>(std::istream &in, List<t> &c);
  template <typename t>
  friend std::ostream &operator<<(std::ostream &out, List<t> &c);

  void output() {
    for (int i = 0; i < len; i++) {
      std::cout << lis[i];
    }
    putchar('\n');
  }
  ~List() { free(lis); }
};

template <typename T> std::istream &operator>>(std::istream &in, List<T> &c) {
  for (int i = 0; i < c.len; i++) {
    in >> c.lis[i];
  }
  return in;
}

template <typename t> std::ostream &operator<<(std::ostream &out, List<t> &c) {
  for (int i = 0; i < c.len; i++) {
    out << c.lis[i] << " ";
  }
  out << std::endl;
  return out;
}

int main() {
  int l1, l2;

  std::cin >> l1;
  List<double> a(l1);
  std::cin >> a;

  std::cin >> l2;
  List<double> b(l2);
  std::cin >> b;

  a += b;

  std::cout << a;
}
