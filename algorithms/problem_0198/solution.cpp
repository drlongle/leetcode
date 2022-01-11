/*
198. House Robber
Difficulty: Easy

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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
#include <vector>

#include <string.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        m_size = static_cast<int>(nums.size());
        if (m_size == 0) return 0;
        return rob(nums, 0);
    }

    int rob(vector<int>& nums, int begin) {
        if (begin >= m_size) return 0;
        if (m_robs.find(begin) != m_robs.end()) return m_robs[begin];
        int res1 = nums[begin] + rob(nums, begin+2);
        if (begin+1 < m_size) {
            int res2 = nums[begin+1] + rob(nums, begin+3);
            if (res2 > res1) res1 = res2;
        }
        m_robs[begin] = res1;
        return res1;
    }

    map<int, int> m_robs;
    int m_size;
};

int main()
{
    Solution sol;
    vector<int> input;
    input = {5,1,5,5,2,5,4};
    cout << "Result: " << sol.rob(input) << endl;

    return 0;
}
