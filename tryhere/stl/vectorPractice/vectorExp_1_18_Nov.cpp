#include <vector>
#include <iterator>
#include <iostream>
#include<experimental/iterator>

template <typename T>
auto print = [](const std::string& str, std::vector<T> container) {
    std::cout << str ;
    for(const auto& elem: container) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
};

template <typename T>
auto print2DMattrix = [] (const std::string& str, std::vector<std::vector<T>> matrix) {
    std::cout << str ;
    for_each(matrix.begin(), matrix.end(), [] (const auto& row) {
        for_each(row.begin(), row.end(), [](const auto& col) {
            std::cout << col << " ";
        });
        std::cout << std::endl;
    });
};

auto randomNum = []()->int {
    return std::rand() % 100;
};

void vectorConstructor() {
    //vector constructor
    std::vector<int> empty;
    std::vector<int> fill(4, 100);
    std::vector<int> range(fill.begin(), fill.end());
    std::vector<int> copy(range);
    std::vector<int> moveVect(std::vector<int>({1,2,3,4,5,6,7,8,9,8,7,6}));

    print<int>("VectorConstructor::: ", moveVect);

}


void iterate_ways() {

    std::vector<int> empty;
    std::vector<int> fill(4, 100);
    std::vector<int> range(fill.begin(), fill.end());
    std::vector<int> copy(range);
    std::vector<int> move(std::vector<int>({1,2,3,4,5,6,7,8,9,8,7,6}));

    std::vector<int> initializer_list({9,8,7,6,5,4,3,2,1,0});

    //iterate styles
    print<int>("Vector contains ::: ", move);

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

}


void randomNumberGenerator() {
    std::vector<int> randNumVector(10);
    std::generate(randNumVector.begin(), randNumVector.end(), randomNum);

    print<int>("randomNumberGenerator::: ", randNumVector);
}


void removeDuplicateCharacterFromVector() {

    std::vector<char> charVect({'a', 'b' , 'c', 'd', 'f', 'e', 'r', 'd', 's', 
                        'a', 's', 'd', 'f', 'w', 'e', 'e', 'e', 'r', 'r' , 'r' });

    print<char>("removeDuplicateCharacterFromVector:::Vector Before:: ", charVect);
    charVect.erase(std::remove(charVect.begin(), charVect.end(), 'r'), charVect.end());

    print<char>("removeDuplicateCharacterFromVector:::Vector Before:: ", charVect);
}


void iterate_2d_vector() {
    std::vector<std::vector<int>> initialize({{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                                {9, 8, 7, 6, 5, 4, 3, 2, 1},
                                                {5, 4, 3, 2, 1, 6, 7, 8, 9},
                                                {1, 3, 4, 5, 8, 1, 9, 2, 6},
                                                {3, 1, 7, 6, 8, 3, 9, 1, 5},
                                                {4, 2, 7, 9, 7, 1, 6, 3, 8}});
    std::cout << "Iterate 2-D vector range based loop::" << std::endl;
    for (auto &&row : initialize)
    {
        for (auto &&elem : row)
        {
            std::cout <<  elem << " ";  
        }
        std::cout << std::endl;
    }

    std::cout << "\nIterate 2-D vector -+ for_each way iteration style - 2 +-\n"<< std::endl;
    //for_each way iteration
    for_each(initialize.begin(), initialize.end(), [](const auto& row) {
        std::copy(row.begin(), row.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    });

    std::cout << "\nIterate 2-D vector -+ for_each way iteration style - 2  +-\n"<< std::endl;

    //for_each 2nd way iteration
    for_each(initialize.begin(), initialize.end(), [](const auto& row) {
        for_each(row.begin(), row.end(), [](const auto& cols) {
            std::cout << cols << " ";
        });
        std::cout << std::endl;
    });


}

void vector2DInitialize() {

    std::vector<std::vector<int>> vec;

    vec.assign({{1, 2, 3, 4, 5, 6, 7, 8, 9}, 
                {9, 8, 7, 6, 5, 4, 3, 2, 1},
                {5, 4, 3, 2, 1, 6, 7, 8, 9},
                {1, 3, 4, 5, 8, 1, 9, 2, 6},
                {3, 1, 7, 6, 8, 3, 9, 1, 5},
                {4, 2, 7, 9, 7, 1, 6, 3, 8}
                });
    
    std::vector<std::vector<int>> initialize({{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                                {9, 8, 7, 6, 5, 4, 3, 2, 1},
                                                {5, 4, 3, 2, 1, 6, 7, 8, 9},
                                                {1, 3, 4, 5, 8, 1, 9, 2, 6},
                                                {3, 1, 7, 6, 8, 3, 9, 1, 5},
                                                {4, 2, 7, 9, 7, 1, 6, 3, 8}});
    constexpr int16_t rows = 5;
    constexpr int16_t cols = 5;
    constexpr int16_t defaultVal = 100;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, defaultVal));

    print2DMattrix<int>("2-D Vector initialized:::\n",  matrix);

    constexpr int16_t row1{5};
    constexpr int16_t col1(4);
    std::vector<std::vector<int>> mat(row1);
    int16_t val{0};
    for(auto&& row: mat) {
        row.resize(col1, val++);
    }
    print2DMattrix<int>("\n\nInitialize[matrix resize] 2d Vector with different values in each rows:::\n", mat);

    std::vector<std::vector<int>> matrixResize;

    matrixResize.resize(row1, std::vector<int>(col1, defaultVal+1));

    print2DMattrix<int>("\nInitialize[matrix resize] 2d Vector with same values in each rows:::\n", matrixResize);

}


int main()
{
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    vectorConstructor();
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;

    iterate_ways();
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;

    randomNumberGenerator();
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;

    removeDuplicateCharacterFromVector();
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    vector2DInitialize();

    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    iterate_2d_vector();

    return 0;
}