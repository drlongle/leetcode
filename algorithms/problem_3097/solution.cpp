/*
3097. Shortest Subarray With OR at Least K II
Medium

You are given an array nums of non-negative integers and an integer k.
An array is called special if the bitwise OR of all of its elements is at least
k. Return the length of the shortest special non-empty subarray of nums, or
return -1 if no special subarray exists.

Example 1:
Input: nums = [1,2,3], k = 2
Output: 1
Explanation:
The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:
Input: nums = [2,1,8], k = 10
Output: 3
Explanation:
The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:
Input: nums = [1,2], k = 0
Output: 1
Explanation:
The subarray [1] has OR value of 1. Hence, we return 1.

Constraints:
1 <= nums.length <= 2 * 10^5
0 <= nums[i] <= 10^9
0 <= k <= 10^9
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
    int minimumSubarrayLength(vector<int> &nums, int k) {
        int res = numeric_limits<int>::max();
        int sum = 0, tail = 0, head = 0, sz = nums.size();
        for (; head < sz; ++head) {
            sum |= nums[head];
            if (sum >= k) {
                res = min(res, head - tail + 1);
                sum = 0;
                tail = head;
                while ((sum |= nums[tail]) < k) {
                    --tail;
                }
                res = min(res, head - tail + 1);
                sum = 0;
                head = ++tail;
            }
        }

        return res != numeric_limits<int>::max() ? res : -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    nums = {1, 2, 3}, k = 2;
    cout << sol.minimumSubarrayLength(nums, k) << endl;

    nums = {2, 1, 8}, k = 10;
    cout << sol.minimumSubarrayLength(nums, k) << endl;

    nums = {1, 2}, k = 0;
    cout << sol.minimumSubarrayLength(nums, k) << endl;

    return 0;
}
