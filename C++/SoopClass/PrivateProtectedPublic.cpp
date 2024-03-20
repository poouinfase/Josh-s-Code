#include <iostream>

class A{
private:
    int pri;
protected:
    int pro;
public:
    int pub;
    A(){
      A::pri=1;
      A::pro=2;
      A::pub=3;
    }
    void in(){
      std::cin>>pri>>pro>>pub;
    }
    void out(){
      std::cout<<"pri= "<<A::pri<<std::endl;
      std::cout<<"pro= "<<A::pro<<std::endl;
      std::cout<<"pub= "<<A::pub<<std::endl;
    }
};

class B:public A{
  public:
    void hi(){
      std::cout<<"HI"<<std::endl;
      A::out();
    }
    void out(){
      std::cout<<"HI"<<std::endl;
      /* std::cout<<"pri= "<<pri<<std::endl; */
      std::cout<<"pro= "<<A::pro<<std::endl;
      std::cout<<"pub= "<<A::pub<<std::endl;
    }
};

void prin(int a){
  printf("%d\n",a);
}

int main(){
  A a;
  B b;
  a.out();
  b.out();
  b.A::out();
}
