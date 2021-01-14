/*
1658. Minimum Operations to Reduce X to Zero
Medium

You are given an integer array nums and an integer x. In one operation, you can either remove the
leftmost or the rightmost element from the array nums and subtract its value from x. Note that this
modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements
(5 operations in total) to reduce x to zero.

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
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
    int minOperations(vector<int>& nums, int x) {
        if (!x)
            return 0;
        unordered_map<int, int> table;
        int n = nums.size();
        int res = numeric_limits<int>::max();
        for (int i = 0, sum = 0; i < n; ++i) {
            sum += nums[i];
            table.emplace(sum, i);
            if (sum == x)
                res = min(res, i+1);
        }

        for (int i = n-1, sum = 0; i >= 0; --i) {
            sum += nums[i];
            int key = x - sum;
            if (key == 0) {
                res = min(res, n - i);

            }
            if (key <= 0)
                break;
            auto it = table.find(key);
            if (it != table.end()) {
                int j = it->second;
                if (j < i)
                    res = min(res, n - i + j + 1);
            }
        }

        return (res == numeric_limits<int>::max()) ? -1 : res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int x;

    // Output: 2
    nums = {1,1,4,2,3}, x = 5;
    cout << sol.minOperations(nums, x) << endl;

    // Output: -1
    nums = {5,6,7,8,9}, x = 4;
    cout << sol.minOperations(nums, x) << endl;

    // Output: 5
    nums = {3,2,20,1,1,3}, x = 10;
    cout << sol.minOperations(nums, x) << endl;

    // Output: -1
    nums = {1,1}, x = 3;
    cout << sol.minOperations(nums, x) << endl;

    return 0;
}
