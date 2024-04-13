#include <corecrt.h>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

typedef struct {
  char name[5000];
} chio;

class Stack {
private:
  uint8_t *data;
  size_t len;
  size_t filled;

  inline int BoundCheck(size_t n) { return (len - filled) < n; }

public:
  Stack(size_t ln = 1024) {
    len = ln;
    data = (uint8_t *)malloc(len);
    for (int i = 0; i < len; i++)
      data[i] = 0;
    filled = 0;
  }

  void StackExpand() {
    len *= 1.5;
    data = (uint8_t *)realloc((void *)data, len);
    cout << "Stack Expanded to: " << len << endl;
  }
  void int8Push(int8_t siz) {
    if (BoundCheck(sizeof(int8_t)))
      StackExpand();
    data[filled] = siz;
    filled++;
  }
  template <typename T> void push(T t) {
    if (BoundCheck(sizeof(T))) {
      StackExpand();
      push(t);
      return;
    }

    size_t temp = filled;
    for (filled; filled - temp < sizeof(T); filled++) {
      data[filled] = (uint64_t)t & 0xff;
      t = (T)((uint64_t)t >> 8);
    }
    int8Push(sizeof(T));
  }
  int8_t int8Pop() {
    filled--;
    return data[filled];
  }

  template <typename T> void pop(T *t) {
    if (filled == 0) {
      cout << "STACK IS EMPTY" << endl;
      return;
    }

    int8_t siz = int8Pop();
    if (siz > sizeof(T)) {
      cout << "POINTER MISMATCH" << endl;
      int8Push(siz);
      return;
    }

    *t = 0;
    size_t temp = filled;
    for (filled; temp - filled < siz; filled--) {
      *t = (T)(((uint64_t)*t << 8) | data[filled - 1]);
    }
    *t = *t;
  }
};

int test1() {
  Stack a = Stack();

  uint32_t ittr = 0;
  cout << "How Many Datas: ";
  cin >> ittr;

  for (int i = 0; i < ittr; i++) {
    int8_t ti = 0;
    cin >> ti;
    a.push(ti);
  }

  for (int i = 0; i < ittr / 2; i++) {
    int8_t te = 0;
    a.pop(&te);
    cout << te << endl;
  }

  for (int i = 0; i < ittr / 2; i++) {
    int16_t te = 0;
    a.pop(&te);
    cout << te << endl;
  }

  return 0;
}

int test2() {
  Stack a = Stack();
  chio c = {};
  strcpy(c.name, "HELLO WORLD");
  chio *cpt;

  a.push(&c);
  a.pop(&cpt);

  cout << cpt->name << endl;

  return 0;
}

#define RAND 8000
int test3() {
  Stack a = Stack();
  srand(time(NULL));

  for (int i = RAND; i >= 0; i--) {
    a.push(rand());
  }

  for (int i = RAND; i >= 0; i--) {
    uint64_t temp = 0;
    a.pop(&temp);
    /* cout << int(temp) << endl; */
  }

  return 0;
}

int main() {
  Stack a = Stack();
  a.push();
  double in = 0;
  a.pop(&in);
  cout << in << endl;
}
