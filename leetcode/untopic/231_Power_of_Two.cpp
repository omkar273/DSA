// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x

// Input: n = 1
// Output: true
// Explanation: 20 = 1

// Input: n = 16
// Output: true
// Explanation: 24 = 16

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    for (size_t i = 0; i < 31; i++) {
        if (n == pow(2, i)) return true;
    }
    return false;
}
int main() {
    cout << isPowerOfTwo(8);
    return 0;
}
