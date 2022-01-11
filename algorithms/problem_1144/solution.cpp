/*
1144. Decrease Elements To Make Array Zigzag
Medium

Given an array nums of integers, a move consists of choosing any element
and decreasing it by 1. An array A is a zigzag array if either:

Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.

Example 1:
Input: nums = [1,2,3]
Output: 2
Explanation: We can decrease 2 to 0 or 3 to 1.

Example 2:
Input: nums = [9,6,1,6,2]
Output: 4
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int adjust(vector<int>& nums, int index)
    {
        int nsize = nums.size();
        int count = 0;
        while (index < nsize) {
            int temp = 0;
            if (index - 1 >= 0)
                temp = max(0, nums[index] - nums[index - 1] + 1);
            if (index + 1 < nsize)
                temp = max(temp, max(0, nums[index] - nums[index + 1] + 1));
            count += temp;
            index += 2;
        }
        return count;
    }

    int movesToMakeZigzag(vector<int>& nums)
    {
        return min(adjust(nums, 0), adjust(nums, 1));
    }
};

int main()
{
    Solution sol;
    vector<int> nums;

    // Expected: 3
    nums = {1, 2, 3};

    // Expected: 4
    nums = {9, 6, 1, 6, 2};

    // Expected: 8
    nums = {7, 6, 13, 6, 7, 12, 5};

    cout << "Result: " << sol.movesToMakeZigzag(nums) << endl;

    return 0;
}
