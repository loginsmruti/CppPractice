#include <bits/stdc++.h>

void merge(std::vector<int>& arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    std::vector<int> temp;

    while(left <= mid && right <= high) {

        if( arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(std::vector<int> & arr, int low, int high) {

    if(low >= high) 
        return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high );
}

int main()
{
    std::vector<int> arr({4, 6, 2, 5, 7, 9, 1, 3});

    std::cout << "Before Using Merge Sort: " << std::endl;
    for(const int& val: arr ) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "After Using Merge sort: " << "\n";
    for(const int& num: arr ) {
        std::cout << num << ", ";
    }
    std::cout << "\n";
    return 0;
}

