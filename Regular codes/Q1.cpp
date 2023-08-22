/***1***
 *
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
#include <bits/stdc++.h>
using namespace std;

// time complexity O(n^2)
vector<int> indices(vector<int> arr, int target) {
    vector<int> temp;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] + arr[i] == target) {
                temp.push_back(i);
                temp.push_back(j);
                return temp;
            }
        }
    }
    // returns -1 if no such values exist in the array
    temp.push_back(-1);
    return temp;
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    vector<int> indice = indices(arr, 89);
    for (auto &&i : indice) {
        cout << i << " ";
    }

    return 0;
}
