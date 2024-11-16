/*
3254. Find the Power of K-Size Subarrays I
Medium

You are given an array of integers nums of length n and a positive integer k.

The power of an array is defined as:
    Its maximum element if all of its elements are consecutive and sorted in
ascending order. -1 otherwise.

You need to find the power of all subarrays of nums of size k.
Return an integer array results of size n - k + 1, where results[i] is the power
of nums[i..(i + k - 1)].

Example 1:
Input: nums = [1,2,3,4,3,2,5], k = 3
Output: [3,4,-1,-1,-1]
Explanation:
There are 5 subarrays of nums of size 3:
    [1, 2, 3] with the maximum element 3.
    [2, 3, 4] with the maximum element 4.
    [3, 4, 3] whose elements are not consecutive.
    [4, 3, 2] whose elements are not sorted.
    [3, 2, 5] whose elements are not consecutive.

Example 2:
Input: nums = [2,2,2,2,2], k = 4
Output: [-1,-1]

Example 3:
Input: nums = [3,2,3,2,3,2], k = 2
Output: [-1,3,-1,3,-1]

Constraints:
    1 <= n == nums.length <= 500
    1 <= nums[i] <= 10^5
    1 <= k <= n
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
    vector<int> resultsArray(vector<int> &nums, int k) {
        vector<int> res;
        auto check = [](auto begin, auto end) {
            for (auto prev = begin, curr = begin + 1; curr < end;
                 ++prev, ++curr) {
                if (*prev + 1 != *curr)
                    return false;
            }
            return true;
        };
        for (int i = 0, sz = nums.size(); i + k <= sz; ++i) {
            if (check(nums.begin() + i, nums.begin() + i + k))
                res.push_back(nums[i + k - 1]);
            else
                res.push_back(-1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums, result;
    int k;

    nums = {1, 2, 3, 4, 3, 2, 5}, k = 3;
    result = sol.resultsArray(nums, k);

    nums = {2, 2, 2, 2, 2}, k = 4;
    result = sol.resultsArray(nums, k);

    nums = {1, 2, 3, 4, 3, 2, 5}, k = 3;
    result = sol.resultsArray(nums, k);

    return 0;
}
