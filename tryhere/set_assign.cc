#include <set>
#include <iostream>
#include <string>

using namespace std;

template <class T>
void print(T& c){
   for( typename T::iterator i = c.begin(); i != c.end(); i++ ) {
      std::cout << *i << endl;
   }
}


int main()
{
   set<string> first;

   first.insert("A");
   first.insert("B");
   first.insert("C");

   cout << first.size() << endl;
   set<string> second (first);   // Copy constructor

   second.insert("I");
   second.insert("S");
   second.insert("C");

   set<string> third = first;

   print(first);
   print(second);
   print(third);
}
