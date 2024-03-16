#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

  bool compare(std::pair<char, int> a, std::pair<char, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
  }

class Solution {
public: 


  string bucketSortCars(string cars) {
    std::unordered_map<char, int> freq;
    for (char c : cars) {
        freq[c]++;
    }
    std::vector<std::pair<char, int>> v;
    for (auto p : freq) {
        v.push_back(p);
    }
    std::sort(v.begin(), v.end(), [this] (std::pair<char, int> a, std::pair<char, int> b) {
        if (a.second == b.second) {
        return a.first < b.first;
    }
        return a.second > b.second;
    });
    std::string result = "";
    for (auto p : v) {
        for (int i = 0; i < p.second; i++) {
            result += p.first;
        }
    }
    return result;
  }
};

int main () {

    Solution sol;
    std::cout << sol.bucketSortCars("ssgysyqa") << std::endl;

};