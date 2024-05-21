#include <iostream>
#include <memory>
#include <string>

class Person {

    private:
        std::weak_ptr<Person> partner;
        std::string name_;
    public:
     Person(const std::string& name) : name_(name) { } 
     ~Person() = default;

    const std::string getName() const { return name_; }

    friend bool makePartner( std::shared_ptr<Person>& person_1, std::shared_ptr<Person>& person_2 ) {
        
        if(!person_1 || !person_2)
            return false;

        person_1->partner = person_2;
        person_2-> partner = person_1;
        std::cout << person_1->getName() << " is now partnered with " << person_2->getName() << "\n";

        return true;
    }

    const std::shared_ptr<Person> getPartner() const {
        return partner.lock();
    }
};

int main() {

    auto lucy = std::make_shared<Person>("Lucy");
    auto lucky = std::make_shared<Person>("Lucky");

    makePartner(lucy, lucky);

    auto partner = lucy->getPartner(); // get shared_ptr to Ricky's partner
    std::cout << lucy->getName() << "'s partner is: " << partner->getName() << std::endl;

    return 0;
}