/*
1590. Make Sum Divisible by P
Medium

Given an array of positive integers nums, remove the smallest subarray (possibly
empty) such that the sum of the remaining elements is divisible by p. It is not
allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if
it's impossible.

A subarray is defined as a contiguous block of elements in the array.

Example 1:
Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6.
We can remove the subarray [4], and the sum of the remaining elements is 6,
which is divisible by 6.

Example 2:
Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The
best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.

Example 3:
Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not
need to remove anything.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= p <= 10^9
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
    int minSubarray(vector<int> &nums, int p) {
        int sum = accumulate(nums.begin(), nums.end(), 0ull) % p;
        if (sum == 0)
            return 0;

        unordered_map<int, int> lookup;
        int res = INT_MAX;
        for (int i = 0, sz = nums.size(), running = 0; i < sz; ++i) {
            if (sum == nums[i])
                return 1;
            running = (running + nums[i]) % p;
            if (running == sum && i != sz - 1)
                res = min(res, i + 1);
            int diff = (running - sum + p) % p;
            if (auto it = lookup.find(diff); it != lookup.end()) {
                res = min(res, i - it->second);
            }
            lookup[running] = i;
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int p;

    nums = {3, 1, 4, 2}, p = 6;
    // cout << "Result: " << sol.minSubarray(nums, p) << endl;

    nums = {6, 3, 5, 2}, p = 9;
    // cout << "Result: " << sol.minSubarray(nums, p) << endl;

    nums = {1, 2, 3}, p = 3;
    // cout << "Result: " << sol.minSubarray(nums, p) << endl;

    nums = {8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2},
    p = 148;
    // cout << "Result: " << sol.minSubarray(nums, p) << endl;

    nums = {1, 2, 3}, p = 7;
    cout << "Result: " << sol.minSubarray(nums, p) << endl;

    return 0;
}
