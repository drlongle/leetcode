/*
1577. Number of Ways Where Square of Number Is Equal to Product of Two Numbers
Medium

Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:

Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.

Example 1:
Input: nums1 = [7,4], nums2 = [5,2,8,9]
Output: 1
Explanation: Type 1: (1,1,2), nums1[1]^2 = nums2[1] * nums2[2]. (4^2 = 2 * 8).

Example 2:
Input: nums1 = [1,1], nums2 = [1,1,1]
Output: 9
Explanation: All Triplets are valid, because 1^2 = 1 * 1.
Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  nums1[i]^2 = nums2[j] * nums2[k].
Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]^2 = nums1[j] * nums1[k].

Example 3:
Input: nums1 = [7,7,8,3], nums2 = [1,2,9,7]
Output: 2
Explanation: There are 2 valid triplets.
Type 1: (3,0,2).  nums1[3]^2 = nums2[0] * nums2[2].
Type 2: (3,0,1).  nums2[3]^2 = nums1[0] * nums1[1].

Example 4:
Input: nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
Output: 0
Explanation: There are no valid triplets.

Constraints:
1 <= nums1.length, nums2.length <= 1000
1 <= nums1[i], nums2[i] <= 10^5
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

    int find(vector<int>& nums, long long k) {
        int i = 0, j = nums.size()-1, res = 0;

        while (i < j) {
            long long prod = static_cast<long long>(nums[i]) * static_cast<long long>(nums[j]);
            if (prod == k) {
                if (nums[i] != nums[j]) {
                    int cnt1 = 0, cnt2 = 0;
                    for (int n = nums[i]; i < j && nums[i] == n; ++i)
                        ++cnt1;
                    for (int n = nums[j]; i <= j && nums[j] == n; --j)
                        ++cnt2;
                    res += cnt1 * cnt2;
                } else {
                    int n = j - i + 1;
                    res += n*(n-1) / 2;
                    break;
                }
            } else if (prod < k)
                ++i;
            else
                --j;
        }

        return res;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        int res = 0;
        for (long long n: nums1)
            res += find(nums2, n * n);
        for (long long n: nums2)
            res += find(nums1, n * n);

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums1, nums2;

    // Output: 1
    nums1 = {7,4}, nums2 = {5,2,8,9};
    cout << sol.numTriplets(nums1, nums2) << endl;

    // Output: 9
    nums1 = {1,1}, nums2 = {1,1,1};
    cout << sol.numTriplets(nums1, nums2) << endl;

    // Output: 2
    nums1 = {7,7,8,3}, nums2 = {1,2,9,7};
    cout << sol.numTriplets(nums1, nums2) << endl;

    // Output: 0
    nums1 = {4,7,9,11,23}, nums2 = {3,5,1024,12,18};
    cout << sol.numTriplets(nums1, nums2) << endl;

    // Output: 4
    nums1 = {3,1,2,2}, nums2 = {1,3,4,4};
    cout << sol.numTriplets(nums1, nums2) << endl;

    // Output: 40
    nums1 = {4,5,7,1,3,6,4,1,4,5,1}, nums2 = {6,4,7,1,5,4,2,1,5,2};
    cout << sol.numTriplets(nums1, nums2) << endl;

    // Output: 30
    nums1 = {7,1,7,3,6,2,6,4,2,6}, nums2 = {5,5,2,2,7,1,7,2,6,7,6};
    cout << sol.numTriplets(nums1, nums2) << endl;

    // Output: 5
    nums1 = {4,1,4,1,12}, nums2 = {3,2,5,4};
    cout << sol.numTriplets(nums1, nums2) << endl;

    return 0;
}
