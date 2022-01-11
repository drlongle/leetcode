/*
795. Number of Subarrays with Bounded Maximum
Medium

We are given an array nums of positive integers, and two positive integers left and right (left <= right).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element
n that subarray is at least left and at most right.

Example:
Input:
nums = [2, 1, 4, 3]
left = 2
right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].

Note:
left, right, and nums[i] will be an integer in the range [0, 109].
The length of nums will be in the range of [1, 50000].
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
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int begin = 0, end = 0, sz = nums.size(), res = 0;
        while (begin < sz) {
            while (begin < sz && nums[begin] > right)
                ++begin;
            end = begin;
            vector<int> lower_pos;
            while (begin < sz && nums[begin] <= right) {
                res += begin - end + 1;
                if (nums[begin] < left)
                    lower_pos.push_back(begin);
                ++begin;
            }
            int j;
            for (int i = 0, n = lower_pos.size(); i < n; i = j) {
                int cnt = 1;
                for (j = i+1; j < n; ++j) {
                    i = j;
                    if (lower_pos[j] != lower_pos[j-1] + 1)
                        break;
                    ++cnt;
                }
                res -= cnt * (cnt + 1) / 2;
            }

        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int left, right;

    // Output: 3
    nums = {2, 1, 4, 3};
    left = 2, right = 3;
    cout << sol.numSubarrayBoundedMax(nums, left, right) << endl;

    // Output: 7
    nums = {2,9,2,5,6};
    left = 2, right = 8;
    cout << sol.numSubarrayBoundedMax(nums, left, right) << endl;

    // Output: 2
    nums = {7,3,6,7,1};
    left = 1, right = 4;
    cout << sol.numSubarrayBoundedMax(nums, left, right) << endl;

    // Output: 22
    nums = {73,55,36,5,55,14,9,7,72,52};
    left = 32, right = 69;
    cout << sol.numSubarrayBoundedMax(nums, left, right) << endl;

    // Output: 5
    nums = {45,2,49,6,55,73,27,17,4,71};
    left = 17, right = 33;
    cout << sol.numSubarrayBoundedMax(nums, left, right) << endl;

    // Output: 24
    nums = {34,46,51,92,50,61,49,82,4,4};
    left = 18, right = 84;
    cout << sol.numSubarrayBoundedMax(nums, left, right) << endl;

    // Output: 0
    nums = {16,69,88,85,79,87,37,33,39,34};
    left = 55, right = 57;
    cout << sol.numSubarrayBoundedMax(nums, left, right) << endl;

    return 0;
}
