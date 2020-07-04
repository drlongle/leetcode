/*
1498. Number of Subsequences That Satisfy the Given Sum Condition
Medium

Given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal than target.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)

Example 2:
Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

Example 3:
Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them don't satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).

Example 4:
Input: nums = [5,2,4,1,7,6,8], target = 16
Output: 127
Explanation: All non-empty subset satisfy the condition (2^7 - 1) = 127

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
1 <= target <= 10^6
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
    static constexpr int MOD = 1000000007;
    int combinations(vector<int>& nums, int i, int j) {
        long long res = 0;
        for (int k = i; k <= j; ++k) {
            if (nums[k] != nums[i])
                break;
            int sz = j-k;
            res = (res + power(sz)) % MOD;
        }
        return res;
    }

    inline int power(int n) {
        if (powers[n] > 0)
            return powers[n];
        return powers[n] = (2 * power(n-1)) % MOD;
    }
    vector<int> powers;
    
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int i = 0, n = nums.size(), res = 0;
        powers.resize(n+1, 0);
        powers[0] = 1;
        while (i < n) {
            auto it = upper_bound(begin(nums)+i, end(nums), target - nums[i]);
            int j;
            if (it == nums.end())
                j = n-1;
            else
                j = it - begin(nums) - 1;
            if (i < j || (i == j && 2*nums[i] <= target)) {
                res = (res + combinations(nums, i, j)) % MOD;
            }

            it = upper_bound(begin(nums)+i, end(nums), nums[i]);
            if (it == nums.end())
                break;
            i = it - nums.begin();
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int target;

    // Output: 4
    nums = {3,5,6,7}, target = 9;
    cout << sol.numSubseq(nums, target) << endl;

    // Output: 6
    nums = {3,3,6,8}, target = 10;
    cout << sol.numSubseq(nums, target) << endl;

    // Output: 61
    nums = {2,3,3,4,6,7}, target = 12;
    cout << sol.numSubseq(nums, target) << endl;

    // Output: 127
    nums = {5,2,4,1,7,6,8}, target = 16;
    cout << sol.numSubseq(nums, target) << endl;

    // Output: 272187084
    nums = {14,4,6,6,20,8,5,6,8,12,6,10,14,9,17,16,9,7,14,11,14,15,13,11,10,18,13,17,17,14,17,7,9,5,10,13,8,5,18,20,7,5,5,15,19,14};
    target = 22;
    cout << sol.numSubseq(nums, target) << endl;

    // Output: 688052206
    nums = {27,21,14,2,15,1,19,8,12,24,21,8,12,10,11,30,15,18,28,14,26,9,2,24,23,11,7,12,9,17,30,9,28,2,14,22,19,19,27,6,15,12,29,2,30,11,20,30,21,20,2,22,6,14,13,19,21,10,18,30,2,20,28,22};
    target = 31;
    cout << sol.numSubseq(nums, target) << endl;

    return 0;
}
