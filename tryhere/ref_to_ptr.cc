#include <iostream>

int g_n = 42;

void func_ref_to_ptr(int*& pp);

void example_ref_to_ptr()
{
   int n = 23;
   int* pn = &n;

   std::cout << "example_ref_to_ptr()" << std::endl;

   std::cout << "Before :" << *pn << std::endl; // display 23

   func_ref_to_ptr(pn);

   std::cout << "After :" << *pn << std::endl; // display 42
}

void func_ref_to_ptr(int*& pp)
{
   pp = &g_n;
}


int main() {

   example_ref_to_ptr();
   
   return 0;
}
   
