/*
698. Partition to K Equal Sum Subsets
Medium

Given an integer array nums and an integer k, return true if it is possible to divide this array into
k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:
Input: nums = [1,2,3,4], k = 3
Output: false

Constraints:
1 <= k <= nums.length <= 16
1 <= nums[i] <= 10^4
The frequency of each element is in the range [1, 4].
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

class Solution {
public:
    int n, sum;
    set<pair<int, int>> cached;

    bool check(vector<int>& nums, int curr, int mask) {
        if (!cached.emplace(curr, mask).second)
            return false;
        if (curr == sum) {
            if (mask == (1 << n) - 1)
                return true;
            return check(nums, 0, mask);
        }
        for (int i = 0; i < n; ++i) {
            int shifted = 1 << i;
            if ((mask & shifted) == 0 && nums[i] + curr <= sum) {
                if (check(nums, curr + nums[i], mask | shifted))
                    return true;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sum = accumulate(begin(nums), end(nums), 0);
        auto divmod = std::div(sum, k);
        if (divmod.rem)
            return false;
        sum = divmod.quot;
        n = nums.size();
        return check(nums, 0, 0);
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    // Output: true
    nums = {4,3,2,3,5,2,1}, k = 4;
    cout << boolalpha << sol.canPartitionKSubsets(nums, k) << endl;

    // Output: false
    nums = {1,2,3,4}, k = 3;
    cout << boolalpha << sol.canPartitionKSubsets(nums, k) << endl;



    return 0;
}
