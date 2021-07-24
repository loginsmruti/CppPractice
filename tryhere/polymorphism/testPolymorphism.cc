#include<iostream>

class A
{
  public:
    virtual const char* getName() { return "A"; }
    A() { std::cout << "A() Constructor Called\n"; }
    virtual ~A() { std::cout << "~A() destructor called\n"; } 
};

class B: public A
{
  public:
    B() { std::cout << "B() Constructor Called\n"; }
    virtual const char* getName() { return "B"; }
    ~B() { std::cout << "~B() destructor called\n"; } 
};

class C: public B
{
  public:
    C() { std::cout << "C() Constructor Called\n"; }
    virtual const char* getName() { return "C"; }
    ~C() { std::cout << "~C() destructor called\n"; }
};

class D: public C
{
  public:
    D() { std::cout << "D() Constructor Called\n"; }
    const char* getName() { return "D"; }
    //virtual 
      ~D() { std::cout << "~D() destructor called\n"; } 
};

int main()
{
  //C c;
  //A &rBase = c;
  //std::cout << "rBase is a " << rBase.getName() << '\n';

  A *obj = new D;

  delete obj;

  return 0;
}

