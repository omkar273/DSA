#include <bits/stdc++.h>
using namespace std;

/*
function for printing a pattern like
1  2  3  4
1  2  3  4
1  2  3  4
1  2  3  4
*/
void pattern1(int n) {
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            cout << j << "  ";
        }
        cout << endl;
    }
}

/*
function for printing a pattern like
4  3  2  1
4  3  2  1
4  3  2  1
4  3  2  1
*/
void pattern2(int n) {
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = n; j > 0; j--) {
            cout << j << "  ";
        }
        cout << endl;
    }
}

int main() {
    pattern2(5);
    return 0;
}
