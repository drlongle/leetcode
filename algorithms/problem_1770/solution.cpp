/*
1770. Maximum Score from Performing Multiplication Operations
Medium

You are given two integer arrays nums and multipliers of size n and m respectively,
where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations.
On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.

Example 1:
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.

Example 2:
Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score.
The total score is 50 + 15 - 9 + 4 + 42 = 102.

Constraints:
n == nums.length
m == multipliers.length
1 <= m <= 10^3
m <= n <= 10^5
-1000 <= nums[i], multipliers[i] <= 1000
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

#define SIZE 100000 * 1000
int dp[SIZE];
char computed[SIZE];
class Solution {
public:
    int sz;
    int maximumScore(vector<int>& nums, vector<int>& multipliers, int i, int j, int k) {

        auto key = 100000 * i + j;
        auto& res = dp[key];
        if (computed[key])
            return res;
        int mult = multipliers[k];
        computed[key] = true;
        return res = max(mult * nums[i] + ( k + 1 < sz ? maximumScore(nums, multipliers, i+1, j, k+1) : 0),
                             mult * nums[j] + ( k + 1 < sz ? maximumScore(nums, multipliers, i , j-1, k+1) : 0));
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        bzero(computed, SIZE);
        sz = multipliers.size();
        return maximumScore(nums, multipliers, 0, nums.size()-1, 0);
    }
};

int main() {
    Solution sol;
    vector<int> nums, multipliers;

    nums = {1,2,3}, multipliers = {3,2,1};
    cout << sol.maximumScore(nums, multipliers) << endl;

    nums = {-5,-3,-3,-2,7,1}, multipliers = {-10,-5,3,4,6};
    cout << sol.maximumScore(nums, multipliers) << endl;

    return 0;
}
