
Both structures and classes containerize data allowing one entity to contain multiple variables.

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
void func(int ad){
  static std::vec<int> lis;
  lis.push_back(ad);
  for(auto i=lis.begin();i!=lis.end();i++)
    cout<<i<<endl;
}
```
