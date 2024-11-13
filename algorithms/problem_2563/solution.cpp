/*
2563. Count the Number of Fair Pairs
Medium

Given a 0-indexed integer array nums of size n and two integers lower and upper,
return the number of fair pairs.

A pair (i, j) is fair if:
0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper

Example 1:
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and
(1,5).

Example 2:
Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).

Constraints:
1 <= nums.length <= 10^5
nums.length == n
-10^9 <= nums[i] <= 10^9
-10^9 <= lower <= upper <= 10^9
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
    int right_search(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] <= target) {
                res = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }

        return res;
    }

    int left_search(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] >= target) {
                hi = mid - 1;
                res = mid;
            } else
                lo = mid + 1;
        }

        return res;
    }

    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        ranges::sort(nums);

        long long res = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int l = left_search(nums, lower - nums[i]);
            int r = right_search(nums, upper - nums[i]);
            if (l >= 0 && r >= 0) {
                if (l <= i && i <= r)
                    res += r - l;
                else
                    res += r - l + 1;
            }
        }

        return res / 2;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int lower, upper;

    nums = {0, 1, 7, 4, 4, 5}, lower = 3, upper = 6;
    cout << sol.countFairPairs(nums, lower, upper) << endl;

    nums = {1, 7, 9, 2, 5}, lower = 11, upper = 11;
    cout << sol.countFairPairs(nums, lower, upper) << endl;

    return 0;
}
