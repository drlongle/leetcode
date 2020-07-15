/*
1509. Minimum Difference Between Largest and Smallest Value in Three Moves
Medium

Given an array nums, you are allowed to choose one element of nums and change it by any value in one move.

Return the minimum difference between the largest and smallest value of nums after perfoming at most 3 moves.

Example 1:
Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.

Example 2:
Input: nums = [1,5,0,10,14]
Output: 1
Explanation: Change the array [1,5,0,10,14] to [1,1,0,1,1]. 
The difference between the maximum and minimum is 1-0 = 1.

Example 3:
Input: nums = [6,6,0,1,1,4,6]
Output: 2

Example 4:
Input: nums = [1,5,6,14,15]
Output: 1

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
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
    int minDifference(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 3)
            return 0;
        sort(begin(nums), end(nums));
        int res = numeric_limits<int>::max();
        for (int i = 0; i <= 3; ++i) {
            int index = sz-4+i;
            if (index >= 0 && index < sz)
                res = min(res, nums[sz-4+i] - nums[i]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {5,3,2,4};
    cout << sol.minDifference(nums) << endl;

    nums = {1,5,0,10,14};
    cout << sol.minDifference(nums) << endl;

    nums = {6,6,0,1,1,4,6};
    cout << sol.minDifference(nums) << endl;

    nums = {1,5,6,14,15};
    cout << sol.minDifference(nums) << endl;

    return 0;
}
