#include <vector>
#include <iostream>
#include <iterator>
#include <string>

template <typename T>
auto print = [] (const std::string& str, const std::vector<T>& container) {
    std::cout << str ;
    for(const auto& elem: container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
};

class Person
{
    private:
        int id = {0};
        std::string name = {""};
    public:
        Person(int idNum, std::string identity) : 
                id(idNum), name(identity)
                {}
        
        const int& getId() const { return id; }

        const std::string& getName () const { return name; }

        void setId(int id) { this-> id = id; }

        void setName(std::string name) { this-> name  = name; }

        friend std::ostream& operator<<(std::ostream& os, const Person& person) {
            os << "\nId: " << person.getId() << " Name: " << person.getName() << "\n";
            return os;
        }
};


int main()
{
    //Constructor
        
        //Empty
        std::vector<std::string> emptyStr;
        
        //Fill
        std::vector<std::string> fillStr(10, "Hi");
        
        //range
        std::vector<std::string> rangeStr(fillStr.begin(), fillStr.end());
        
        //copy
        std::vector<std::string> copyStr(rangeStr);
        
        //initializer list
        std::vector<std::string> initStr({"Hi", "bye", "Bonjour", "Hola", "Yeah"});

        //move
        std::vector<std::string> moveStr(std::move(initStr));

        int myInts[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> arrVect(myInts , myInts + sizeof(myInts)/ sizeof(int));
    
    //destructor
        //~vector()
    
    //Iterator
        //begin
        //cbegin
        //rbegin
        //crbegin
        //end
        //cend
        //rend
        //crend
        for_each(moveStr.begin(), moveStr.end(), [](const std::string& str) 
                                                    { std::cout << str << ", "; } );
        std::cout << "\n";
        std::copy(copyStr.begin(), copyStr.end(), std::ostream_iterator<std::string>(std::cout, " "));

        std::cout << "\n";

        for (auto &&i : myInts)
        {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
        
        std::vector<std::string>::const_reverse_iterator crit = moveStr.crbegin();
        while(crit != moveStr.crend()) {
            std::cout << *crit << ", ";
            crit++;
        }
        std::cout << "\n";

    //Element Access
        //at
        //operator
        //front
        //back
        std::string welcomeStr = "";
        for(size_t i = 0; i< moveStr.size(); i++) {

            welcomeStr = welcomeStr + moveStr.at(i) + "," + moveStr.front() + moveStr.back();
        }
        std::cout << welcomeStr << std::endl;
    
    //Capacity
        //empty
        //size
        //max_size
        //resize
        //capacity
        //reserve
        //shrink_to_fit
        
        std::vector<std::string> tempVect;
        tempVect.reserve(100);
        if (tempVect.empty()) {
            std::cout << "Temp Vector is Empty.\n" << std::endl;
            tempVect.assign(20, "Hi");
            print<std::string>("Print TempVect: ", tempVect);
        } else {
            print<std::string>("Print TempVect", tempVect);
        }

        std::cout << "SIZE: " << tempVect.size() << "\n";
        std::cout << "max_size: " << tempVect.max_size() << '\n';
        std::cout << "Capacity: " << tempVect.capacity() << '\n';

        tempVect.resize(50);
        std::cout << "SIZE: " << tempVect.size() << "\n";
        std::cout << "Capacity: " << tempVect.capacity() << '\n';

        tempVect.shrink_to_fit();
        print<std::string>("Print TempVect: ", tempVect);

    //Modifier
        //insert
        //erase
        auto it = tempVect.insert(tempVect.begin() + 2 , "Bye" );

        print<std::string>("TempVect Insert: ", tempVect);

        it = tempVect.insert(it, 3, "Morning");

        print<std::string>("TempVect Insert: ", tempVect);

        it = tempVect.erase(it);
        print<std::string>("TempVect Insert: ", tempVect);
        it = tempVect.erase(it, it + 2);
        print<std::string>("TempVect Insert: ", tempVect);

        //emplace
        //emplace_back

        //push_back
        tempVect.push_back("Bonjour");
        tempVect.push_back("Hola");
        
        //pop_back
        tempVect.pop_back();
        //swap
        tempVect.swap(fillStr);
        print<std::string>("swap: ", tempVect);
        print<std::string>("swap: ", fillStr);
        
        //clear
        fillStr.clear();
        std::vector<std::string> str({"Hi", "Bye", "Hola", "Bonjour", "start", "end"});
        std::vector<std::string>().swap(str);
        std::cout << std::endl;
        print<std::string>("Clear: ", str);

        std::vector<Person> personVect;
        Person personObj(1, std::string("Sample_Name"));
        personVect.assign(10, personObj);
        print<Person>("Person Object: ", personVect);
        int id = 0;
        for(auto && obj: personVect) {
            obj.setId(++id);
            obj.setName("Sample_name_1");
        }

        
        personVect.emplace(personVect.begin(), 0, "Rocky");
        personVect.emplace_back(11, "Vicky");


        print<Person>("Person Object: ", personVect);

    //List Operations

    //LookUp

    //Observer
     

    //Allocator
        //get_allocator
    return 0;
}