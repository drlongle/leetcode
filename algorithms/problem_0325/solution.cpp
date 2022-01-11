/*
325. Maximum Size Subarray Sum Equals k
Medium

Given an array nums and a target value k, find the maximum length of a subarray that sums to k.
If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.

Example 2:
Input: nums = [-2, -1, 2, 1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.

Follow Up:
Can you do it in O(n) time?
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
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> table {{0, -1}};
        int sum = 0, n = nums.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            auto it = table.find(sum - k);
            if (it != table.end())
                res = max(res, i - it->second);
            table.emplace(sum, i);
        }

        return res;
    }
};

int main() {
    vector<int> nums;
    int k;

    // Output: 4
    {
        Solution sol;
        nums = {1, -1, 5, -2, 3}, k = 3;
        cout << sol.maxSubArrayLen(nums, k) << endl;
    }

    // Output: 2
    {
        Solution sol;
        nums = {-2, -1, 2, 1}, k = 1;
        cout << sol.maxSubArrayLen(nums, k) << endl;
    }

    return 0;
}
