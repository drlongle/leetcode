/*
1695. Maximum Erasure Value
Medium

You are given an array of positive integers nums and want to erase a subarray containing unique
elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is,
if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 104
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
    int maximumUniqueSubarray(vector<int>& nums) {
        int head = 0, tail = 0, sum = 0, res = 0;
        unordered_map<int, int> cnt;
        for (int sz = nums.size(); head < sz; ++head) {
            int num = nums[head];
            sum += num;
            if (++cnt[num] < 2) {
                res = max(res, sum);
            } else {
                do {
                    --cnt[nums[tail]];
                    sum -= nums[tail];
                } while (num != nums[tail++]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {4,2,4,5,6};
    cout << sol.maximumUniqueSubarray(nums) << endl;

    nums = {5,2,1,2,5,2,1,2,5};
    cout << sol.maximumUniqueSubarray(nums) << endl;

    return 0;
}
