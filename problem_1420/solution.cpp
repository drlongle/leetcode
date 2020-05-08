/*
1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
Hard

Given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:

You should build the array arr which has the following properties:

* arr has exactly n integers.
* 1 <= arr[i] <= m where (0 <= i < n).
* After applying the mentioned algorithm to arr, the value search_cost is equal to k.
* Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

Example 1:
Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]

Example 2:
Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned conditions.

Example 3:
Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]

Example 4:
Input: n = 50, m = 100, k = 25
Output: 34549172
Explanation: Don't forget to compute the answer modulo 1000000007

Example 5:
Input: n = 37, m = 17, k = 7
Output: 418930126

Constraints:
1 <= n <= 50
1 <= m <= 100
0 <= k <= n
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
    static constexpr int MOD = 1000000007;
    using ll = long long;
    int numOfArrays(int n, int m, int K) {

        // dp contains number of ways for an array of i elements that max the maximum value
        // of j and has a search cost of k.
        vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(K+1, vector<ll>(m+1, 0)));
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= K; ++k) {
                if (k > i)
                    continue;
                for (int j = 1; j <= m; ++j) {
                    if (i == 1) {
                        dp[i][k][j] = (k == 1) ? 1 : 0;
                    } else {

                        // These are the combinations where the max value was found in a previous
                        // (not the last element)
                        dp[i][k][j] = (dp[i-1][k][j] * j) % MOD;
                        if (k > 1 && k <= j) {
                            int sum = 0;

                            // These are the combinations where the max value is at the last element
                            for (int l = 1; l < j; ++l) {
                                sum = (sum + dp[i-1][k-1][l]) % MOD;
                            }
                            dp[i][k][j] = (dp[i][k][j] + sum) % MOD;
                        }
                    }
                }
            }
        }

        return accumulate(begin(dp[n][K]), end(dp[n][K]), 0, [] (auto a, auto b) {return (a+b) % MOD;});
    }
};

int main() {
    Solution sol;
    int n, m, k;

    // Output: 6
    n = 2, m = 3, k = 1;
    cout << sol.numOfArrays(n, m, k) << endl;
    //return 0;
    
    // Output: 0
    n = 5, m = 2, k = 3;
    cout << sol.numOfArrays(n, m, k) << endl;
    
    // Output: 1
    n = 9, m = 1, k = 1;
    cout << sol.numOfArrays(n, m, k) << endl;
    
    // Output: 34549172
    n = 50, m = 100, k = 25;
    cout << sol.numOfArrays(n, m, k) << endl;
    //return 0;
    // Output: 418930126
    n = 37, m = 17, k = 7;
    cout << sol.numOfArrays(n, m, k) << endl;
    
    return 0;
}
