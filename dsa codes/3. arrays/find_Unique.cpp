#include <bits/stdc++.h>
using namespace std;
int findUnique(int arr[], int size) {
    // unordered_map<int, int> map;
    // for (size_t i = 0; i < size; i++) {
    //     if (map.find(arr[i]) == map.end()) {
    //         map.insert({arr[i], 1});
    //     } else {
    //         map[arr[i]] += 1;
    //     }
    // }
    // for (auto i : map) {
    //     if (i.second == 1) return i.first;
    // }

    // when we xor 2 same valules it cancels out
    //  2^2 = 0
    int ans = 0;
    for (size_t i = 0; i < size; i++) {
        ans ^= arr[i];
    }
    return ans;
}
int main() {
    int arr[] = {1, 3, 1, 3, 6, 6, 7, 10, 7};
    cout << findUnique(arr, 9);
    return 0;
}
