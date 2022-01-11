/*
163. Missing Ranges
Easy

You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all
elements are in the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

Return the smallest sorted list of ranges that cover every missing number exactly. That is, no element
of nums is in any of the ranges, and each missing number is in one of the ranges.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Example 1:
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: ["2","4->49","51->74","76->99"]
Explanation: The ranges are:
[2,2] --> "2"
[4,49] --> "4->49"
[51,74] --> "51->74"
[76,99] --> "76->99"

Example 2:
Input: nums = [], lower = 1, upper = 1
Output: ["1"]
Explanation: The only missing range is [1,1], which becomes "1".

Example 3:
Input: nums = [], lower = -3, upper = -1
Output: ["-3->-1"]
Explanation: The only missing range is [-3,-1], which becomes "-3->-1".

Example 4:
Input: nums = [-1], lower = -1, upper = -1
Output: []
Explanation: There are no missing ranges since there are no missing numbers.

Example 5:
Input: nums = [-1], lower = -2, upper = -1
Output: ["-2"]

Constraints:
-10^9 <= lower <= upper <= 10^9
0 <= nums.length <= 100
lower <= nums[i] <= upper
All the values of nums are unique.
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

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int expected = lower;
        for (int n: nums) {
            if (n < expected)
                continue;
            if (n == expected + 1) {
                res.emplace_back(to_string(expected));
            } else if (n > expected + 1) {
                res.emplace_back(to_string(expected));
                res.back() += "->" + to_string(n-1);
            }
            expected = n+1;
        }
        if (expected == upper)
            res.emplace_back(to_string(expected));
        else if (expected < upper) {
            res.emplace_back(to_string(expected));
            res.back() += "->" + to_string(upper);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    vector<string> res;
    int lower, upper;

    // Output: {"2","4->49","51->74","76->99"}
    nums = {0,1,3,50,75}, lower = 0, upper = 99;
    res = sol.findMissingRanges(nums, lower, upper);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    // Output: {"1"}
    nums = {}, lower = 1, upper = 1;
    res = sol.findMissingRanges(nums, lower, upper);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    // Output: {"-3->-1"}
    nums = {}, lower = -3, upper = -1;
    res = sol.findMissingRanges(nums, lower, upper);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    // Output: {};
    nums = {-1}, lower = -1, upper = -1;
    res = sol.findMissingRanges(nums, lower, upper);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    // Output: {"-2"}
    nums = {-1}, lower = -2, upper = -1;
    res = sol.findMissingRanges(nums, lower, upper);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "; "));
    cout << endl;

    return 0;
}
