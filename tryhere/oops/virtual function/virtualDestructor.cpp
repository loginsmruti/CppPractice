#include <iostream>
#include <memory>

class Base {
    public:
        Base() {
            std::cout << "Base Constructor .\n";
        };
        ~Base() {
            std::cout << "~Base Destructor.\n";
        }
};


class Derived : public Base {
    
    public:
        Derived(const size_t length) : ptr { std::move(new int{static_cast<int>(length)}) } {
            std::cout << "Derived Constructor\n";
        }

         ~Derived() {
            std::cout << "~Derived destructor\n";
        }
    private:
        std::unique_ptr<int> ptr;
};

int main() {

    //Derived d{10};

    //Base &b {d};

    Derived *d = new Derived{10};

    Base * b = d;

    delete b;
    b = NULL;

    return 0;
}