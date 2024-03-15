#include <stdio.h>

class employee {
public:
  MakeAdance();
  void input();
  void raise(float);
  void output();

private:
  int empid;
  char name[50];
  float salary;
};

void employee::input() { scanf("%d %s %f", &empid, name, &salary); }
void employee::output() {
  printf("Employe id: %d\nName: %s\nSalary: %.2f\n", empid, name, salary);
}

void employee::raise(float rai = 1.1) { salary *= rai; }

int main() {
  employee jo;
  jo.input();
  jo.output();
  jo.raise(10);
  jo.output();
}
