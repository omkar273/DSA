#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &a) {
    int lo = 0;
    int hi = a.size() - 1;
    int mid = 0;

    while (mid <= hi) {
        switch (a[mid]) {
            // If the element is 0
            case 0:
                swap(a[lo++], a[mid++]);
                break;

            // If the element is 1 .
            case 1:
                mid++;
                break;

            // If the element is 2
            case 2:
                swap(a[mid], a[hi--]);
                break;
        }
    }
    cout << "printing sorted array :     " << endl;
    for (auto &&i : a) {
        cout << i << " ";
    }
    cout << endl;
}

void sort0122(int a[], int arr_size) {
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= hi) {
        switch (a[mid]) {
            // If the element is 0
            case 0:
                swap(a[lo++], a[mid++]);
                break;

            // If the element is 1 .
            case 1:
                mid++;
                break;

            // If the element is 2
            case 2:
                swap(a[mid], a[hi--]);
                break;
        }
    }
}

void printArray(int arr[], int arr_size) {
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}
int main() {
    vector<int> a = {1, 0, 0, 0, 1, 2, 1, 1, 2, 0, 2, 1};
    int arr[] = {1, 0, 0, 0, 1, 2, 1, 1, 2, 0, 2, 1};
    sort012(a);
    // printArray(arr, 12);

    return 0;
}
