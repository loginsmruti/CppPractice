#include <string>
#include <iostream>

int main() {

       std::string pass;

       pass.assign("smruti");
   
       std::string *pointer(&pass);

       
       std::cout <<  *pointer << std::endl;
}
