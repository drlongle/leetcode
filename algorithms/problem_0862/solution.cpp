/*
862. Shortest Subarray with Sum at Least K
Hard

Given an integer array nums and an integer k, return the length of the shortest
non-empty subarray of nums with a sum of at least k. If there is no such
subarray, return -1.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1], k = 1
Output: 1

Example 2:
Input: nums = [1,2], k = 4
Output: -1

Example 3:
Input: nums = [2,-1,2], k = 3
Output: 3

Constraints:
1 <= nums.length <= 10^5
-105 <= nums[i] <= 10^5
1 <= k <= 10^9
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
    int shortestSubarray(vector<int> &nums, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        long long s = 0, sz = nums.size();
        int res = numeric_limits<int>::max();
        for (int i = 0; i < sz; ++i) {
            s += nums[i];
            if (s >= k) {
                res = min(res, i + 1);
            }
            while (!pq.empty() && s - pq.top().first >= k) {

                res = min(res, i - pq.top().second);
                pq.pop()
            }
            pq.emplace(s, i);
        }

        return res == numeric_limits<int>::max() ? -1 : res;
        ;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    // Output: 1
    nums = {1};
    k = 1;
    cout << sol.shortestSubarray(nums, k) << endl;

    // Output: -1
    nums = {1, 2};
    k = 4;
    cout << sol.shortestSubarray(nums, k) << endl;

    // Output: 3
    nums = {2, -1, 2};
    k = 3;
    cout << sol.shortestSubarray(nums, k) << endl;

    // Output: 3
    nums = {-28, 81, -20, 28, -29};
    k = 89;
    cout << sol.shortestSubarray(nums, k) << endl;

    // Output: 1
    nums = {44, -25, 75, -50, -38, -42, -32, -6, -40, -47};
    k = 19;
    cout << sol.shortestSubarray(nums, k) << endl;

    return 0;
}
