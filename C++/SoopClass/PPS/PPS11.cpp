#include <iostream>
#include <stdlib.h>

class Department;
class emp {
private:
  char Name[50];
  int empid;
  Department *Dep;

public:
  emp() { std::cin >> empid >> Name; }
  void setDep(Department *D) { Dep = D; }
  void out() { std::cout << empid << std::endl << Name << std::endl; }
};

struct employList {
  emp *lis;
  int len;
};

class Department {
protected:
  char Name[50];
  struct employList lis;

public:
  Department() {
    lis.len = 0;
    std::cin >> Name >> lis.len;
    lis.lis = (emp *)malloc(lis.len * sizeof(emp));
    for (int i = 0; i < lis.len; i++) {
      lis.lis[i] = emp();
      lis.lis[i].setDep(this);
    }
  }
  /* ~Department() { free(lis.lis); } */

  void outName() { std::cout << Name << std::endl; }
  void out() {
    std::cout << Name << "\n\n" << std::endl;
    for (int i = 0; i < lis.len; i++) {
      lis.lis[i].out();
    }
    std::cout << "---\n\n\n";
  }
};

int main(int argc, char *argv[]) {
  int n1 = 0;
  std::cin >> n1;
  Department *Dep = (Department *)malloc(n1 * sizeof(Department));
  for (int i = 0; i < n1; i++)
    Dep[i] = Department();
  for (int i = 0; i < n1; i++) {
    Dep[i].out();
  }
  free(Dep);
  return 0;
}
/*
FORMAT:
N//Number of Departments

N Times:
DEP_NAME//Name Of Department
NN_Emp//Number of empolyees

NN_Emp Times:
Empid Name //Employee Id name
*/
