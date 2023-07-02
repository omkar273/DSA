// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++) {
        mpp[arr[i]]++;
    }

    unordered_map<int, int> mpp2;
    for (auto& i : mpp) {
        if (mpp2.find(i.second) != mpp2.end()) {
            return false;
        }
        mpp2[i.second];
    }

    return true;
}
int main() {
    vector<int> arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << uniqueOccurrences(arr) << endl;
    return 0;
}
