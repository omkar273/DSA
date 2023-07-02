#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr) {
    int low = 0, high = arr.size() - 1, mid = 0, counter = 1;
    while (mid < high) {
        while (arr[high] == 2 && mid < high) {
            high--;
        }
        while (arr[low] == 0 && low < mid) {
            low++;
        }
        while (arr[mid] == 1 && mid < high) {
            mid++;
        }
        if (arr[mid] == 0 && mid < high && low < mid) {
            swap(arr[mid], arr[low]);
            cout << "swapped " << arr[mid] << " and " << arr[low] << "at index " << mid << " & " << low << endl;
            mid++;
            low++;
        }

        if (arr[mid] == 2 && mid < high) {
            swap(arr[mid], arr[high]);
            cout << "swapped " << arr[mid] << " and " << arr[high] << "at index " << mid << " & " << high << endl;
            mid++;
            high--;
        }
        cout << "step " << counter++ << " " << endl;
        for (auto &&i : arr) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "printing sorted array :     " << endl;
    for (auto &&i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    vector<int> a = {1, 0, 0, 0, 1, 2, 1, 1, 2, 0, 2, 1};
    sort012(a);
    return 0;
}
