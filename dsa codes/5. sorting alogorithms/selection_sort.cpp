// selection sort

#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>& arr) {
    int n = arr.size();  // Store the size of the vector to avoid redundant calls
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[minIndex], arr[i]);
        }
    }
}

int main() {
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    selectionSort(arr);

    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
