/*
915. Partition Array into Disjoint Intervals
Medium

Given an array nums, partition it into two (contiguous) subarrays left and right so that:
- Every element in left is less than or equal to every element in right.
- left and right are non-empty.
- left has the smallest possible size.
- Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

Example 1:
Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]

Example 2:
Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]

Note:
2 <= nums.length <= 30000
0 <= nums[i] <= 10^6
It is guaranteed there is at least one way to partition nums as described.
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

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int sz = nums.size(), mi = INT_MAX, ma = INT_MIN;
        vector<int> mins(sz);
        for (int i = sz -1; i >= 0; --i)
            mins[i] = mi = min(mi, nums[i]);
        for (int i = 0; i < sz - 1; ++i) {
            ma = max(ma, nums[i]);
            if (ma <= mins[i+1])
                return i + 1;
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Output: 3
    nums = {5,0,3,8,6};
    cout << sol.partitionDisjoint(nums) << endl;

    // Output: 4
    nums = {1,1,1,0,6,12};
    cout << sol.partitionDisjoint(nums) << endl;

    return 0;
}
