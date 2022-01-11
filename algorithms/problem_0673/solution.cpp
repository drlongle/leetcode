/*
673. Number of Longest Increasing Subsequence
Medium

Given an integer array nums, return the number of longest increasing subsequences.

Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are
5 subsequences' length is 1, so output 5.

Constraints:
0 <= nums.length <= 2000
-10^6 <= nums[i] <= 10^6
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
    vector<pair<int, int>> dp;
    int findNumberOfLIS(vector<int>& nums) {
        int sz = nums.size();
        dp.resize(sz);

        pair<int, int> res{0, 0};

        for (int i = 0; i < sz; ++i) {
            pair<int, int> cnt{0, 1};
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    if (dp[j].first == cnt.first)
                        cnt.second += dp[j].second;
                    else if (dp[j].first > cnt.first)
                        cnt = dp[j];
                }
            }
            dp[i] = {cnt.first + 1, cnt.second};
            if (res.first == dp[i].first)
                res.second += dp[i].second;
            else if (res.first < dp[i].first)
                res = dp[i];
        }

        return res.second;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 2
    nums = {1,3,5,4,7};
    //cout << sol.findNumberOfLIS(nums) << endl;

    // Output: 5
    nums = {2,2,2,2,2};
    //cout << sol.findNumberOfLIS(nums) << endl;

    // Output: 3
    nums = {1,2,4,3,5,4,7,2};
    cout << sol.findNumberOfLIS(nums) << endl;

    return 0;
}
