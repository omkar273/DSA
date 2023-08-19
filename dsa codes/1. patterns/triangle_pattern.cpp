#include <bits/stdc++.h>
using namespace std;

/*
function for printing a pattern like
*
***
****
******
*/
void pattern1(int n) {
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= i; j++) {
            cout << "*  ";
        }
        cout << endl;
    }
}

/*
function for printing a pattern like
A
B C
D E F
G H I J
*/
void pattern2(int n) {
    char c = 'A';
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < i; j++) {
            cout << c++ << "  ";
        }
        cout << endl;
    }
}

/*
function for printing a pattern like
D
C D
B C D
A B C D
*/
void pattern3(int n) {
    for (size_t i = 1; i <= n; i++) {
        char c = 'A' + n - i;
        for (size_t j = 0; j < i; j++) {
            cout << char(c + j) << " ";
        }
        cout << endl;
    }
}

/*
function for printing a pattern like
---    *
--   * *
-  * * *
 * * * *
*/
void pattern4(int n) {
    for (size_t i = 1; i <= n; i++) {
        int no_spaces = n - i;
        for (size_t j = 1; j <= no_spaces; j++) {
            cout << "  ";
        }
        for (size_t k = 1; k <= i; k++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
function for printing a pattern like
*  *  *  *
*  *  *
*  *
*

*/
void pattern5(int n) {
    for (size_t i = n; i > 0; i--) {
        for (size_t j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
function for printing a pattern like
        1
      1 2 1
    1 2 3 2 1
  1 2 3 4 3 2 1

*/
void pattern6(int n) {
    for (size_t i = 1; i <= n; i++) {
        // for spaces
        for (size_t j = 0; j < n - i; j++) {
            cout << "  ";
        }
        int count = 1;
        for (size_t k = 1; k <= i; k++) {
            cout << k << " ";
        }
        for (size_t l = i - 1; l > 0; l--) {
            cout << l << " ";
        }

        cout << endl;
    }
}

int main() {
    pattern6(5);
    return 0;
}
