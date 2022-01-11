/*
1269. Number of Ways to Stay in the Same Place After Some Steps
Hard

You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array or stay in the same place  (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer still at index 0 after exactly steps steps.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

Example 2:
Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

Example 3:
Input: steps = 4, arrLen = 2
Output: 8

Constraints:
1 <= steps <= 500
1 <= arrLen <= 10^6
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
    static constexpr int mod = 1000000007;

    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps/2+1);
        vector<int> dp(arrLen, 0);
        dp[0] = 1;
        for (int i = 0; i < steps; ++i) {
            vector<int> dp2(arrLen, 0);
            for (int j = 0; j < arrLen; ++j) {
                for (int offset: {-1, 0, 1}) {
                    int k = j + offset;
                    dp2[j] = (dp2[j] + ((k >= 0 && k < arrLen) ? dp[k] : 0)) % mod;
                }
            }
            dp = dp2;
        }
        return dp[0];
    }
};

int main() {
    Solution sol;
    return 0;
}
