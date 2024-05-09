#include <vector>
#include <iostream>
#include <unordered_map>

int singleNonDuplicate(std::vector<int>& arr)
{
	std::unordered_map<int, int> unMap;
	for(const auto& val: arr) {
        if(unMap.count(val) == 1)
	        unMap[val] = unMap[val] + 1;
        else
            unMap[val] = 1;
	}

    for (auto &&i : unMap) {
        //std::cout << i.first << ":" << i.second << std::endl;
        if(i.second == 1)
            return i.first;
    }
}

int main() {
    std::vector<int> arr({1, 1, 4, 4, 15});

    std::cout << singleNonDuplicate(arr);

    return 0;
}