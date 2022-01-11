/*
689. Maximum Sum of 3 Non-Overlapping Subarrays
Hard

In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.

Return the result as a list of indices representing the starting position of each interval
(0-indexed). If there are multiple answers, return the lexicographically smallest one.

Example:
Input: [1,2,1,2,6,7,5,1], 2
Output: [0, 3, 5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

Note:
nums.length will be between 1 and 20000.
nums[i] will be between 1 and 65535.
k will be between 1 and floor(nums.length / 3).
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res, back_sum(n, 0), for_sum(n, 0);
        vector<int> back_index(n), for_index(n);
        for (int i = 0, sum = 0, maxsum = 0, maxindex = 0; i < n; ++i) {
            sum += nums[i];
            if (i < k-1)
                continue;
            if (i >= k)
                sum -= nums[i-k];
            if (maxsum < sum) {
                maxsum = sum;
                maxindex = i;
            }
            back_sum[i] = maxsum;
            back_index[i] = maxindex;
        }

        for (int i = n-1, sum = 0, maxsum = 0, maxindex = 0; i >= 0; --i) {
            sum += nums[i];
            if (i + k > n)
                continue;
            if (i + k < n)
                sum -= nums[i+k];
            if (maxsum <= sum) {
                maxsum = sum;
                maxindex = i;
            }
            for_sum[i] = maxsum;
            for_index[i] = maxindex;
        }

        for (int i = 0, sum = 0, maxsum = 0; i + k < n; ++i) {
            sum += nums[i];
            int j = i - k;
            if (j < 0)
                continue;
            sum -= nums[j];
            int total = sum + back_sum[j] + for_sum[i+1];
            vector<int> cur_index{back_index[j]-k+1, i-k+1, for_index[i+1]};
            if (total > maxsum || (total == sum && (res.empty() || res < cur_index))) {
                maxsum = total;
                res = cur_index;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums, res;
    int k;

    nums = {1,2,1,2,6,7,5,1}, k = 2;
    res = sol.maxSumOfThreeSubarrays(nums, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
