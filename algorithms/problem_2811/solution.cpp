/*
2811. Check if it is Possible to Split Array
Medium

You are given an array nums of length n and an integer m. You need to determine if it is
possible to split the array into n arrays of size 1 by performing a series of steps.

An array is called good if:

The length of the array is one, or
The sum of the elements of the array is greater than or equal to m.
In each step, you can select an existing array (which may be the result of previous steps) with
a length of at least two and split it into two arrays, if both resulting arrays are good.
Return true if you can split the given array into n arrays, otherwise return false.

Example 1:
Input: nums = [2, 2, 1], m = 4
Output: true
Explanation:
Split [2, 2, 1] to [2, 2] and [1]. The array [1] has a length of one, and the array [2, 2] has the sum of its elements equal to 4 >= m, so both are good arrays.
Split [2, 2] to [2] and [2]. both arrays have the length of one, so both are good arrays.

Example 2:
Input: nums = [2, 1, 3], m = 5
Output: false
Explanation:
The first move has to be either of the following:
Split [2, 1, 3] to [2, 1] and [3]. The array [2, 1] has neither length of one nor sum of elements greater than or equal to m.
Split [2, 1, 3] to [2] and [1, 3]. The array [1, 3] has neither length of one nor sum of elements greater than or equal to m.
So as both moves are invalid (they do not divide the array into two good arrays), we are unable to split nums into n arrays of size 1.

Example 3:
Input: nums = [2, 3, 3, 2, 3], m = 6
Output: true
Explanation:
Split [2, 3, 3, 2, 3] to [2] and [3, 3, 2, 3].
Split [3, 3, 2, 3] to [3, 3, 2] and [3].
Split [3, 3, 2] to [3, 3] and [2].
Split [3, 3] to [3] and [3].

Constraints:
1 <= n == nums.length <= 100
1 <= nums[i] <= 100
1 <= m <= 200
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    vector<int> sum;
    vector<vector<int>> dp;;

    bool check(vector<int> &nums, int i, int j, int m) {
        if (i == j)
            return true;
        if (dp[i][j] >= 0)
            return dp[i][j];
        if (i+1 == j || (sum[j] - sum[i] >= m &&
            check(nums, i+1, j, m)))
            return dp[i][j] = true;
        if (i == j-1 || (sum[j-1] - (i > 0 ? sum[i-1] : 0) >= m &&
            check(nums, i, j-1, m)))
            return dp[i][j] = true;
        return dp[i][j] = false;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        sum.clear();
        dp.resize(100, vector<int>(100, -1));
        for (int i = 0, s = 0; i < nums.size(); i++) {
            s += nums[i];
            sum.push_back(s);
        }
        return check(nums, 0, nums.size() - 1, m);
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int m;

    nums = {2, 2, 1}, m = 4;
    cout << boolalpha << s.canSplitArray(nums, m) << endl;

    nums = {2, 1, 3}, m = 5;
    cout << boolalpha << s.canSplitArray(nums, m) << endl;

    return 0;
}
