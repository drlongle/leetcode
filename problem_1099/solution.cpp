/*
1099. Two Sum Less Than K
Easy

Given an array nums of integers and integer k, return the maximum sum such that there exists i < j
with nums[i] + nums[j] = sum and sum < k. If no i, j exist satisfying this equation, return -1.

Example 1:
Input: nums = [34,23,1,24,75,33,54,8], k = 60
Output: 58
Explanation: We can use 34 and 24 to sum 58 which is less than 60.

Example 2:
Input: nums = [10,20,30], k = 15
Output: -1
Explanation: In this case it is not possible to get a pair sum less that 15.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 1000
1 <= k <= 2000
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

#define for_loop(n) for(int i = 0; i < n; ++i)

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        optional<int> res;
        sort(begin(nums), end(nums));
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                int t = nums[i] + nums[j];
                if (t < k && (!res || res < t))
                    res = t;
            }
        }

        return res ? res.value() : -1;
    }
};

int main() {
    Solution sol;

    return 0;
}
