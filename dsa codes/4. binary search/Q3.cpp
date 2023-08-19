#include <bits/stdc++.h>
using namespace std;

// time complexity : O(log N)
// space complexity : O(1)
int pivotIndex(vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

int main() {
    vector<int> arr = {8, 10, 11, 1, 2, 3};
    cout << arr[pivotIndex(arr) - 1] << endl;
    return 0;
}
