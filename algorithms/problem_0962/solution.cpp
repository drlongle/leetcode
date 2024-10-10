/*
962. Maximum Width Ramp
Medium

A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <=
nums[j]. The width of such a ramp is j - i.

Given an integer array nums, return the maximum width of a ramp in nums. If
there is no ramp in nums, return 0.

Example 1:
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0
and nums[5] = 5.

Example 2:
Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1
and nums[9] = 1.

Constraints:
2 <= nums.length <= 5 * 10^4
0 <= nums[i] <= 5 * 10^4
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    int find(vector<int> &nums, vector<int> &indices, int n) {
        int res{-1};
        if (indices.empty())
            return res;
        int lo = 0, hi = indices.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (n >= nums[indices[mid]]) {
                res = mid;
                hi = mid - 1;
            } else
                lo = mid + 1;
        }

        return res;
    }

    int maxWidthRamp(vector<int> &nums) {
        int res{0};
        vector<int> indices;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            if (int j = find(nums, indices, nums[i]); j >= 0)
                res = max(res, i - indices[j]);
            if (indices.empty() || nums[i] < nums[indices.back()]) {
                indices.push_back(i);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 4
    nums = {6, 0, 8, 2, 1, 5};
    cout << sol.maxWidthRamp(nums) << endl;

    // Output: 7
    nums = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    cout << sol.maxWidthRamp(nums) << endl;

    // Output: 5
    nums = {10, 10, 10, 7, 1, 6, 2, 1, 7};
    cout << sol.maxWidthRamp(nums) << endl;

    // Output: 9
    nums = {1, 9, 7, 0, 6, 5, 0, 7, 2, 3};
    cout << sol.maxWidthRamp(nums) << endl;

    return 0;
}
