/*
2708. Maximum Strength of a Group
Medium

You are given a 0-indexed integer array nums representing the score of students in an exam.
The teacher would like to form one non-empty group of students with maximal strength,
where the strength of a group of students of indices i0, i1, i2, ... , ik is defined as
nums[i0] * nums[i1] * nums[i2] * ... * nums[ik].

Return the maximum strength of a group the teacher can create.

Example 1:

Input: nums = [3,-1,-5,2,5,-9]
Output: 1350
Explanation: One way to form a group of maximal strength is to group the students at indices
[0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.

Example 2:
Input: nums = [-4,-5,-4]
Output: 20
Explanation: Group the students at indices [0, 1] . Then, we’ll have a resulting strength of 20. We cannot achieve
greater strength.

Constraints:
1 <= nums.length <= 13
-9 <= nums[i] <= 9
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
    long long maxStrength(vector<int>& nums) {
        long long res = 1;
        vector<int> negs;

        if (nums.size() == 1) {
            return nums[0];
        }

        bool has_pos = false;
        bool has_zero = false;
        for (int n: nums) {
            if (n < 0)
                negs.emplace_back(n);
            else if (n > 0) {
                res *= n;
                has_pos = true;
            } else
                has_zero = true;
        }

        if (!has_pos && has_zero && negs.size() <= 1) {
            return 0;
        }

        auto lambda = [] (auto a, auto b) { return a * b; };
        if (negs.size() % 2 == 0) {
            res *= std::accumulate(negs.begin(), negs.end(), 1LL, lambda);
            return res;
        }
        ranges::sort(negs, std::ranges::greater{});
        res *= std::accumulate(negs.begin() + 1, negs.end(), 1LL, lambda);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {3,-1,-5,2,5,-9};
    cout << sol.maxStrength(nums) << endl;

    nums = {-4,-5,-4};
    cout << sol.maxStrength(nums) << endl;

    return 0;
}
