/*
907. Sum of Subarray Minimums
Medium

Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

Example 1:
Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17.

Note:
1 <= A.length <= 30000
1 <= A[i] <= 30000
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

    int sumSubarrayMins(vector<int>& nums) {
        int sz = nums.size(), sum = 0;
        vector<int> forward(sz, 0), backward(sz, sz-1);
        stack<int> pos;
        for (int i = 0; i < sz; ++i) {
            while (pos.size() && nums[pos.top()] > nums[i]){
                pos.pop();
            }
            if (pos.size())
                forward[i] = pos.top()+1;
            pos.push(i);
        }
        while (pos.size())
            pos.pop();

        for (int i = sz-1; i >= 0; --i) {
            while (pos.size() && nums[pos.top()] >= nums[i]){
                pos.pop();
            }
            if (pos.size())
                backward[i] = pos.top()-1;
            pos.push(i);
        }

        for (int i = 0; i < sz; ++i) {
            int left = max(0, i - forward[i]);
            int right = max(0, backward[i] - i);
            sum = (sum + (static_cast<long long>(nums[i]) * (backward[i] - forward[i] + 1)) % MOD) % MOD;
            sum = (sum + (static_cast<long long>(nums[i]) * left * right) % MOD) % MOD;
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 17
    nums = {3,1,2,4};
    //cout << sol.sumSubarrayMins(nums) << endl;

    // Output: 41
    nums = {3,1,8,2,2,4};
    //cout << sol.sumSubarrayMins(nums) << endl;

    // Output: 593
    nums = {71,55,82,55};
    cout << sol.sumSubarrayMins(nums) << endl;

    return 0;
}
