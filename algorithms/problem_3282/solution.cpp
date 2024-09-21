/*
3282. Reach End of Array With Max Score
Medium

You are given an integer array nums of length n.

Your goal is to start at index 0 and reach index n - 1. You can only jump to
indices greater than your current index.

The score for a jump from index i to index j is calculated as (j - i) * nums[i].

Return the maximum possible total score by the time you reach the last index.

Example 1:
Input: nums = [1,3,1,5]
Output: 7
Explanation:
First, jump to index 1 and then jump to the last index. The final score is 1 * 1
+ 2 * 3 = 7.

Example 2:
Input: nums = [4,3,1,3,2]
Output: 16
Explanation:
Jump directly to the last index. The final score is 4 * 4 = 16.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
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

/*
Intuition
(j - i) * A[i] is same to add A[i] for each step.
So the stradgy is greedy, jump when A[i] < A[j].

Explanation
For each step,
we increment res += ma,
where ma is the max A[i] up to now.
then we update ma = max(ma, a)
 */

class Solution {
  public:
    long long findMaximumScore(vector<int> &nums) {
        long long res = 0;
        int ma = 0;
        for (int a : nums) {
            res += ma;
            ma = max(ma, a);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 3, 1, 5};
    cout << sol.findMaximumScore(nums) << endl;

    nums = {4, 3, 1, 3, 2};
    cout << sol.findMaximumScore(nums) << endl;

    return 0;
}
