#include <bits/stdc++.h>

int findPartitionIndex(std::vector<int>& arr,int low, int high) 
{
    int i = low;
    int j = high;
    int pivot = arr[low];

    while(i  < j) {
        while(pivot >= arr[i] && i <= high -1) {
            i++;
        }

        while(pivot < arr[j] && j >= low +1) {
            j--;
        }
        if (i < j)
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);
    return j;
}


void applyQuickSort(std::vector<int>& arr , int low, int high) {

    if(low < high) {

       int pIndex =  findPartitionIndex(arr, low, high);
       
       applyQuickSort(arr, 0, pIndex -1);

       applyQuickSort(arr, pIndex +1, high);
    }

}


std::vector<int> quickSort(std::vector<int> & arr) {

    applyQuickSort(arr, 0, arr.size() - 1);

    return arr;
}

int main()
{
    std::vector<int> arr({4, 6, 2, 5, 7, 9, 1, 3});

    std::cout << "Before Using quick Sort: " << std::endl;
    for(const int& val: arr ) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    arr = quickSort(arr);
    std::cout << "After Using quick sort: " << "\n";
    for(const int& num: arr ) {
        std::cout << num << ", ";
    }
    std::cout << "\n";
    return 0;
}


