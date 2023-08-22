/*****2****Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
    Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation:
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> triplet(vector<int> arr) {
    vector<int> temp;
    for (size_t i = 0; i < arr.size() - 2; i++) {
        for (size_t j = i + 1; j < arr.size() - 1; j++) {
            for (size_t k = j + 1; k < arr.size(); k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(k);
                }
            }
        }
    }

    // returns -1 if no such values exist in the array
    if (temp.empty()) {
        temp.push_back(-1);
    }
    return temp;
}
int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<int> indice = triplet(arr);
    for (auto &&i : indice) {
        cout << i << " ";
    }
    return 0;
}
