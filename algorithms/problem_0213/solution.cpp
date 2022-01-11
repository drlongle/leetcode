/*
213. House Robber II
Total Accepted: 30260 Total Submissions: 97290 Difficulty: Medium

Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include <algorithm>
#include <array>
#include <cassert>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int nsize = nums.size();
        if (nsize == 1) return nums[0];
        m_robs = vector<vector<int>>(nsize, vector<int>(nsize,-1));
        return max(rob(nums, 0, nsize-2), rob(nums,1,nsize-1));
    }

    int rob(vector<int>& nums, int begin, int end) {
        if (begin > end) return 0;
        if (begin == end) return nums[begin];

        if (m_robs[begin][end] >= 0) return m_robs[begin][end];
        int res1,res2;
        if (!begin)
        {
            res1 = nums[begin] + rob(nums, begin+2, end);
            res2 = nums[end] + rob(nums, begin, end-2);
        }
        else
        {
            res1 = nums[begin] + rob(nums, begin+2, end);
            res2 = nums[begin+1] + rob(nums, begin+3, end);
        }
        int res = max(res1,res2);
        m_robs[begin][end] = res;
        return res;
    }

    vector<vector<int>> m_robs;
};

int main()
{
    Solution sol;
    vector<int> input;
    input = {1,2,3,4,5};
    cout << "Result: " << sol.rob(input) << endl;

    return 0;
}

