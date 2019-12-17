/*
1289. Minimum Falling Path Sum II
Hard

Given a square grid of integers arr, a falling path with non-zero shifts is a choice of exactly
one element from each row of arr, such that no two elements chosen in adjacent rows are in the
same column.

Return the minimum sum of a falling path with non-zero shifts.

Example 1:

Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.

Constraints:
1 <= arr.length == arr[i].length <= 200
-99 <= arr[i][j] <= 99
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int sz = arr.size();
        vector<vector<int>> dp(sz, vector<int>(sz, numeric_limits<int>::max()));
        dp[0] = arr[0];
        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                for (int k = 0; k < sz; ++k) {
                    if (k != j) {
                        dp[i][j] = min(dp[i][j], arr[i][j] + dp[i-1][k]);
                    }
                }
            }
        }

        auto it = min_element(begin(dp[sz-1]), end(dp[sz-1]));
        return *it;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr;
    
    arr = {{1,2,3},{4,5,6},{7,8,9}};

    cout << "Result: " << sol.minFallingPathSum(arr) << endl;
    
    return 0;
}
