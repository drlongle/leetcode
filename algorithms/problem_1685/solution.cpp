/*
1685. Sum of Absolute Differences in a Sorted Array
Medium

You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal
to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length
and j != i (0-indexed).

Example 1:
Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.

Example 2:
Input: nums = [1,4,6,8,10]
Output: [24,15,13,15,21]

Constraints:
2 <= nums.length <= 105
1 <= nums[i] <= nums[i + 1] <= 104
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int sz = nums.size();
        vector<int> prefix(sz+1, 0), suffix(sz+1, 0);
        for (int i = 0; i < sz; ++i)
            prefix[i+1] = prefix[i] + nums[i];
        for (int i = sz-1; i >= 0; --i)
            suffix[i] = suffix[i+1] + nums[i];
        vector<int> res(sz);
        for (int i = 0; i < sz; ++i) {
            res[i] = (i+1) * nums[i] - prefix[i+1];
            res[i] += suffix[i] - (sz - i) * nums[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums, res;

    // Output: [4,3,5]
    nums = {2,3,5};
    res = sol.getSumAbsoluteDifferences(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: [24,15,13,15,21]
    nums = {1,4,6,8,10};
    res = sol.getSumAbsoluteDifferences(nums);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
