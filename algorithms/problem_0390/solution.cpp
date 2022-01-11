/*
390. Elimination Game
Difficulty: Medium

There is a list of sorted integers from 1 to n. Starting from left to right,
remove the first number and every other number afterward until you reach the end
of the list.

Repeat the previous step again, but this time from right to left, remove the
right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left,
until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
*/

#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int remain(int n, bool left) {
        if (n == 1)
            return 1;
        if (left)
            return 2 * remain(n/2, false);
        else if (n % 2 == 0)
            return 2 * (remain(n/2, true) - 1) + 1;
        else
            return 2 * remain(n/2, true);
    }
    
    int lastRemaining(int n) {
        return remain(n, true);
    }
};

int main(int argc, char** argv) {
    Solution sol;
    int n;

    // Expected: 6
    n = 8;

    // Expected: 6
    //n = 12;
    cout << n << " -> " << sol.lastRemaining(n) << endl;
    
    return 0;
}
