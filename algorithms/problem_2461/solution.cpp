/*
2461. Maximum Sum of Distinct Subarrays With Length K
Medium

You are given an integer array nums and an integer k. Find the maximum subarray
sum of all the subarrays of nums that meet the following conditions:
- The length of the subarray is k, and
- All the elements of the subarray are distinct.

Return the maximum subarray sum of all the subarrays that meet the conditions.
If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is
repeated.
- [9,9,9] which does not meet the requirements because the element 9 is
repeated. We return 15 because it is the maximum subarray sum of all the
subarrays that meet the conditions

Example 2:
Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is
repeated. We return 0 because no subarrays meet the conditions.

Constraints:
1 <= k <= nums.length <= 10^5
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
    long long maximumSubarraySum(vector<int> &nums, int k) {
        long long res = 0, sum = 0;
        int sz = nums.size();
        unordered_map<int, int> cnt;

        for (int head = 0, tail = 0; head < sz; ++head) {
            sum += nums[head];
            ++cnt[nums[head]];
            if ((int)cnt.size() == k && head - tail == k - 1) {
                res = max(res, sum);
            }
            if (head - tail == k) {
                sum -= nums[tail];
                if (--cnt[nums[tail]] == 0)
                    cnt.erase(nums[tail]);
                if ((int)cnt.size() == k) {
                    res = max(res, sum);
                }
                ++tail;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    nums = {1, 5, 4, 2, 9, 9, 9}, k = 3;
    cout << sol.maximumSubarraySum(nums, k) << endl;

    nums = {1, 2, 2}, k = 2;
    cout << sol.maximumSubarraySum(nums, k) << endl;

    return 0;
}
