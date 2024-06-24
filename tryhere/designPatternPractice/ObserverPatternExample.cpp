#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Observer {

    public:
        virtual void fieldChanged(T& source, const std::string& msg) = 0;

};


template <typename T>
class Observable {

    private:
        std::vector<Observer<T>*> observers;

    public:
            void subscribe(Observer<T>& observer) {
                observers.push_back(&observer);
            }

            void unsubscribe(Observer<T>& observer) {
                observers.erase(std::remove(observers.begin(), observers.end(), &observer), observers.end() );
            }

            void notify(T& source , const std::string fieldName) {
                for(auto& observer: observers) {
                    observer->fieldChanged(source, fieldName);
                }
            }
};


class Person : public Observable<Person>
{
    int age_{0};
 public:
    Person() = default;

    Person(int age) : age_(age) { }

    int getAge() const { return age_; }

    void setAge(int age) {

        if(this->age_ == age) return;

        this->age_ = age;

        notify(*this, "age");
    }
};

class ConsoleObserver : public Observer<Person> {

    public:
        virtual void fieldChanged(Person& source, const std::string& fieldName) {

            std::cout << "Person " <<  "changed to ";
            if(fieldName == "age") std::cout << source.getAge() << std::endl;

            std::cout << std::endl;
        }
};

int main() {

    Person p;

    ConsoleObserver cop;

    p.subscribe(cop);

    p.setAge(13);
    p.setAge(14);

    p.unsubscribe(cop);

    p.setAge(15);


    return 0;
}