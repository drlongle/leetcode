/*
1879. Minimum XOR Sum of Two Arrays
Hard

You are given two integer arrays nums1 and nums2 of length n.

The XOR sum of the two integer arrays is
(nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).

For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.

Rearrange the elements of nums2 such that the resulting XOR sum is minimized.
Return the XOR sum after the rearrangement.

Example 1:
Input: nums1 = [1,2], nums2 = [2,3]
Output: 2
Explanation: Rearrange nums2 so that it becomes [3,2].
The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.

Example 2:
Input: nums1 = [1,0,3], nums2 = [5,3,4]
Output: 8
Explanation: Rearrange nums2 so that it becomes [5,4,3].
The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.

Constraints:
n == nums1.length
n == nums2.length
1 <= n <= 14
0 <= nums1[i], nums2[i] <= 10^7
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int compute(vector<int>& nums1, vector<int>& nums2, int level, int mask) {
        if (level == n)
            return 0;
        int& res = dp[level][mask];
        if (res >= 0)
            return res;
        res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int shifted = (1 << i);
            if ((mask & shifted) == 0) {
                mask |= shifted;
                res = min(res, (nums1[level] ^ nums2[i]) + compute(nums1, nums2, level+1, mask));
                mask ^= shifted;
            }
        }
        return res;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        dp.resize(n, vector<int>(1 << 14, -1));
        return compute(nums1, nums2, 0, 0);
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2;

    // Output: 2
    nums1 = {1,2}, nums2 = {2,3};
    cout << sol.minimumXORSum(nums1, nums2) << endl;

    // Output: 8
    nums1 = {1,0,3}, nums2 = {5,3,4};
    cout << sol.minimumXORSum(nums1, nums2) << endl;

    return 0;
}
