#include <iostream>
#include <stdlib.h>

class emp {
private:
  char Name[50];
  int empid;

public:
  emp() { std::cin >> empid >> Name; }
  void out() { std::cout << empid << std::endl << Name << std::endl; }
};

class Department {
private:
  char Name[50];

public:
  Department() { Name[0] = 0; }

  void outName() { std::cout << Name << std::endl; }
}
}
;

int main(int argc, char *argv[]) {
  int n1 = 0;
  std::cin >> n1;
  Department *Dep = (Department *)malloc(n1 * sizeof(Department));
  for (int i = 0; i < n1; i++)
    Dep[i] = Department();

  int n2 = 0;
  std::cin >> n2;
  emp *em = (emp *)malloc(n1 * sizeof(emp));
  for (int i = 0; i < n1; i++)
    em[i] = emp();

  for (int i = 0; i < n1; i++) {
    Dep[i].outName();
  }

  for (int i = 0; i < n1; i++)
    em[i].out();

  free(Dep);
  free(em);
  return 0;
}
