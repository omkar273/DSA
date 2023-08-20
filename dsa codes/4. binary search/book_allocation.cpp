/*
You are given an array pages[] of length n, representing the number of pages in n different books, and an integer m, representing the number of students. You have to allocate books to m students in such a way that

1. each student gets at least one book
2. maximum number of pages assigned to a student is minimized.

Find the minimum possible maximum number of pages a student can have while allocating books optimally.
*/
// max min type
#include <bits/stdc++.h>
using namespace std;

// 10 20 30 40
bool isPossible(vector<int> &book, int no_students, int maxPages) {
    int currentMaxPages = 0, noPartition = 1;
    for (size_t i = 0; i < book.size(); i++) {
        if (noPartition >= no_students || book[i] > maxPages) {
            return false;
        } else if (currentMaxPages + book[i] < maxPages) {
            currentMaxPages += book[i];
        } else {
            currentMaxPages = book[i];
            noPartition++;
        }
    }
    return true;
}

int findMinimalNumberOfPages(vector<int> &book, int m) {
    // not possible to allocate the books as no of books is less than the no of students
    if (m > book.size()) {
        return -1;
    }

    int start = *max_element(book.begin(), book.end());
    int end = accumulate(book.begin(), book.end(), 0);

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(book, m, mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return end;
}

int main() {
    vector<int> books = {1, 2, 3, 4};
    cout << findMinimalNumberOfPages(books, 2) << endl;
    return 0;
}
