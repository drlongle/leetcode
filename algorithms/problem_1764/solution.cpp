/*
1764. Form Array by Concatenating Subarrays of Another Array
Medium

You are given a 2D integer array groups of length n. You are also given an integer array nums.

You are asked if you can choose n disjoint subarrays from the array nums such that the ith subarray
is equal to groups[i] (0-indexed), and if i > 0, the (i-1)th subarray appears before the ith subarray
in nums (i.e. the subarrays must be in the same order as groups).

Return true if you can do this task, and false otherwise.

Note that the subarrays are disjoint if and only if there is no index k such that nums[k] belongs
to more than one subarray. A subarray is a contiguous sequence of elements within an array.

Example 1:
Input: groups = [[1,-1,-1],[3,-2,0]], nums = [1,-1,0,1,-1,-1,3,-2,0]
Output: true
Explanation: You can choose the 0th subarray as [1,-1,0,1,-1,-1,3,-2,0]
and the 1st one as [1,-1,0,1,-1,-1,3,-2,0].
These subarrays are disjoint as they share no common nums[k] element.

Example 2:
Input: groups = [[10,-2],[1,2,3,4]], nums = [1,2,3,4,10,-2]
Output: false
Explanation: Note that choosing the subarrays [1,2,3,4,10,-2] and [1,2,3,4,10,-2] is incorrect
because they are not in the same order as in groups.
[10,-2] must come before [1,2,3,4].

Example 3:
Input: groups = [[1,2,3],[3,4]], nums = [7,7,1,2,3,4,7,7]
Output: false
Explanation: Note that choosing the subarrays [7,7,1,2,3,4,7,7] and [7,7,1,2,3,4,7,7] is invalid
because they are not disjoint.
They share a common elements nums[4] (0-indexed).

Constraints:
groups.length == n
1 <= n <= 103
1 <= groups[i].length, sum(groups[i].length) <= 10^3
1 <= nums.length <= 10^3
-10^7 <= groups[i][j], nums[k] <= 10^7
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

class Solution {
public:
    bool match(vector<int>& group, vector<int>& nums, size_t i) {
        size_t j = 0;
        while (i < nums.size() && j < group.size()) {
            if (nums[i] != group[j])
                return false;
            ++i, ++j;
        }
        return j == group.size();
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        size_t index = 0, i = 0;
        while (index < groups.size()) {
            bool matched = false;
            while (! (matched = match(groups[index], nums, i)) && i < nums.size()) {
                ++i;
            }
            if (!matched)
                return false;
            i += groups[index].size();
            ++index;
        }
        return index == groups.size();
    }
};

int main() {
    Solution sol;
    vector<vector<int>> groups;
    vector<int> nums;

    // True
    groups = {{1,-1,-1},{3,-2,0}}, nums = {1,-1,0,1,-1,-1,3,-2,0};
    cout << sol.canChoose(groups, nums) << endl;

    // False
    groups = {{10,-2},{1,2,3,4}}, nums = {1,2,3,4,10,-2};
    cout << sol.canChoose(groups, nums) << endl;

    // False
    groups = {{1,2,3},{3,4}}, nums = {7,7,1,2,3,4,7,7};
    cout << sol.canChoose(groups, nums) << endl;

    return 0;
}
