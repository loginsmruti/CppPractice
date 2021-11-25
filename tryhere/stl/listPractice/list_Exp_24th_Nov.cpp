#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <experimental/iterator>

template <typename T>
auto print = [] (const std::string& str, const std::list<T>& container) {
    std::cout << str;
    for(const auto& elem: container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
};

auto randomNumber = [] () -> int  {
    return std::rand() % 100;
};

void listConstructors() {

    std::list<int> empty; //empty constructor
    std::list<int> fill(10, 100);
    std::list<int> range(fill.begin(), fill.end());
    std::list<int> copy(fill);
    std::list<int> move(std::list<int>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110}));
    std::list<int> initializerList({1,2,3,4,5,6,7,8,9});

    empty.assign({3,4,5,6,103, 104, 105, 106, 7,8,9});

    print<int>("Dummy initialization via::: ", initializerList);
}

void ways_to_iterate_list() {

    std::list<int> move(std::list<int>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110}));

    std::cout << "Iterate via range based loop: ";
    for(const auto& elem: move) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Loop via std::list<int>::iterator : ";
    std::list<int>::iterator it = move.begin();
    while (it != move.end())
    {
        std::cout << *it << " ";
        it++;
    }
    

    std::cout << "\nIterate via std::copy ostream_iterator: ";
    std::copy(move.begin(), move.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << "\nIterate via std::copy std::experimental::ostream_joiner: ";
    std::copy(move.begin(), move.end(), std::experimental::make_ostream_joiner(std::cout, " "));

    std::cout << "\nIterate via for_each: ";
    for_each(move.begin(), move.end(), [] (const auto& elem) {
        std::cout << elem << " ";
    });
    std::cout << std::endl;

}

void randomNumberGenerator() {

    std::list<int> move(std::list<int>({100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110}));

    std::generate(move.begin(), move.end(), randomNumber);

    print<int>("randomNumberGenerator::: ", move);
}


struct Student {
    int id;
    std::string name;
    
    //Constructor
    Student(int id, std::string name) :
            id(id),
            name(name) {
                std::cout << "\nConstructor Called" << std::endl;
            }
/*
    //Copy constructor
    Student(const Student& st):
                    id(st.id), name(st.name) 
                    {
                        std::cout << "\n Copy Constructor Called" << std::endl;
                    }
    
    //Copy assignment
    Student& operator=(const Student& st) {
        std::cout << "\Copy assignment Called" << std::endl;
        if(this == &st)
            return *this;

        id = 0;
        name = "";

        id = st.id;
        name = st.name;

        return *this;
    }
*/
    //move constructor
    Student(Student&& st) noexcept:
                    id(st.id), name(st.name)
    {
        st.id = 0;
        st.name = "";
        std::cout << "\nMove Constructor Called" << std::endl;
    }

    //move assignment
    Student& operator=(Student&& st) noexcept {
        
        std::cout << "\nMove assignment Called" << std::endl;

        if(this == &st)
            return *this;
        
        id = 0;
        name = "";

        id = st.id;
        name = st.name;

        st.id = 0;
        st.name = "";

        return *this;
    }


};

void listAPI() {
    std::list<int> empty; //empty constructor

    //assign
    empty.assign({3,4,5,6,103, 104, 105, 106, 7,8,9});

    //push_back
    std::list<int> myLIst;
    myLIst.push_back(10);

    while( myLIst.back() != 0 ) {
        myLIst.push_back( myLIst.back() - 1 );
        //myLIst.pop_back();
    }
    //pop_back
    myLIst.pop_back();
    
    //push_front
    myLIst.push_front(100);
    print<int>("\nUse of list.back() ::: ", myLIst);

    std::list<Student> listObj;
    //std::list<Student> listObj(10, Student(0, ""));
    listObj.push_front(Student(1, "Vicky"));
    listObj.insert(listObj.begin(), Student(2, "Vicky"));
    listObj.insert(listObj.begin(), Student(3, "Vicky"));

    //listObj.emplace_back(listObj.begin(), 2, "Rocky");
    //listObj.emplace_front(listObj.begin(), 3, "Mama");

    std::cout << "emplace_back() / push_back() / push_front() / emplace_front() / insert :::\n" ;
    for_each(listObj.begin(), listObj.end(), [](const Student& refObj) {
        std::cout << refObj.id << "     " << refObj.name << std::endl;
    });

    //insert API
    auto listItr = listObj.insert(listObj.begin(), Student(0, "Parent"));
    listItr++;
    listItr++;
    listObj.insert(listItr, Student(4, "Random"));
    std::cout << "emplace_back() / push_back() / push_front() / emplace_front() / insert :::\n" ;

    for_each(listObj.begin(), listObj.end(), [](const Student& refObj) {
        std::cout << refObj.id << "     " << refObj.name << std::endl;
    });

    //erase API
    std::cout << "list.erase() :::\n";
    auto itr  = listObj.begin();
    listObj.erase(itr, ++itr );
    listObj.erase(itr, listObj.end() );
    for_each(listObj.begin(), listObj.end(), [](const Student& refObj) {
        std::cout << refObj.id << "     " << refObj.name << std::endl;
    });

}

void removeElementViaIterating() {
    std::list<int> listOfInts( { 2, 3, 3, 4, 8, 9, 4, 6, 8, 3 });
    
    auto it  = listOfInts.begin();
    while (it != listOfInts.end())
    {
        if (*it % 3 == 0)
        {   
            //Erase API removes taking input as iterator/ iterator range
            it  = listOfInts.erase(it);
        } else {
            it++;
        }
        
    }

    //remove API takes input as value
    listOfInts.remove(8);
    print<int>("Print integers post removal of multiple of 3::", listOfInts);
    
}
void removeElementViaCriterion() {
    std::list<int> listOfInts( { 2, 3, 3, 4, 8, 9, 4, 6, 8, 3 });

    listOfInts.remove_if([] (const int& elem) {
        if (elem % 2 == 0)
        {
            return true;
        } else {
            return false;
        }
        
    });

    print<int>("Removed elements based on criterion:: ", listOfInts);
}

void getElementByIndexInList() {
    std::list<int> listOfInts( { 1,2,3,4,5,6,7,8,9, 10 });

    auto it = listOfInts.begin();
    std::advance(it, 3);
    std::cout << "Advance by 3 element:::" << *it << std::endl;

    auto itr = listOfInts.begin();
    auto pointer = std::next(itr, 3);
    std::cout << "Advance by 3 element:::" << *pointer << std::endl;
}

void searchElementInList() {


}   

//generic search

//sort list by custom comparator and lambda

void list_size_resize_maxSize_API_usage() {
    std::list<int> listOfInts( { 2, 3, 3, 4, 8, 9, 4, 6, 8, 3 });

    print<int>("\nPrint elements ::: ", listOfInts);
    std::cout << "Size: " << listOfInts.size();
    listOfInts.resize(5);
    print<int>("\nPrint elements after resize::: ", listOfInts);
    std::cout << "\nresize: " << listOfInts.size();

    
    print<int>("\nPrint elements after reserve(10)::: ", listOfInts);
}

int main()
{
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    listConstructors();

    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    ways_to_iterate_list();

    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    randomNumberGenerator();
    
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    listAPI();

    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    removeElementViaIterating();

    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    list_size_resize_maxSize_API_usage();

    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    removeElementViaCriterion();

    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    getElementByIndexInList();

    return 0;
}
