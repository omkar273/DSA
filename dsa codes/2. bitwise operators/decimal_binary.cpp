#include <bits/stdc++.h>
using namespace std;

int binary_to_decimal(__int64 n) {
    int result = 0;
    int base = 1;
    while (n != 0) {
        int msb = n % 10;
        n /= 10;
        result += (msb * base);
        base *= 2;
    }
    return result;
}

// 5
// 101 & 1 = 1    result = 1     1*10^0
// 010 & 1 = 0    result = 01    0*10^1
// 001 & 1 = 1    result = 101   1*10^2
__int64 decimal_to_binary(__int64 n) {
    int base = 1;
    int result = 0;
    while (n) {
        int msb = n & 1;
        result += (msb * base);
        base *= 10;
        n >>= 1;
    }
    return result;
}

int main() {
    // cout << decimal_to_binary(5);

    cout << "decimal : " << decimal_to_binary(7);
    return 0;
}
