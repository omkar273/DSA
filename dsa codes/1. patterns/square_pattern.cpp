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

/*
function for printing a pattern like
1  2   3  4
5  6   7  8
9  10  11  12
*/
void pattern3(int n) {
    int count = 1;
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= n; j++) {
            cout << count++ << "  ";
        }
        cout << endl;
    }
}

/*
function for printing a pattern like
A  A  A  A
B  B  B  B
C  C  C  C
D  D  D  D
*/
void pattern4(int n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << (char)('A' + i) << "  ";
        }
        cout << endl;
    }
}

/*
function for printing a pattern like
A  B  C  D
E  F  G  H
I  J  K  L
M  N  O  P
*/
void pattern5(int n) {
    char c = 'A';
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            cout << c++ << "  ";
        }
        cout << endl;
    }
}

int main() {
    pattern5(7);
    return 0;
}
