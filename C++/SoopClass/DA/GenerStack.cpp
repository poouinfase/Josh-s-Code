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

class Student {
private:
  char name[50];
  int Uid;

public:
  Student(int i = 0) {
    name[0] = 0;
    Uid = i;
  }
  void input() {
    cout << "Name? ";
    cin >> name;
  }
  void out() { cout << "Uid: " << Uid << "\tName: " << name << endl; }
};

int main() {
  Stack a = Stack();

  int letteri = 0;
  cout << "How Many Characters?: ";
  cin >> letteri;
  for (int i = 0; i < letteri; i++) {
    char ti;
    cin >> ti;
    a.push(ti);
  }

  int Numi = 0;
  cout << "How Many Numbers?: ";
  cin >> Numi;
  for (int i = 0; i < Numi; i++) {
    int ti;
    cin >> ti;
    a.push(ti);
  }

  int Obji = 0;
  cout << "How Many Objects?: ";
  cin >> Obji;
  for (int i = 0; i < Obji; i++) {
    Student *ti = new Student(i + 1);
    ti->input();
    a.push(ti);
  }

  // POPIN
  for (int i = 0; i < Obji; i++) {
    Student *ti;
    a.pop(&ti);
    ti->out();
  }

  for (int i = 0; i < Numi; i++) {
    int ti;
    a.pop(&ti);
    cout << ti << endl;
  }

  for (int i = 0; i < letteri; i++) {
    char ti;
    a.pop(&ti);
    cout << ti << endl;
  }

  return 0;
}
