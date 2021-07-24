#include<iostream>


int main() {


  float f = 12.3;
  float* pf = &f;

  // static cast<>
  // OK, n = 12
  int n = static_cast<int>(f);
  // Error, types pointed to are unrelated
  //int* pn = static_cast<int*>(pf);
  // OK
  void* pv = static_cast<void*>(pf);
  // OK, but *pn2 is rubbish
  int* pn2 = static_cast<int*>(pv);
  
  // reinterpret_cast<>
  // Error, the compiler know you should
  // call static_cast<>
  
  //reinterpret_cast from float to int not allowed
  //int i = reinterpret_cast<int>(f);
  
  // OK, but *pn is actually rubbish, same as *pn2
  int* pi = reinterpret_cast<int*>(pf);

  return 0;
}
