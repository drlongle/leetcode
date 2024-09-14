/*
2419. Longest Subarray With Maximum Bitwise AND
Medium

You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise
AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of
nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.

Example 1:
Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.

Example 2:
Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
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
    int longestSubarray(vector<int> &nums) {
        int m = 0;
        for (int n : nums)
            m = max(m, n);

        int n = nums.size(), len = 0;
        for (int i = 0; i < n; ++i) {
            int j;
            for (j = i; j < n && nums[j] == m; ++j) {
                len = max(len, j - i + 1);
            }
            i = j;
        }

        return len;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 2
    nums = {1, 2, 3, 3, 2, 2};
    cout << sol.longestSubarray(nums) << endl;

    // Output: 1
    nums = {1, 2, 3, 4};
    cout << sol.longestSubarray(nums) << endl;

    return 0;
}
