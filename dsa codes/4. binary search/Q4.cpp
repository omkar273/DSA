// find a function to find a element in the rotated sorted array

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, size_t start, size_t end, int key) {
    while (end >= start) {
        size_t mid = start + (end - start) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int findPivot(vector<int>& arr, int key) {
    size_t start = 0, end = arr.size() - 1;
    while (start < end) {
        size_t mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    if (key >= arr[start]) {
        return binarySearch(arr, 0, start - 1, key);
    } else {
        return binarySearch(arr, start, arr.size() - 1, key);
    }
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 1, 2, 3, 4};
    int key = 85;
    int result = findPivot(arr, key);
    if (result != -1) {
        cout << "Element " << key << " found at index " << result << endl;
    } else {
        cout << "Element " << key << " not found in the array" << endl;
    }
    return 0;
}
