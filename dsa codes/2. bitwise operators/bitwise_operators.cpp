#include <bits/stdc++.h>
using namespace std;
int main() {
    
    cout << "bitwise and of 2 and 3 : " << (2 & 3) << endl;
    cout << "bitwise or of 2 and 3 : " << (2 | 3) << endl;
    cout << "bitwise not of 2 : " << (~3) << endl;
    cout << "bitwise Ex-or of 2 and 3 : " << (2 ^ 3) << endl;


    // shifting operators
    // left shift : multipy by 2
    // right shift : divide by 2
    cout << "left shift of 2 : " << (2 << 1) << endl;   // it means left shift 2 1 times
    cout << "right shift of 36 : " << (36 >> 3) << endl;  // it means right shift 2 3 times
    return 0;
}
