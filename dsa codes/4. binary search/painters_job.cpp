/*
The "Famous Painters' Job" problem is a classic algorithmic problem that can be stated as follows:

**Problem Statement:**

You are given a set of boards, each with a specific length, and a set of painters. Each painter takes a unit of time to paint one unit of length. The task is to assign boards to painters in such a way that each board is painted by exactly one painter, and the time taken to paint all the boards is minimized. Each painter can paint consecutive boards only, and a painter cannot paint more than one board at the same time.

Formally, you are given an array `boards[]` representing the lengths of the boards and an integer `k` representing the number of painters. You need to find the minimum time required to paint all the boards, such that the division of work among painters is such that the maximum sum of lengths assigned to a painter is minimized.

Here are some key points to consider in this problem:

1. Each painter must be assigned at least one board.
2. The order of boards cannot be changed; they must be painted in the same order as they are given in the array.
3. The painters work in parallel, meaning multiple painters can paint boards simultaneously.

Solving this problem typically involves using optimization techniques such as binary search to efficiently find the minimum time required.

A common algorithm for solving this problem is to use binary search to find the minimum and maximum possible values for the time required to paint the boards. Then, iteratively search for the optimal time that minimizes the maximum sum of lengths assigned to a painter.

This problem has various real-world applications, such as scheduling tasks in parallel processing systems or optimizing the allocation of resources in manufacturing processes.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPossible(const vector<int>& board, int no_painters, ll maxTime) {
    ll currentMaxTime = 0;
    int noPaintersRequired = 1;

    for (int i = 0; i < board.size(); i++) {
        if (noPaintersRequired >= no_painters || board[i] > maxTime) {
            return false;
        } else if (currentMaxTime + board[i] <= maxTime) {
            currentMaxTime += board[i];
        } else {
            noPaintersRequired++;
            currentMaxTime = board[i];
        }
    }

    return true;
}

ll findMinTimeRequired(const vector<int>& board, int k) {
    if (k > board.size()) {
        return -1;
    }

    ll start = *max_element(board.begin(), board.end());
    ll end = accumulate(board.begin(), board.end(), 0LL);

    while (start <= end) {
        ll mid = start + (end - start) / 2;
        if (isPossible(board, k, mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return start;
}

int main() {
    vector<int> board = {1, 2, 3};
    cout << findMinTimeRequired(board, 2) << endl;
    return 0;
} 
