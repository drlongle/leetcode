/*
629. K Inverse Pairs Array
Hard

For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length
and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n
such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 10^9 + 7.

Example 1:
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.

Example 2:
Input: n = 3, k = 1
Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.

Constraints:
1 <= n <= 1000
0 <= k <= 1000
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    using ll = long long;
    static constexpr int MOD = 1000000007;
    static constexpr int max_size = 1002;
    vector<vector<ll>> dp;
    vector<ll> prefix;

    int kInversePairs(int N, int K) {
        dp.clear();
        dp.resize(max_size, vector<ll>(max_size, 0));
        prefix.clear();
        prefix.resize(max_size, 0);
        for (int n = 1; n <= N; ++n) {
            dp[n][0] = 1;
            for (int k = 1; k <= K; ++k) {
                int start = min(n, k + 1);
                dp[n][k] = (prefix[k] - (k >= start ? prefix[k-start] : 0)) % MOD;
            }
            partial_sum(dp[n].begin(), dp[n].begin() + K + 2, prefix.begin());
        }

        return dp[N][K] % MOD;
    }
};

int main() {
    Solution sol;
    int n, k;

    // Output: 1
    n = 3, k = 0;
    cout << sol.kInversePairs(n, k) << endl;

    // Output: 2
    n = 3, k = 1;
    cout << sol.kInversePairs(n, k) << endl;

    // Output: 2
    n = 3, k = 2;
    cout << sol.kInversePairs(n, k) << endl;

    // Output: 1
    n = 3, k = 3;
    cout << sol.kInversePairs(n, k) << endl;

    n = 1000, k = 1000;
    cout << sol.kInversePairs(n, k) << endl;

    return 0;
}
