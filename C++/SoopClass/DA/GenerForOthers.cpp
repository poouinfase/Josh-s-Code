#include <corecrt.h>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;

class stack {
private:
  uint8_t *byte;
  int len;
  int cap;

public:
  stack(int ln = 1024) {
    len = ln;
    byte = (uint8_t *)malloc(len);

    cap = 0;
  }

  void int8Push(int8_t siz) {
    byte[cap] = siz;
    cap++;
  }
  template <typename T> void push(T t) {

    int temp = cap;
    for (cap; cap - temp < sizeof(T); cap++) {
      byte[cap] = (uint64_t)t & 0xff;
      t = (T)((uint64_t)t >> 8);
    }
    int8Push(sizeof(T));
  }
  int8_t int8Pop() {
    cap--;
    return byte[cap];
  }

  template <typename T> void pop(T *t) {
    if (cap == 0) {
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
    int temp = cap;
    for (cap; temp - cap < siz; cap--) {
      *t = (T)(((uint64_t)*t << 8) | byte[cap - 1]);
    }
    *t = *t;
  }
};

class Test {
private:
  char name[50];
  int Uid;

public:
  Test(int i = 0) {
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
  stack a = stack();

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
    Test *ti = new Test(i + 1);
    ti->input();
    a.push(ti);
  }

  // POPIN
  for (int i = 0; i < Obji; i++) {
    Test *ti;
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
