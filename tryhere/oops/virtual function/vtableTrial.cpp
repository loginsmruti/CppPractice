#include <iostream>

static int myNum = 1;

class Parent {
 public:
  virtual void Foo() {}
  virtual void FooNotOverridden() {}
};

class Derived : public Parent {
 public:
  void Foo() override {}
};

int main() {

  Parent p1, p2;
  Derived d1, d2;
  
  const char* name = "Vicky";

  std::cout << "done :: " << myNum << std::endl;


}
