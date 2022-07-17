/*
491. Increasing Subsequences
Medium

Given an integer array nums, return all the different possible increasing
subsequences of the given array with at least two elements. You may return the
answer in any order.

The given array may contain duplicates, and two equal integers should also be
considered a special case of increasing sequence.

Example 1:
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Example 2:
Input: nums = [4,4,3,2,1]
Output: [[4,4]]

Constraints:
1 <= nums.length <= 15
-100 <= nums[i] <= 100
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
    set<vector<int>> res;
    void backtrack(vector<int> &nums, size_t index) {
        if (temp.size() >= 2)
            res.insert(temp);
        size_t sz = nums.size();
        for (auto i = index; i < sz; ++i) {
            if (temp.empty() || temp.back() <= nums[i]) {
                temp.push_back(nums[i]);
                backtrack(nums, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<int> temp;
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        backtrack(nums, 0);
        return vector<vector<int>>(begin(res), end(res));
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    vector<vector<int>> res;

    auto print = [](vector<vector<int>> &res) {
        for (auto &r : res) {
            copy(begin(r), end(r), ostream_iterator<int>(cout, ", "));
            cout << endl;
        }
    };

    nums = {4, 6, 7, 7};
    res = sol.findSubsequences(nums);
    print(res);

    nums = {4, 4, 3, 2, 1};
    res = sol.findSubsequences(nums);
    print(res);

    return 0;
}