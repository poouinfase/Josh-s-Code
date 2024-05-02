#include <corecrt.h>
#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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

  template <typename T> void push(T t) {
    int temp = cap;
    for (cap; cap - temp < sizeof(T); cap++) {
      byte[cap] = (uint64_t)t & 0xff;
      t = (T)((uint64_t)t >> 8);
    }
  }

  template <typename T> void pop(T *t) {
    if (cap == 0) {
      cout << "STACK IS EMPTY" << endl;
      return;
    }

    *t = 0;
    int temp = cap;
    for (; temp - cap < sizeof(T); cap--) {
      *t = (T)(((uint64_t)*t << 8) | byte[cap - 1]);
    }
  }
};

class Student {
private:
  char name[50];
  int Uid;

public:
  Student() {
    static int n = 1;
    name[0] = 0;
    Uid = n;
    n++;
  }
  void input() {
    cout << "Name ";
    cin >> name;
  }
  void out() { cout << "Uid: " << Uid << "\tName: " << name << endl; }
};

int main() {
  stack a = stack();

  int letteri = 0;
  cout << "Characters: ";
  cin >> letteri;
  for (int i = 0; i < letteri; i++) {
    char ti;
    cin >> ti;
    a.push(ti);
  }

  int Numi = 0;
  cout << "Numbers: ";
  cin >> Numi;
  for (int i = 0; i < Numi; i++) {
    int ti;
    cin >> ti;
    a.push(ti);
  }

  int Obji = 0;
  cout << "Objects: ";
  cin >> Obji;
  for (int i = 0; i < Obji; i++) {
    Student *ti = new Student();
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
