/*
2044. Count Number of Maximum Bitwise-OR Subsets
Medium

Given an integer array nums, find the maximum possible bitwise OR of a subset of
nums and return the number of different non-empty subsets with the maximum
bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting
some (possibly zero) elements of b. Two subsets are considered different if the
indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1]
(0-indexed).

Example 1:
Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2
subsets with a bitwise OR of 3:
- [3]
- [3,1]

Example 2:
Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are
23 - 1 = 7 total subsets.

Example 3:
Input: nums = [3,2,1,5]
Output: 6
Explanation: The maximum possible bitwise OR of a subset is 7. There are 6
subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]

Constraints:
1 <= nums.length <= 16
1 <= nums[i] <= 10^5
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
    unordered_map<int, int> dp;
    unordered_map<int, int> lookup;
    int max_value = 0;
    void countMaxOrSubsets(vector<int> &nums, int curr, int mask) {
        if (auto it = dp.find(mask); it != dp.end()) {
            return;
        }

        dp[mask] = curr;
        ++lookup[curr];
        max_value = max(max_value, curr);
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            if ((mask & (1 << i)) == 0)
                countMaxOrSubsets(nums, curr | nums[i], mask | (1 << i));
        }
    }

    int countMaxOrSubsets(vector<int> &nums) {
        countMaxOrSubsets(nums, 0, 0);

        return lookup[max_value];
    }
};

int main() {
    vector<int> nums;

    {
        Solution sol;
        nums = {3, 1};
        cout << sol.countMaxOrSubsets(nums) << endl;
    }

    {
        Solution sol;
        nums = {2, 2, 2};
        cout << sol.countMaxOrSubsets(nums) << endl;
    }

    {
        Solution sol;
        nums = {3, 2, 1, 5};
        cout << sol.countMaxOrSubsets(nums) << endl;
    }

    return 0;
}
