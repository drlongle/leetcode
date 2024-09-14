/*
2009. Minimum Number of Operations to Make Array Continuous
Hard

You are given an integer array nums. In one operation, you can replace any
element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums
equals nums.length - 1. For example, nums = [4, 2, 5, 3] is continuous, but nums
= [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

Example 1:
Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.

Example 2:
Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.

Example 3:
Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
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
    int minOperations(vector<int> &nums) {
        std::ranges::sort(nums);
        int res = nums.size(), sz = nums.size();

        // Count the cumulative duplicates
        set<int> s;
        vector<int> dups(sz, 0);
        for (int i = 0; i < sz; ++i) {
            auto [it, inserted] = s.insert(nums[i]);
            if (i > 0)
                dups[i] = dups[i - 1] + (inserted == false);
        }

        for (int i = 0; i < sz; ++i) {

            // For each nums[i], find the numbers that are outside of the
            // range [nums[i], nums[i] + sz - 1]. Those numbers need to change
            // and we also need to add the duplicates in the range  [nums[i],
            // nums[i] + sz - 1].

            int n = nums[i] + sz - 1;
            auto it = std::lower_bound(nums.begin(), nums.end(), n);
            if (it == nums.end()) {
                int count = sz - i;
                int changes =
                    sz - count + dups[sz - 1] - (i > 0 ? dups[i - 1] : 0);
                res = min(res, changes);
            } else {
                if (*it != n)
                    --it;
                int j = it - nums.begin();
                int count = j - i + 1;
                int changes = sz - count + dups[j] - (i > 0 ? dups[i - 1] : 0);
                res = min(res, changes);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 0
    nums = {4, 2, 5, 3};
    cout << sol.minOperations(nums) << endl;

    // Output: 1
    nums = {1, 2, 3, 5, 6};
    cout << sol.minOperations(nums) << endl;

    // Output: 3
    nums = {1, 10, 100, 1000};
    cout << sol.minOperations(nums) << endl;

    // Output: 2
    nums = {8, 5, 9, 9, 8, 4};
    cout << sol.minOperations(nums) << endl;

    return 0;
}
