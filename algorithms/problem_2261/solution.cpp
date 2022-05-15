/*
2261. K Divisible Elements Subarrays
Medium

Given an integer array nums and two integers k and p, return the number of
distinct subarrays which have at most k elements divisible by p.

Two arrays nums1 and nums2 are said to be distinct if:

They are of different lengths, or
There exists at least one index i where nums1[i] != nums2[i].
A subarray is defined as a non-empty contiguous sequence of elements in an
array.

Example 1:

Input: nums = [2,3,3,2,2], k = 2, p = 2
Output: 11
Explanation:
The elements at indices 0, 3, and 4 are divisible by p = 2.
The 11 distinct subarrays which have at most k = 2 elements divisible by 2 are:
[2], [2,3], [2,3,3], [2,3,3,2], [3], [3,3], [3,3,2], [3,3,2,2], [3,2], [3,2,2],
and [2,2]. Note that the subarrays [2] and [3] occur more than once in nums, but
they should each be counted only once. The subarray [2,3,3,2,2] should not be
counted because it has 3 elements that are divisible by 2. Example 2:

Input: nums = [1,2,3,4], k = 4, p = 1
Output: 10
Explanation:
All element of nums are divisible by p = 1.
Also, every subarray of nums will have at most 4 elements that are divisible
by 1. Since all subarrays are distinct, the total number of subarrays satisfying
all the constraints is 10.

Constraints:
1 <= nums.length <= 200
1 <= nums[i], p <= 200
1 <= k <= nums.length
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    static constexpr int MOD = 1000000007;
    int countSubarray(vector<int> &nums, int len, int k, int p) {
        unordered_map<int, vector<int>> hash;
        long long div_count = 0, sum = 0, mult_factor = 1, res = 0;

        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] % p == 0)
                ++div_count;
            sum = (sum * 10 + nums[i]) % MOD;
            if (i < len)
                mult_factor = mult_factor * 10 % MOD;
            if (i < len - 1)
                continue;
            int j = i - len;
            if (j >= 0) {
                if (nums[j] % p == 0)
                    --div_count;
                sum = (sum - mult_factor * nums[j]) % MOD;
                while (sum < 0)
                    sum += MOD;
            }
            if (div_count <= k) {
                bool unique = true;
                for (int j : hash[sum]) {
                    bool eq =
                        std::equal(nums.begin() + j, nums.begin() + j + len,
                                   nums.begin() + i - len + 1);
                    if (eq) {
                        unique = false;
                        break;
                    }
                }
                if (unique) {
                    ++res;
                    hash[sum].push_back(i - len + 1);
                }
            }
        }
        return res;
    }

    int countDistinct(vector<int> &nums, int k, int p) {
        int res = 0;
        for (int len = 1, n = nums.size(); len <= n; ++len)
            res += countSubarray(nums, len, k, p);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k, p;

    // Output: 11
    nums = {2, 3, 3, 2, 2}, k = 2, p = 2;
    cout << sol.countDistinct(nums, k, p) << endl;

    // Output: 10
    nums = {1, 2, 3, 4}, k = 4, p = 1;
    cout << sol.countDistinct(nums, k, p) << endl;

    // Output: 50
    nums = {13, 4, 14, 13, 15, 4, 8, 13, 4, 12}, k = 5, p = 14;
    cout << sol.countDistinct(nums, k, p) << endl;

    // Output: 35
    nums = {5, 15, 6, 7, 1, 5, 17, 3}, k = 4, p = 11;
    cout << sol.countDistinct(nums, k, p) << endl;

    return 0;
}
