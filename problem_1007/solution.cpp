/*
1007. Minimum Domino Rotations For Equal Row
Medium

In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the i-th domino, so that A[i] and B[i] swap values.

Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.

If it cannot be done, return -1.

Example 1:
Input: A = [2,1,2,4,2,2], B = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by A and B: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

Example 2:
Input: A = [3,5,1,2,3], B = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.

Note:
1 <= A[i], B[i] <= 6
2 <= A.length == B.length <= 20000
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<vector<int>> count(7, vector<int>(3, 0));
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            ++count[A[i]][0];
            ++count[B[i]][1];
            if (A[i] == B[i])
                ++count[A[i]][2];
        }

        int res = numeric_limits<int>::max();
        for (int i = 1; i <= 6; ++i) {
            if (count[i][0] + count[i][1] - count[i][2] >= n) {
                int changes = n - max(count[i][0], count[i][1]);
                res = min(res, changes);
            }
        }

        return res == numeric_limits<int>::max() ? -1 : res;
    }
};

int main() {
    Solution sol;
    vector<int> A, B;

    // Output: 2
    A = {2,1,2,4,2,2}, B = {5,2,6,2,3,2};
    cout << sol.minDominoRotations(A, B) << endl;

    // Output: -1
    A = {3,5,1,2,3}, B = {3,6,3,3,4};
    cout << sol.minDominoRotations(A, B) << endl;

    return 0;
}
