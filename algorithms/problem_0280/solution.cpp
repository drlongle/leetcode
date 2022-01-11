/*
280. Wiggle Sort
Medium

Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

You may assume the input array always has a valid answer.

Example 1:
Input: nums = [3,5,2,1,6,4]
Output: [3,5,1,6,2,4]
Explanation: [1,6,2,5,3,4] is also accepted.

Example 2:
Input: nums = [6,6,5,6,3,8]
Output: [6,6,5,6,3,8]

Constraints:
1 <= nums.length <= 5 * 104
0 <= nums[i] <= 104
It is guaranteed that there will be an answer for the given input nums.

Follow up: Could you do it without sorting the array?
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
    void wiggleSort(vector<int>& nums) {
        for (int i = 0, n = nums.size(); i+1 < n; ++i){
            if (i% 2 == 0){
                if (nums[i] > nums[i+1])
                    swap(nums[i],nums[i+1]);
            } else if (nums[i] < nums[i+1])
                swap(nums[i],nums[i+1]);
        }
    }
};

int main() {
    Solution sol;

    return 0;
}
