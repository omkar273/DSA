/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
*/
#include <bits/stdc++.h>
using namespace std;

int mySqrtInteger(int x) {
    if (x == 0) return 0;  // Handle special case

    long long int start = 1, end = x;
    while (start <= end) {
        long long int mid = start + (end - start) / 2;
        if (mid == x / mid) {
            return static_cast<int>(mid);
        } else if (mid < x / mid) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return static_cast<int>(end);  // Return the floor value
}

double preciseSqrt(int x,  double intResult, int precision) {
    double factor = 1;
    for (size_t i = 0; i < precision; i++) {
        factor /= 10;
        for (double j = 0; j < x / j; j += factor) {
            intResult = j;
        }
    }
    return intResult;
}

int main() {
    cout << preciseSqrt(107, mySqrtInteger(107), 8);
    return 0;
}
