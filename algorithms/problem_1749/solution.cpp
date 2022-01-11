/*
1749. Maximum Absolute Sum of Any Subarray
Medium

You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr]
is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

Example 1:
Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

Example 2:
Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
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
    int pos_sum(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        for (int n: nums) {
            if (sum < 0)
                sum = 0;
            sum += n;
            res = max(res, sum);
        }
        return res;
    }

    int neg_sum(vector<int>& nums) {
        int sum = 0, res = INT_MAX;
        for (int n: nums) {
            if (sum > 0)
                sum = 0;
            sum += n;
            res = min(res, sum);
        }
        return res;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(pos_sum(nums)), abs(neg_sum(nums)));
    }
};

int main() {
    Solution sol;

    return 0;
}
