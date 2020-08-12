/*
1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
Medium

Given an array nums and an integer target.

Return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray
is equal to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 2
Output: 2
Explanation: There are 2 non-overlapping subarrays [1,1,1,1,1] with sum equals to target(2).

Example 2:
Input: nums = [-1,3,5,1,4,2,-9], target = 6
Output: 2
Explanation: There are 3 subarrays with sum equal to 6.
([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.

Example 3:
Input: nums = [-2,6,6,3,5,4,1,2,8], target = 10
Output: 3

Example 4:
Input: nums = [0,0,0], target = 0
Output: 3

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
0 <= target <= 10^6
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
    int maxNonOverlapping(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<int> dp(sz+1, 0);
        unordered_map<int, int> pos;
        pos[0] = 0;
        for (int i = 1, sum = 0; i <= sz; ++i) {
            sum += nums[i-1];
            dp[i] = dp[i-1];
            auto it = pos.find(sum - target);
            if (it != pos.end())
                dp[i] = max(dp[i], 1 + dp[it->second]);
            pos[sum] = i;
        }

        return dp[sz];
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int target;

    // Output: 2
    nums = {1,1,1,1,1}, target = 2;
    cout << sol.maxNonOverlapping(nums, target) << endl;

    // Output: 2
    nums = {-1,3,5,1,4,2,-9}, target = 6;
    cout << sol.maxNonOverlapping(nums, target) << endl;

    // Output: 3
    nums = {-2,6,6,3,5,4,1,2,8}, target = 10;
    cout << sol.maxNonOverlapping(nums, target) << endl;

    // Output: 3
    nums = {0,0,0}, target = 0;
    cout << sol.maxNonOverlapping(nums, target) << endl;

    return 0;
}
