// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

#include <bits/stdc++.h>
using namespace std;

// vector<int> findDuplicates(vector<int>& nums) {
//     unordered_map<int, int> map;
//     vector<int> result;
//     for (size_t i = 0; i < nums.size(); i++) {
//         map[nums[i]]++;
//         if (nums[i] == 2) result.push_back(nums[i]);
//     }

//     for (size_t i = 0; i < result.size(); i++) {
//         cout << result[i] << " ";
//     }

//     return result;
// }

vector<int> findDuplicates(vector<int>& nums) {
    unordered_map<int, int> map;
    vector<int> result;
    for (size_t i = 0; i < nums.size(); i++) {
        if (map[nums[i]] == 1) result.push_back(nums[i]);
        map[nums[i]]++;
    }
    return result;
}

int main() {
    vector<int> v = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> v2 = findDuplicates(v);
    for (size_t i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }

    return 0;
}
