/*
1537. Get the Maximum Score
Hard

You are given two sorted arrays of distinct integers nums1 and nums2.

A valid path is defined as follows:

Choose array nums1 or nums2 to traverse (from index-0).
Traverse the current array from left to right.
If you are reading any value that is present in nums1 and nums2 you are allowed to change
your path to the other array. (Only one repeated value is considered in the valid path).
Score is defined as the sum of uniques values in a valid path.

Return the maximum score you can obtain of all possible valid paths.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
Output: 30
Explanation: Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
The maximum is obtained with the path in green [2,4,6,8,10].

Example 2:
Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
Output: 109
Explanation: Maximum sum is obtained with the path [1,3,5,100].

Example 3:
Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
Output: 40
Explanation: There are no common elements between nums1 and nums2.
Maximum sum is obtained with the path [6,7,8,9,10].

Example 4:
Input: nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
Output: 61

Constraints:
1 <= nums1.length <= 10^5
1 <= nums2.length <= 10^5
1 <= nums1[i], nums2[i] <= 10^7nums1 and nums2 are strictly increasing.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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

using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0, sz1 = nums1.size(), sz2 = nums2.size();
        long long sum = 0, sum1 = 0, sum2 = 0;
        while (i1 < sz1 || i2 < sz2) {
            if (i1 == sz1) {
                sum2 = sum2 + nums2[i2++] % MOD;
            } else if (i2 == sz2) {
                sum1 = sum1 + nums1[i1++] % MOD;
            } else {
                int diff = nums1[i1] - nums2[i2];
                if (diff < 0)
                    sum1 = (sum1 + nums1[i1++]) % MOD;
                else if (diff > 0)
                    sum2 = (sum2 + nums2[i2++]) % MOD;
                else {
                    sum = (sum + max(sum1, sum2) + nums1[i1]) % MOD;
                    sum1 = sum2 = 0;
                    ++i1, ++i2;
                }
            }
        }
        return (sum + max(sum1, sum2)) % MOD;
    }
};

int main() {
    vector<int> nums1, nums2;

    // Output: 30
    {
        Solution sol;
        nums1 = {2,4,5,8,10}, nums2 = {4,6,8,9};
        cout << sol.maxSum(nums1, nums2) << endl;
    }

    // Output: 109
    {
        Solution sol;
        nums1 = {1,3,5,7,9}, nums2 = {3,5,100};
        cout << sol.maxSum(nums1, nums2) << endl;
    }

    // Output: 40
    {
        Solution sol;
        nums1 = {1,2,3,4,5}, nums2 = {6,7,8,9,10};
        cout << sol.maxSum(nums1, nums2) << endl;
    }

    // Output: 61
    {
        Solution sol;
        nums1 = {1,4,5,8,9,11,19}, nums2 = {2,3,4,11,12};
        cout << sol.maxSum(nums1, nums2) << endl;
    }

    // Output: 111
    {
        Solution sol;
        nums1 = {5,9,11,15,17,25,29}, nums2 = {6,12,15};
        cout << sol.maxSum(nums1, nums2) << endl;
    }

    // Output: 101
    {
        Solution sol;
        nums1 = {6,7,8,10,16,19}, nums2 = {9,10,18,25,27};
        cout << sol.maxSum(nums1, nums2) << endl;
    }

    // OUtput: 93
    {
        Solution sol;
        nums1 = {6,7,12,13,14,17,20}, nums2 = {1,4,5,7};
        cout << sol.maxSum(nums1, nums2) << endl;
    }

    return 0;
}
