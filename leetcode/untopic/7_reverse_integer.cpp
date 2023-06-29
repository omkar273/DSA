/*
 *Given a signed 32-bit integer x, return x with its digits reversed. If reversing x *causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then *return 0.
 *
 *Assume the environment does not allow you to store 64-bit integers (signed or *unsigned).
 *
 *Input: x = 123
 *Output: 321
 *
 *Input: x = -123
 *Output: -321
 *
 *Input: x = 120
 *Output: 21
 */
#include <bits/stdc++.h>

using namespace std;

int reverse(int n) {
    int result = 0;
    while (n) {
        int last_digit = n % 10;
        n /= 10;
        if ((result < INT_MIN / 10 || result > INT_MAX / 10)) return 0;
        result = result * 10 + last_digit;
    }
    return result;
}
int main() {
    cout << "reverse : " << reverse(-89988);
    return 0;
}
