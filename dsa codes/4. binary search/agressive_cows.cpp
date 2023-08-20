/*
The "Aggressive Cows" problem is a classic algorithmic problem that can be stated as follows:

**Problem Statement:**

You are given a set of stalls, each with a specific position along a straight line. You have a certain number of cows and want to place them in the stalls in such a way that the minimum distance between any two cows is maximized. The goal is to find the maximum minimum distance (minimum distance between any two cows) that can be achieved by placing the cows optimally.

Formally, you are given:

1. An array `stalls[]` representing the positions of the stalls along a straight line.
2. An integer `cows` representing the number of cows available.

Your task is to find the maximum minimum distance that can be achieved by placing the cows optimally in the stalls.

Key points to consider in this problem:

1. Each stall can have at most one cow.
2. The order of the cows and the stalls cannot be changed.
3. All cows must be placed in the stalls, and each stall can have at most one cow.
4. The minimum distance between any two cows should be maximized.

**Example:**

Consider the following example:

```
stalls[] = {1, 2, 4, 8, 9}
cows = 3
```

In this case, the optimal way to place the cows is as follows:

- Place the first cow at stall position 1.
- Place the second cow at stall position 4.
- Place the third cow at stall position 8.

The minimum distance between any two cows is 3 (between the first and second cows), and this is the maximum minimum distance that can be achieved.

**Solution:**

This problem can be solved using various techniques, but a common approach is to use binary search to find the maximum minimum distance. Here's a high-level outline of the solution:

1. Initialize `start` to 0 (minimum possible minimum distance) and `end` to the maximum possible distance between stalls (e.g., the maximum stall position minus the minimum stall position).

2. Perform a binary search in the range `[start, end]`.

3. In each iteration of the binary search, calculate `mid` as the average of `start` and `end`.

4. Check if it's possible to place the cows in such a way that the minimum distance between any two cows is at least `mid`. This can be done by iterating through the stalls and checking if cows can be placed while maintaining this minimum distance.

5. If it's possible, update `start = mid + 1` to search for a larger minimum distance. Otherwise, update `end = mid - 1` to search for a smaller minimum distance.

6. Continue the binary search until `start` becomes greater than `end`.

7. The value of `end` will be the maximum minimum distance that can be achieved by placing the cows optimally.

The binary search approach allows you to efficiently find the maximum minimum distance while minimizing the search space.

*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> stall, int no_cow, int min_distance) {
    int cows_placed = 1;
    int lastPos = stall[0];
    for (size_t i = 1; i < stall.size(); i++) {
        if (cows_placed == no_cow) return true;
        if (stall[i] - lastPos >= min_distance) {
            cows_placed++;
            lastPos = stall[i];
        }
    }
    return false;
}

int findMaxMinDistance(vector<int>& stall, int no_cows) {
    sort(stall.begin(), stall.end());
    int start = 0;
    int end = stall.back() - stall.front();
    int mid;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (isPossible(stall, no_cows, mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return mid;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int result = findMaxMinDistance(stalls, 3);

    if (result != 0) {
        std::cout << "Maximum minimum distance: " << result << std::endl;
    } else {
        std::cout << "It's not possible to place all cows with the given constraints." << std::endl;
    }
    return 0;
}
