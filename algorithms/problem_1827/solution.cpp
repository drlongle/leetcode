/*
1827. Minimum Operations to Make the Array Increasing
Easy

You are given an integer array nums (0-indexed). In one operation, you can choose an element
of the array and increment it by 1.

For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
Return the minimum number of operations needed to make nums strictly increasing.

An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1.
An array of length 1 is trivially strictly increasing.

Example 1:
Input: nums = [1,1,1]
Output: 3
Explanation: You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,2].
2) Increment nums[1], so nums becomes [1,2,2].
3) Increment nums[2], so nums becomes [1,2,3].

Example 2:
Input: nums = [1,5,2,4,1]
Output: 14

Example 3:
Input: nums = [8]
Output: 0

Constraints:
1 <= nums.length <= 5000
1 <= nums[i] <= 10^4
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 1; i < n; ++i) {
            int diff = nums[i] - nums[i-1];
            if (diff <= 0) {
                res += abs(diff) + 1;
                nums[i] += abs(diff) + 1;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 1, 1};
    cout << sol.minOperations(nums) << endl;

    return 0;
}
