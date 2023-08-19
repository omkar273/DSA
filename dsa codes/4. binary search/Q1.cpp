// find first and last position of element in array

#include <bits/stdc++.h>
using namespace std;

int last_position(vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int index = -1;

    while (start <= end) {
        if (arr[mid] == key) {
            index = mid;
            start = mid + 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else if (key < arr[mid]) {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return index;
}

int first_position(vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    int mid = (start + end) / 2;
    int index = -1;

    while (start <= end) {
        if (arr[mid] == key) {
            index = mid;
            end = mid - 1;
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else if (key < arr[mid]) {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return index;
}

pair<int, int> first_last_position(vector<int>& arr, int key) {
    pair<int, int> p;
    p.first = first_position(arr, key);
    p.second = last_position(arr, key);
    cout << "First occurence is at " << p.first << " and last is at " << p.second << endl;
    return p;
}

int main() {
    vector<int> arr = {1, 2, 3, 5};
    first_last_position(arr, 5);
    return 0;
}