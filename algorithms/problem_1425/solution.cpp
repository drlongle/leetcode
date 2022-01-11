/*
1425. Constrained Subsequence Sum
Hard

Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

Example 1:
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].

Example 2:
Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.

Example 3:
Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].

Constraints:
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
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
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int res = numeric_limits<int>::min(), sz = nums.size();
        multiset<int> neighbors;
        map<int, set<int>::iterator> lookup;
        queue<int > q;
        for (int i = 0; i < sz; ++i) {
            while (!q.empty()) {
                int index = q.front();
                if (i - index <= k)
                    break;
                neighbors.erase(lookup[index]);
                q.pop();
            }
            int val = nums[i];
            if (!neighbors.empty()) {
                val = max(val, val + *(neighbors.rbegin()));
            }
            auto it = neighbors.insert(val);
            lookup[i] = it;
            q.push(i);
            res = max(res, val);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    // Output: 37
    nums = {10,2,-10,5,20}, k = 2;
    cout << sol.constrainedSubsetSum(nums, k) << endl;
    
    // Output: -1
    nums = {-1,-2,-3}, k = 1;
    cout << sol.constrainedSubsetSum(nums, k) << endl;
    
    // Output: 23
    nums = {10,-2,-10,-5,20}, k = 2;
    cout << sol.constrainedSubsetSum(nums, k) << endl;
    
    return 0;
}
