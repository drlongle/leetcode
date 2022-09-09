/*
2023. Number of Pairs of Strings With Concatenation Equal to Target
Medium

Given an array of digit strings nums and a digit string target, return the
number of pairs of indices (i, j) (where i != j) such that the concatenation of
nums[i] + nums[j] equals target.

Example 1:
Input: nums = ["777","7","77","77"], target = "7777"
Output: 4
Explanation: Valid pairs are:
- (0, 1): "777" + "7"
- (1, 0): "7" + "777"
- (2, 3): "77" + "77"
- (3, 2): "77" + "77"

Example 2:
Input: nums = ["123","4","12","34"], target = "1234"
Output: 2
Explanation: Valid pairs are:
- (0, 1): "123" + "4"
- (2, 3): "12" + "34"

Example 3:
Input: nums = ["1","1","1"], target = "11"
Output: 6
Explanation: Valid pairs are:
- (0, 1): "1" + "1"
- (1, 0): "1" + "1"
- (0, 2): "1" + "1"
- (2, 0): "1" + "1"
- (1, 2): "1" + "1"
- (2, 1): "1" + "1"

Constraints:
2 <= nums.length <= 100
1 <= nums[i].length <= 100
2 <= target.length <= 100
nums[i] and target consist of digits.
nums[i] and target do not have leading zeros.
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

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    int numOfPairs(vector<string> &nums, string target) {
        unordered_map<string, int> cnt;
        for (auto &n : nums) {
            ++cnt[n];
        }
        int res = 0;
        for (auto &n : nums) {
            if (n.size() >= target.size())
                continue;
            if (target.substr(0, n.size()) == n) {
                string s = target.substr(n.size());
                if (s == n)
                    res += cnt[n] - 1;
                else
                    res += cnt[s];
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<string> nums;
    string target;

    // Output: 5
    nums = {"4", "4", "43", "34034", "43403", "4034"};
    target = "434034";
    cout << sol.numOfPairs(nums, target) << endl;
}
