/*
1630. Arithmetic Subarrays
Medium

A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference
between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if
s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic:
1, 1, 2, 5, 7
You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing
the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if the subarray
nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence,
and false otherwise.

Example 1:
Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
Explanation:
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.

Example 2:
Input: nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
Output: [false,true,false,false,true,true]

Constraints:
n == nums.length
m == l.length
m == r.length
2 <= n <= 500
1 <= m <= 500
0 <= l[i] < r[i] < n
-10^5 <= nums[i] <= 105
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
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int rsz = r.size();
        vector<bool> rs(rsz, true);
        vector<int> scratch(nums.size());
        for (int i = 0; i < rsz; ++i) {
            int k = 0;
            for (int j = l[i]; j <= r[i]; ++j, ++k) {
                scratch[k] = nums[j];
            }

            sort(begin(scratch), begin(scratch)+k);
            int diff = scratch[1] - scratch[0];
            for (int j = 1; rs[i] && j < k; ++j) {
                rs[i] = (diff == scratch[j] - scratch[j-1]);
            }
        }

        return rs;
    }
};

int main() {
    Solution sol;
    vector<int> nums, l, r;
    vector<bool> res;

    // Output: {true,false,true}
    nums = {4,6,5,9,3,7}, l = {0,0,2}, r = {2,3,5};
    res = sol.checkArithmeticSubarrays(nums, l, r);
    copy(begin(res), end(res), ostream_iterator<bool>(cout, ", "));
    cout << endl;

    // Output: {false,true,false,false,true,true}
    nums = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10}, l = {0,1,6,4,8,7}, r = {4,4,9,7,9,10};
    res = sol.checkArithmeticSubarrays(nums, l, r);
    copy(begin(res), end(res), ostream_iterator<bool>(cout, ", "));
    cout << endl;

    return 0;
}
