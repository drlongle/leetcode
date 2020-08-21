/*
1043. Partition Array for Maximum Sum
Medium

Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.
After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

Example 1:
Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
Explanation: A becomes [15,15,15,9,10,10,10]

Note:
1 <= K <= A.length <= 500
0 <= A[i] <= 10^6
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
    int maxSumAfterPartitioning(vector<int>& nums, int K) {
        int sz = nums.size();
        vector<int> dp(sz, numeric_limits<int>::min());
        vector<vector<int>> mx(sz, vector<int>(sz));
        for (int i = 0; i < sz; ++i) {
            int max_so_far = nums[i];
            for (int j = i; j < sz; ++j) {
                max_so_far = max(max_so_far, nums[j]);
                mx[i][j] = max(mx[i][j], max_so_far);
            }
        }

        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < min(i+1, K); ++j) {
                dp[i] = max(dp[i], (j+1) * mx[i-j][i] + ((i-j-1 >= 0) ? dp[i-j-1] : 0));
            }
        }

        return dp[sz-1];
    }
};

int main() {
    Solution sol;
    vector<int> A;
    int K;

    // Output: 84
    A = {1,15,7,9,2,5,10}, K = 3;
    cout << sol.maxSumAfterPartitioning(A, K) << endl;

    return 0;
}
