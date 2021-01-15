/*
523. Continuous Subarray Sum
Medium

Given a list of non-negative numbers and a target integer k, write a function to check if the array has
a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where
n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

Constraints:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
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
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> table{{0, -1}};
        long key, sum = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            sum = sum + nums[i];
            if (k != 0) {
                sum %= k;
                key = (k - sum) % k;
            } else
                key = sum;
            auto it = table.find(key);
            if (it != table.end() && i - it->second >= 2)
                return true;
            table.emplace(key, i);
        }
        return false;
    }
};

int main() {
    Solution sol;

    return 0;
}
