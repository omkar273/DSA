#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], size_t size) {
    cout << "Printing the array : " << endl;
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, *arr;
    cout << "Enter the array size : ";
    cin >> n;
    arr = new int[n];

    for (size_t i = 0; i < n; i++) {
        cout << "Enter the array element  : " << endl;
        cin >> arr[i];
    }
    printArr(arr, n);

    for (size_t i = 0; i < n - 2; i+=2) {
        swap(arr[i], arr[i + 1]);
    }
    printArr(arr, n);
    return 0;
}
