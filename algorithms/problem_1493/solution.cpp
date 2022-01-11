/*
1493. Longest Subarray of 1's After Deleting One Element
Medium

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

Example 4:
Input: nums = [1,1,0,0,1,1,1,0,1]
Output: 4

Example 5:
Input: nums = [0,0,0]
Output: 0

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
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
    int longestSubarray(vector<int>& nums) {
        int res = 0, prev = -1, n = nums.size(), begin = 0;
        bool has_zero = false;
        while (begin < n) {
            int zeroes = 0;
            while (begin < n && nums[begin] == 0) {
                ++begin;
                ++zeroes;
                has_zero = true;
            }
            if (zeroes >= 2)
                prev = 0;
            int ones = 0;
            while (begin < n && nums[begin] == 1) {
                ++begin;
                ++ones;
            }
            res = max(res, ones + max(prev, 0));
            prev = ones;
        }
        if (!has_zero && res > 0)
            --res;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 3
    nums = {1,1,0,1};
    cout << sol.longestSubarray(nums) << endl;

    // Output: 5
    nums = {0,1,1,1,0,1,1,0,1};
    cout << sol.longestSubarray(nums) << endl;

    // Output: 2
    nums = {1,1,1};
    cout << sol.longestSubarray(nums) << endl;

    // Output: 4
    nums = {1,1,0,0,1,1,1,0,1};
    cout << sol.longestSubarray(nums) << endl;

    // Output: 0
    nums = {0,0,0};
    cout << sol.longestSubarray(nums) << endl;

    // Output: 1
    nums = {1,0,0,0,0};
    cout << sol.longestSubarray(nums) << endl;

    return 0;
}
