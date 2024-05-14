#include <iostream>
#include <string_view>
#include  <memory>

class Animal {
    
    protected:
        std::string_view name;
        Animal(std::string_view myName) : name(myName) { }
        
        //copy constructor = delete
        Animal(const Animal& animal) = delete;
        //copy assignment operator = delete
        Animal& operator=(const Animal& animal) = delete;
       
    public:
        virtual ~Animal() = default;
        virtual const std::string_view& getName() const { return name; }
        virtual const char* speak() const { return "???"; }

};

class Cat : public Animal {
    
    public:
        Cat(std::string_view myName) : Animal(myName) { }

        const char* speak() const { return "Meow"; }
};

class Dog : public Animal {

    public:
        Dog(std::string_view myName) : Animal(myName) { }
    
        const char* speak() const { return "Bhow"; }
};

int main() {

    Cat cat("Pussy");
    Dog dog("Jacky");

    Animal& obj = cat;
    Animal& obj2 = dog;
    
    std::cout << "Animal name: "<< obj.getName() << ", speaks:  " << obj.speak() << std::endl;
    std::cout << "Animal name: "<< obj2.getName() << ", speaks: " << obj2.speak() << "\n\n";
    
    std::unique_ptr<Animal> ptr(new Cat("Disco"));
    std::unique_ptr<Animal> pointer(new Dog("Dancer"));

    std::cout << "Animal name: "<< ptr->getName() << ", speaks:  " << ptr->speak() << std::endl;
    std::cout << "Animal name: "<< pointer->getName() << ", speaks: " << pointer->speak() << std::endl;
    
    return 0;
}