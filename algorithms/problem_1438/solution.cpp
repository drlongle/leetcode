/*
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Medium

Given an array of integers nums and an integer limit, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to limit.

In case there is no subarray satisfying the given condition return 0.

Example 1:
Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    bool check(multiset<int>& nums, int limit) {
        return nums.empty() || (*nums.rbegin() - *nums.begin() <= limit);
    }
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0, start = 0, end = 0, sz = nums.size();
        multiset<int> currs;
        while (start < sz) {
            while (start < sz) {
                currs.emplace(nums[start++]);
                if (!check(currs, limit))
                    break;
                res = max(res, start - end);
            }

            while (end < start) {
                auto it = currs.find(nums[end++]);
                currs.erase(it);
                if (check(currs, limit))
                    break;
            }
            res = max(res, start - end);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int limit;

    // Output: 2 
    nums = {8,2,4,7}, limit = 4;
    cout << sol.longestSubarray(nums, limit) << endl;

    // Output: 4 
    nums = {10,1,2,4,7,2}, limit = 5;
    cout << sol.longestSubarray(nums, limit) << endl;
    
    // Output: 3
    nums = {4,2,2,2,4,4,2,2}, limit = 0;
    cout << sol.longestSubarray(nums, limit) << endl;

    nums = {8}, limit = 10;
    cout << sol.longestSubarray(nums, limit) << endl;
    
    return 0;
}
