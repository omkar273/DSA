#include <bits/stdc++.h>
using namespace std;

vector<int> array_intersection(vector<int> &v1, vector<int> &v2) {
    int n = v1.size(), m = v2.size();
    int i = 0, j = 0;
    vector<int> result;

    while (i < n && j < m) {
        if (v1[i] < v2[j]) {
            i++;
        } else if (v1[i] > v2[j]) {
            j++;
        } else {
            result.push_back(v1[i]);
            i++;
            j++;
        }
    }
    for (auto &&i : result) {
        cout << i << " "; 
    }

    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {1, 3, 6 , 7, 8,};

    array_intersection(a, b);
    return 0;
}
