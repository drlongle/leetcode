/*
1063. Number of Valid Subarrays
Hard

Given an integer array nums, return the number of non-empty subarrays with
the leftmost element of the subarray not larger than other elements in the subarray.

A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,4,2,5,3]
Output: 11
Explanation: There are 11 valid subarrays: [1],[4],[2],[5],[3],[1,4],[2,5],[1,4,2],[2,5,3],[1,4,2,5],[1,4,2,5,3].

Example 2:
Input: nums = [3,2,1]
Output: 3
Explanation: The 3 valid subarrays are: [3],[2],[1].

Example 3:
Input: nums = [2,2,2]
Output: 6
Explanation: There are 6 valid subarrays: [2],[2],[2],[2,2],[2,2],[2,2,2].

Constraints:
1 <= nums.length <= 5 * 10^4
0 <= nums[i] <= 10^5
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        stack<int> pos;
        int res = 0, sz = nums.size();
        for (int i = sz - 1; i >= 0; --i) {
            int n = nums[i];
            while (pos.size() && nums[pos.top()] >= n)
                pos.pop();
            int j = pos.empty() ? sz : pos.top();
            res += j - i;
            pos.push(i);
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
