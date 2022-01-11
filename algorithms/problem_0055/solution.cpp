/*
55. Jump Game
Total Accepted: 81476 Total Submissions: 285862 Difficulty: Medium

Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false. 
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nsize = nums.size();
        int dest = nsize-1;
        vector<bool> reach_dest(nsize, false);
        reach_dest[dest] = true;
        int next_reach_index = dest;
        for (int i = nsize-2; i >= 0; --i)
        {
            int offset = nums[i];
            if (i+offset >= next_reach_index)
            {
                reach_dest[i] = true;
                next_reach_index = i;
            }
         }

        return reach_dest[0];
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
  
    // Expected: true
    nums = {2,3,1,1,4};
    cout << boolalpha << "Result: " << sol.canJump(nums) << endl;
  
    return 0;
}

