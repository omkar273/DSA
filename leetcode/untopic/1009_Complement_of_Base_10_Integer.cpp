/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer n, return its complement.


Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10

*/
#include <bits/stdc++.h>
using namespace std;

// input : 5   00....101
// ouput : 5   00....010
// 000......101 ----> 1111....00010 invert all 0 - 1
//  now if we add a mask value like 00000.....111 and perform bitwise addition it will give us 10;
//

int bitwiseComplement(int n) {
    if (n == 0) return 1;  // edge case
    int temp = n;
    int mask = 0;

    // creating the mask value
    while (temp) {
        temp >>= 1;
        mask = (mask << 1) | 1;
    }
    return (~n) & mask;

    cout << mask << endl;
}
int main() {
    cout << bitwiseComplement(5);
    return 0;
}
