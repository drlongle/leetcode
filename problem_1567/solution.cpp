/*
1567. Maximum Length of Subarray With Positive Product
Medium

Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

Example 1:
Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.

Example 2:
Input: nums = [0,1,-2,-3,-4]
Output: 3
Explanation: The longest subarray with positive product is [1,-2,-3] which has a product of 6.
Notice that we cannot include 0 in the subarray since that'll make the product 0 which is not positive.

Example 3:
Input: nums = [-1,-2,-3,0,1]
Output: 2
Explanation: The longest subarray with positive product is [-1,-2] or [-2,-3].

Example 4:
Input: nums = [-1,2]
Output: 1

Example 5:
Input: nums = [1,2,3,5,-6,4,0,10]
Output: 4

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
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
    int getMaxLen(vector<int>& nums, int begin, int end) {
        if (begin > end)
            return 0;
        int negs = 0, first = -1, last;
        for (int i = begin; i < end; ++i) {
            if (nums[i] < 0) {
                ++negs;
                if (first < 0)
                    first = i;
                last = i;
            }
        }
        if (negs % 2 == 0)
            return end - begin;
        else
            return max(last - begin, end - first -1);
    }

    int getMaxLen(vector<int>& nums) {
        int res = 0, start = 0, sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            if (nums[i] == 0) {
                res = max(res, getMaxLen(nums, start, i));
                start = i+1;
            }
        }
        res = max(res, getMaxLen(nums, start, sz));
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 4
    nums = {1,-2,-3,4};
    cout << sol.getMaxLen(nums) << endl;

    // Output: 3
    nums = {0,1,-2,-3,-4};
    cout << sol.getMaxLen(nums) << endl;

    // Output: 2
    nums = {-1,-2,-3,0,1};
    cout << sol.getMaxLen(nums) << endl;

    // Output: 1
    nums = {-1,2};
    cout << sol.getMaxLen(nums) << endl;

    // Output: 4
    nums = {1,2,3,5,-6,4,0,10};
    cout << sol.getMaxLen(nums) << endl;

    // Output: 8
    nums = {5,-20,-20,-39,-5,0,0,0,36,-32,0,-7,-10,-7,21,20,-12,-34,26,2};
    cout << sol.getMaxLen(nums) << endl;

    return 0;
}
