/*
1673. Find the Most Competitive Subsequence
Medium

Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first
position where a and b differ, subsequence a has a number less than the corresponding number in b.
For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at
the final number, and 4 is less than 5.

Example 1:
Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6]
is the most competitive.

Example 2:
Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9
1 <= k <= nums.length
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        for (int i = 0, sz = nums.size(); i < sz; ++i) {
            int n = nums[i];
            while (!res.empty() && n < res.back() && static_cast<int>(res.size()) - 1 + sz - i >= k)
                res.pop_back();
            if (static_cast<int>(res.size()) < k)
                res.push_back(n);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums, res;
    int k;

    // Output: {2,6}
    nums = {3,5,2,6}, k = 2;
    res = sol.mostCompetitive(nums, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {2,3,3,4}
    nums = {2,4,3,3,5,4,9,6}, k = 4;
    res = sol.mostCompetitive(nums, k);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
