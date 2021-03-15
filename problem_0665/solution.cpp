/*
665. Non-decreasing Array
Medium

Given an array nums with n integers, your task is to check if it could become non-decreasing
by modifying at most one element.

We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based)
such that (0 <= i <= n - 2).

Example 1:
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.

Constraints:
n == nums.length
1 <= n <= 10^4
-10^5 <= nums[i] <= 10^5
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
    bool checkPossibility(vector<int>& nums) {
        int cnt = 1, n = nums.size();
        for (int i = 1; i < n; ++i){
            if (nums[i-1] > nums[i]) {
                if (!cnt)
                    return false;
                cnt = 0;
                if (i > 1 && nums[i] < nums[i-2])
                    nums[i] = nums[i-1];
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    return 0;
}
