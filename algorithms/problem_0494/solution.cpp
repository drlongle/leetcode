/*
494. Target Sum

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    void findTargetSumWays(vector<int>& nums, int index, int target, int& res) {
        if (index == static_cast<int>(nums.size())) {
            if (target == 0)
                ++res;
            return;
        }

        findTargetSumWays(nums, index+1, target - nums[index], res);
        findTargetSumWays(nums, index+1, target + nums[index], res);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        findTargetSumWays(nums, 0, target, res);
        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    vector<int> nums;
    int target;

    nums = {1, 1, 1, 1, 1};
    target = 3;
    cout << "Result: " << sol.findTargetSumWays(nums, target) << endl;

    return 0;
}

