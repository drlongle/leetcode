/*
632. Smallest Range Covering Elements from K Lists
Hard

You have k lists of sorted integers in non-decreasing order. Find the smallest
range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a <
c if b - a == d - c.

Example 1:
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

Constraints:
nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-10^5 <= nums[i][j] <= 10^5
nums[i] is sorted in non-decreasing order.
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

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        vector<int> res(2);
        int diff = numeric_limits<int>::max();
        multimap<int, int> m;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            m.emplace(nums[i][0], i);
        }

        vector<size_t> indices(nums.size(), 0);
        while (true) {
            int d = m.rbegin()->first - m.begin()->first;
            if (d < diff) {
                res = vector<int>{m.begin()->first, m.rbegin()->first};
                diff = d;
            }

            auto it = m.begin();
            int index = it->second;
            if (++indices[index] == nums[index].size())
                break;
            m.erase(it);
            m.emplace(nums[index][indices[index]], index);
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> nums;
    vector<int> res;

    // Output: [20,24]
    nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    res = sol.smallestRange(nums);
    cout << '[' << res[0] << ", " << res[1] << ']' << endl;

    // Output: {1,1}
    nums = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    res = sol.smallestRange(nums);
    cout << '[' << res[0] << ", " << res[1] << ']' << endl;

    // Output: {10,11}
    nums = {{10}, {11}};
    res = sol.smallestRange(nums);
    cout << '[' << res[0] << ", " << res[1] << ']' << endl;
}
