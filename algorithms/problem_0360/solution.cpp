/*
360. Sort Transformed Array
Medium

Given a sorted integer array nums and three integers a, b and c, apply a quadratic function of the form
f(x) = ax2 + bx + c to each element nums[i] in the array, and return the array in a sorted order.

Example 1:
Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]

Example 2:
Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]

Constraints:
1 <= nums.length <= 200
-100 <= nums[i], a, b, c <= 100
nums is sorted in ascending order.

Follow up: Could you solve it in O(n) time?
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
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        transform(begin(nums), end(nums), nums.begin(), [a, b, c] (int n)
        {return a*n*n + b*n + c;});
        sort(begin(nums), end(nums));
        return nums;
    }
};

int main() {
    Solution sol;

    return 0;
}
