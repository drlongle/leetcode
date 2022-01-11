/*
1696. Jump Game VI
Medium

You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without
going outside the boundaries of the array. That is, you can jump from index i to any index in the
range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j]
for each index j you visited in the array.

Return the maximum score you can get.

Example 1:
Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7.

Example 2:
Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.

Example 3:
Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0

Constraints:
 1 <= nums.length, k <= 105
-10^4 <= nums[i] <= 10^4
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> dp;
    int k, n;

    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        dp.resize(n);
        map<int, int> values;
        dp[n-1] = nums[n-1];
        values[nums[n-1]] = 1;
        for (int i = n-2; i >= 0; --i) {
            int val = nums[i] + values.rbegin()->first;
            dp[i] = val;
            ++values[val];
            int j = i + k;
            if (j < n) {
                auto it = values.find(dp[j]);
                if (--it->second == 0)
                    values.erase(it);
            }
        }

        return dp[0];
    }
};
int main() {
    vector<int> nums;
    int k;

    {
        Solution sol;
        nums = {1,-1,-2,4,-7,3}, k = 2;
        cout << sol.maxResult(nums, k) << endl;
    }

    {
        Solution sol;
        nums = {10,-5,-2,4,0,3}, k = 3;
        cout << sol.maxResult(nums, k) << endl;
    }

    {
        Solution sol;
        nums = {1,-5,-20,4,-1,3,-6,-3}, k = 2;
        cout << sol.maxResult(nums, k) << endl;
    }

    return 0;
}
