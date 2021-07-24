
#include <iostream>

//Forward declaration
class Parent;
class ChildOne;
class ChildTwo;

class MemberFunctionWrapper
{
   public:

      enum DerivedType { ParentType, ChildOneType, ChildTwoType };

      typedef void(Parent::*ParentFnType)();
      typedef void(ChildOne::*ChildOneFnType)();
      typedef void(ChildTwo::*ChildTwoFnType)();

      MemberFunctionWrapper(ParentFnType fn) : type_(ParentType) { fn_.ParentFn_ = fn; }
      MemberFunctionWrapper(ChildOneFnType fn) : type_(ChildOneType) {fn_.ChildOneFn_ = fn;}
      MemberFunctionWrapper(ChildTwoFnType fn) : type_(ChildTwoType) {fn_.ChildTwoFn_ = fn;}

      void operator()(Parent* ptr) const;

   private:

      union FnUnion
      {
         ParentFnType ParentFn_;
         ChildOneFnType ChildOneFn_;
         ChildTwoFnType ChildTwoFn_;
      };

      DerivedType type_;
      FnUnion fn_;
};

class Parent
{
   public:

      Parent() : doSomethingImpl(&Parent::doSomeWork) { }
      Parent(MemberFunctionWrapper::ChildOneFnType f) : doSomethingImpl(f) { }
      Parent(MemberFunctionWrapper::ChildTwoFnType f) : doSomethingImpl(f) { }

      void doSomething() { doSomethingImpl(this); }
   private:
      void doSomeWork() {
         std::cout <<"Parent::doSomeWork() called\n"; 
      }
      MemberFunctionWrapper doSomethingImpl;
};

class ChildOne : public Parent
{
   public:
      ChildOne() : Parent(&ChildOne::doSomeWork) { }

   private:
      void doSomeWork() {

         std::cout <<"ChildOne::doSomeWork() called\n";
      } 
};

class ChildTwo : public Parent
{
   public:
      ChildTwo() : Parent(&ChildTwo::doSomeWork) { }
   private:
      void doSomeWork() { 
         std::cout <<"ChildTwo::doSomeWork() called\n";
      } 
};

void MemberFunctionWrapper::operator()(Parent* ptr) const
{
   switch (type_)
   {
      case ParentType:     return (ptr->*(fn_.ParentFn_))();
      case ChildOneType: return (static_cast<ChildOne*>(ptr)->*(fn_.ChildOneFn_))();
      case ChildTwoType: return (static_cast<ChildTwo*>(ptr)->*(fn_.ChildTwoFn_))();
   }
}

int main()
{
   Parent* obj0 = new Parent;
   Parent* obj1 = new ChildOne;
   Parent* obj2 = new ChildTwo;
   obj0->doSomething(); // resolved this call to  Parent::doSomeWork()
   obj1->doSomething(); // resolved this call to ChildOne::doSomeWork()
   obj2->doSomething(); // resolved this call to ChildTwo::doSomeWork()

   return 0;
}

