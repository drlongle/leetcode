/*
1262. Greatest Sum Divisible by Three
Medium

Given an array nums of integers, we need to find the maximum possible sum
of elements of the array such that it is divisible by three.

Example 1:
Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).

Example 2:
Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.

Example 3:
Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
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
    int maxSumDivThree(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> dp(sz, vector<int>(3, 0));
        
        for (int i = 0; i < sz; ++i) {
            if (i > 0)
                dp[i] = dp[i-1];
            int n = nums[i];
            switch (n % 3) {
                case 0:
                    dp[i][0] = n + (i > 0 ? dp[i-1][0] : 0);
                    if (dp[i][1] > 0)
                        dp[i][1] += n;
                    if (dp[i][2] > 0)
                        dp[i][2] += n;
                    break;
                case 1:
                    if (i > 0 && dp[i-1][2] > 0)
                        dp[i][0] = max(dp[i][0], n+dp[i-1][2]);
                    dp[i][1] = max(n + (i > 0 ? dp[i-1][0] : 0), dp[i][1]);
                    if (i > 0 && dp[i-1][1] > 0)
                        dp[i][2] = max(dp[i][2], n+dp[i-1][1]);
                    break;
                case 2:
                    if (i > 0 && dp[i-1][1] > 0)
                        dp[i][0] = max(dp[i][0], n+dp[i-1][1]);
                    if (i > 0 && dp[i-1][2] > 0)
                        dp[i][1] = max(dp[i][1], n+dp[i-1][2]);
                    dp[i][2] = max(n + (i > 0 ? dp[i-1][0] : 0), dp[i][2]);

            }
        }

        return dp[sz-1][0];
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 18
    nums = {3,6,5,1,8};

    // Output: 0
    nums = {4};

    // Output: 12
    nums = {1,2,3,4,4};

    cout << "Result: " << sol.maxSumDivThree(nums) << endl;
    
    return 0;
}
