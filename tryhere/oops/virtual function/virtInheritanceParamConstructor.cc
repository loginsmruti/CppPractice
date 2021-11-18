#include<iostream>
using namespace std;

//remove the comment & see the magic

class Person {
   public:
      Person(int x)  { cout << "Person::Person(int ) called" << endl;   }
      Person()     { cout << "Person::Person() called" << endl;   }
      ~Person() { cout << "destructor Person::~Person() called" << endl;}
};

class Faculty : /*virtual*/ public Person {
   public:
      Faculty(int x):Person(x)   {
         cout<<"Faculty::Faculty(int ) called"<< endl;
      }

     ~Faculty() { cout<<"Destructor Faculty::~Faculty called"<< endl;}
};

class Student : /*virtual*/ public Person {
   public:
      Student(int x):Person(x) {
         cout<<"Student::Student(int ) called"<< endl;
      }
     ~Student() { cout<<"Destructor Student::~Student called"<< endl;}
};

class TA : public Student ,public Faculty  {
   public:
      TA(int x):Student(x), Faculty(x)/*, Person(x)*/   {
         cout<<"TA::TA(int ) called"<< endl;
      }

     ~TA() { cout<<"Destructor TA::~TA called"<< endl;}
};

int main()  {

   TA ta1(30);

   return 0;
}
