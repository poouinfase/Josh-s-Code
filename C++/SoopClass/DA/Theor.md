Both structures and classes containerize data allowing one entity to contain multiple variables.
Both have member variables


Structures can be held in stack memory or heap memory.
Classes are mainly held in heap memory.

Structures can hold variables only.
Classes contain both variables and methods, providing certain levels of encapsulation.

Structures are value types.
Classes are reference types.

Structures cannot hold null values.
Classes can hold null values.

Structures do not have a destructor method.
Classes do have a destructor method.

Structures are automatically initialized.
Classes must be initialized using a constructor.

Structures have all member variables as default.
Classes may choose the security level of different pieces of data.

---

Static objects are those objects that exist until the end of program execution.
Most of the time Static objects are Global Static objects. Static objects declared beyond the scope of any function.

These objects can be accessed anywhere in any scope and persist until program execution completes.

One example of a static object that is widely used is std as it grants access to multiple useful library functions.

Example:

```c
#include <iostream>
#include <stdlib.h>
#include <vector>

void func(int ad) {
  static std::vector<int> lis;
  lis.push_back(ad);
  int n = 0;
  for (int i = 0; i < lis.size(); i++)
    std::cout << i + 1 << " " << lis[i] << " ";
  std::cout << std::endl;
}

int main() {
  srand(0);
  for (int i = 0; i < 10; i++)
    func(rand());
}
```

---

Reference variables are variables that contain the address of another variable.
Thus we can access a variable by dereferencing a reference variable, thus directly accessing the relevant memory address.
Often times we use reference variables in order to access objects, arrays and other classes.

Reference variables are what we use to access heap memory, allowing us to use more dynamic programming paradigms and allow us to store and return multiple values.

```c
#include <stdio.h>
void changeAddr(int *ref) { (*ref)++; }
void change(int val) { val++; }

int main() {
  int n = 90;
  printf("%d\n", n);
  change(n); // Change not carried into main
  printf("%d\n", n);
  changeAddr(&n); // Change is done to n
  printf("%d\n", n);
  return 0;
}
```
---
