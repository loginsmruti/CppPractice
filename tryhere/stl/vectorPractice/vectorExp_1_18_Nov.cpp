#include <vector>
#include <iterator>
#include <iostream>
#include<experimental/iterator>

auto print = [](const std::string& str, std::vector<int> container) {
    std::cout << str ;
    for(const auto& elem: container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
};

auto randomNum = []()->int {
    return std::rand() % 100;
};

int main()
{
    //vector constructor
    std::vector<int> empty;
    std::vector<int> fill(4, 100);
    std::vector<int> range(fill.begin(), fill.end());
    std::vector<int> copy(range);
    std::vector<int> move(std::vector<int>({1,2,3,4,5,6,7,8,9,8,7,6}));
    std::vector<int> initializer_list({9,8,7,6,5,4,3,2,1,0});

    //iterate styles
    print("Vector contains ::: ", move);

    for(const auto& elem: move) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::vector<int>::iterator itr =  initializer_list.begin();
    while(itr != initializer_list.end()) {
        std::cout << *itr << "  ";
        itr++;
    }
    std::cout <<std::endl;

    std::copy(initializer_list.begin(), initializer_list.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << "\nReverse printing" << std::endl;
    std::vector<int>::reverse_iterator revItr= move.rbegin();
    while (revItr != move.rend())
    {
        std::cout << *revItr << " ";
        revItr ++;
    }
    std::cout << std::endl;


    std::cout << "\nPrinting via container size" << std::endl;
    for (size_t i = 0; i < range.size(); i++)
    {
        std::cout << range[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nPrinting via experimental iterator" << std::endl;
    std::copy(move.begin(), move.end(), std::experimental::make_ostream_joiner(std::cout, " "));
    std::cout << std::endl;

    std::cout << "\nPrinting via for_each" << std::endl;
    for_each(move.begin(), move.end(), [](const auto& elem) {
        std::cout << elem <<" ";
    });
    std::cout << std::endl;


    std::vector<char> charSet({'a', 'b' , 'c', 'd', 'f', 'e', 'r', 'd', 's', 
                        'a', 's', 'd', 'f', 'w', 'e', 'e', 'e', 'r', 'r' , 'r' });
    charSet.erase(std::remove(charSet.begin(), charSet.end(), 'r'), charSet.end());

    print("std::generate Applied to fill:: ", fill);
    std::generate(fill.begin(), fill.end(), randomNum);

    std::cout << std::endl;

    print("Vector ::" , move);
    //auto it = move.begin() + 3;
    auto it = move.begin();
    //it++;
    //it++;
    std::cout << *it;
    

    return 0;
}