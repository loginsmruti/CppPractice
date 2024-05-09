#include <iostream>
#include <vector>
#include <cstdint>

std::vector<bool> int_to_vector_bool(int16_t x) {
    std::vector<bool> result;
    result.reserve(16);

    for (int i = 0; i < 16; ++i) {
        result.push_back((x >> i) & 1);
    }
    return result;
}

int main() {
    int16_t my_integer = 161;
    std::vector<bool> bool_vector = int_to_vector_bool(my_integer);

    for (bool bit : bool_vector) {
        std::cout << bit;
    }
    std::cout << std::endl;

    std::vector<int> newVect;
    int position  = 1;
    bool flag =false;

    for (int i = bool_vector.size() - 1; i >= 0 ; i--) {
        
        if ( bool_vector[i] == 1) {
            flag = true;
            std::cout << bool_vector[i] << " ";
            newVect.push_back(position++);
        }
        if(flag == true) 
            position++;
    }
    std::cout << std::endl;

    for (auto &&i : newVect) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
