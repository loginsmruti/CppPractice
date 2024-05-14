#include <iostream>

//Function overloading allows creating functions with same name and different paramaters

//A function’s return type is NOT considered when overloading functions. 

//Typedefs are not distinct

//1) First, C++ tries to find an exact match.

//2) If no exact match is found, C++ tries to find a match through promotion
//3) If no promotion is possible, C++ tries to find a match through standard conversion
//4) Finally, C++ tries to find a match through user-defined conversion. 
//5) 


//int myfunction1(int a){ return 1;}
//int myfunction1(const int a){ return 2; } //WRONG


int myfunction(int& a){ return 1; }
int myfunction(const int& a) { return 1; }  //RIGHT

// ambiguous match
//int square(const int& num) { return num * num ; }
//int square(int num) { return num + num; }


//int square(int& num); ACCEPTED
//int square(const int& num);

// Type your code here, or load an example.
int exor(int& num) {
    return num ^ num;
}

int exor(const int& num) {
    return num  ^ num;
}

class MyClass {
public:
    void display() {
        std::cout << "Display without const\n";
    }

    void display() const {
        std::cout << "Display with const\n";
    }
};


/*

//Example 1
int getRandomValue() {
    return 12;
}
//error: functions that differ only in their return type cannot be overloaded
double getRandomValue() { //not an overload 

    return 1.23;
}

*/

//Example - 2
int foo(int& val) {
    val = 10;
    return val;
}

int foo(int* val) {
    *val = 20;
    return *val;
}

/*

//Typedefs are not distinct
typedef char* mystring; 
void print(mystring value);
void print(char* value);

*/

int main() {

    //example - 1
    //std::cout << getRandomValue();

    //example - 2
    int x = 5;
    std::cout << foo(&x) << "\n";
    std::cout << foo(x) << std::endl; 


        int y = 5;
    std::cout << exor(y) << '\n';

    MyClass obj;
    obj.display(); //Display without const

    const MyClass obj1;
    obj1.display(); //Display with const

    

    return 0;
}

