/*
644. Maximum Average Subarray II
Hard

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is greater than or equal to k that has the maximum
average value and return this value. Any answer with a calculation error less than 10^-5
will be accepted.

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation:
- When the length is 4, averages are [0.5, 12.75, 10.5] and the maximum average is 12.75
- When the length is 5, averages are [10.4, 10.8] and the maximum average is 10.8
- When the length is 6, averages are [9.16667] and the maximum average is 9.16667
The maximum average is when we choose a subarray of length 4 (i.e., the sub array [12, -5, -6, 50])
which has the max average 12.75, so we return 12.75.

Note that we do not consider the subarrays of length < 4.

Example 2:
Input: nums = [5], k = 1
Output: 5.00000

Constraints:
n == nums.length
1 <= k <= n <= 104
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    bool check(vector<int>& nums, int k, double mid) {
        double sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i] - mid;
        }
        if (sum >= 0)
            return true;
        double pre_sum = 0, min_pre_sum = 0;
        for (int i = k, n = nums.size(); i < n; ++i) {
            sum += nums[i] - mid;
            pre_sum += nums[i-k] - mid;
            min_pre_sum = min(pre_sum, min_pre_sum);
            if (sum - min_pre_sum >= 0)
                return true;
        }

        return false;
    }

    static constexpr double epsilon = 0.00001;

    double findMaxAverage(vector<int>& nums, int k) {
        double minv = *min_element(nums.begin(), nums.end());
        double maxv = *max_element(nums.begin(), nums.end());
        double error = numeric_limits<double>::max();

        while (error > epsilon) {
            double mid = (maxv + minv) / 2;
            if (check(nums, k, mid))
                minv = mid;
            else
                maxv = mid;
            error = maxv - minv;
        }

        return minv;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    nums = {1,12,-5,-6,50,3}, k = 4;
    cout << sol.findMaxAverage(nums, k) << endl;

    nums = {5}, k = 1;
    cout << sol.findMaxAverage(nums, k) << endl;

    nums = {2, -100, 3}, k = 2;
    cout << sol.findMaxAverage(nums, k) << endl;

    return 0;
}
