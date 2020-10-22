/*
1621. Number of Sets of K Non-Overlapping Line Segments
Medium

Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can
draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of
each segment must have integral coordinates. The k line segments do not have to cover all n points, and they
are allowed to share endpoints.

Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge,
return it modulo 10^9 + 7.

Example 1:
Input: n = 4, k = 2
Output: 5
Explanation:
The two line segments are shown in red and blue.
The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)},
{(0,1),(1,2)}.

Example 2:
Input: n = 3, k = 1
Output: 3
Explanation: The 3 ways are {(0,1)}, {(0,2)}, {(1,2)}.

Example 3:
Input: n = 30, k = 7
Output: 796297179
Explanation: The total number of possible ways to draw 7 line segments is 3796297200. Taking this number modulo 109 + 7 gives us 796297179.

Example 4:
Input: n = 5, k = 3
Output: 7

Example 5:
Input: n = 3, k = 2
Output: 1

Constraints:
2 <= n <= 1000
1 <= k <= n-1
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
#include <regex>
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
    static constexpr int MOD = 1000000007;

    int count(int n, int k) {
        if (k == 1) {
            return n*(n-1)/2;
        }

        auto& res = dp[n][k];
        if (res >= 0)
            return res;

        res = 0;
        for (int i = 1; n - i > k-1; ++i) {
            long long t = (static_cast<long long>(i) * count(n-i, k-1)) % MOD;
            res = (res + t) % MOD;
        }

        return res;
    }

    vector<vector<int>> dp;

    int numberOfSets(int n, int k) {
        dp.clear();
        dp.resize((n+1), vector<int>(k+1, -1));

        return count(n, k);
    }
};

int main() {
    int n, k;

    // Output: 5
    Solution sol;
    n = 4, k = 2;
    cout << sol.numberOfSets(n, k) << endl;

    // Output: 3
    n = 3, k = 1;
    cout << sol.numberOfSets(n, k) << endl;

    // Output: 7
    n = 5, k = 3;
    cout << sol.numberOfSets(n, k) << endl;

    // Output: 15
    n = 5, k = 2;
    cout << sol.numberOfSets(n, k) << endl;

    // Output: 66
    n = 8, k = 5;
    cout << sol.numberOfSets(n, k) << endl;

    // Output: 286
    n = 9, k = 5;
    cout << sol.numberOfSets(n, k) << endl;

    // Output: 15
    n = 10, k = 2;
    cout << sol.numberOfSets(n, k) << endl;

    // Output: 796297179
    n = 30, k = 7;
    cout << sol.numberOfSets(n, k) << endl;

    // Output: 513360177
    n = 311, k = 109;
    cout << sol.numberOfSets(n, k) << endl;

    return 0;
}
