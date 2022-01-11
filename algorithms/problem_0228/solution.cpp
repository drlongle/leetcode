/*
228. Summary Ranges
Easy

You are given a sorted unique integer array nums.

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"

Example 2:
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"

Example 3:
Input: nums = []
Output: []

Example 4:
Input: nums = [-1]
Output: ["-1"]

Example 5:
Input: nums = [0]
Output: ["0"]

Constraints:
0 <= nums.length <= 20
-2^31 <= nums[i] <= 2^31 - 1
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

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int curr = 0, sz = nums.size();

        ostringstream oss;
        for (; curr < sz; ++curr) {
            int n = nums[curr], cnt = 1;
            while (curr < sz - 1 && nums[curr+1] == n) {
                ++cnt, ++curr;
            }
            if (cnt > 1 || curr == sz-1 || nums[curr+1] - n != 1) {
                res.emplace_back(to_string(n));
                continue;
            }
            while (curr < sz -1 && static_cast<long long>(nums[curr+1]) - nums[curr] == 1) {
                ++curr;
            }
            oss.str("");
            oss << to_string(n) << "->" << to_string(nums[curr]);
            res.emplace_back(oss.str());
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    vector<string> res;

    // Output: {"0->2","4->5","7"}
    nums = {0,1,2,4,5,7};
    res = sol.summaryRanges(nums);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"0","2->4","6","8->9"}
    nums = {0,2,3,4,6,8,9};
    res = sol.summaryRanges(nums);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {}
    nums = {};
    res = sol.summaryRanges(nums);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"-1"}
    nums = {-1};
    res = sol.summaryRanges(nums);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"0"}
    nums = {0};
    res = sol.summaryRanges(nums);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
