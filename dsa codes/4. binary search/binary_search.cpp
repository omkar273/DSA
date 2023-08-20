#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> arr, int key) {
    int start = 0, end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int compare = 0;

    while (start <= end) {
        compare++;
        if (arr[mid] == key) {
            return key;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return INTPTR_MIN;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    binary_search(v1, 63);
    return 0;
}
