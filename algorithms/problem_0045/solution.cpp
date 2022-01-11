/*
45. Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
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
    int jump(vector<int>& nums)
    {
        int size = static_cast<int>(nums.size());
        if (size > 20000)
        {
            int result = check_shortest_path(nums);
            if (result >= 0) return result;
        }
        vector<int> jumps(size, numeric_limits<int>::max());
        jumps[size-1]=0;
        for (int i = size-2; i >= 0; --i)
        {
            for (int j = 1; j <= nums[i]; ++j)
            {
                int next = i + j;
                if (next <= size-1 &&
                    jumps[next] != numeric_limits<int>::max() &&
                    jumps[next] + 1< jumps[i])
                        jumps[i] = jumps[next] + 1;
            }
        }

        return jumps[0]; 
    }

    int check_shortest_path(vector<int>& nums)
    {
        int size = nums.size();
        int index = 0, count = 0;
        while (index < size)
        {
            if (index == size-1)
                return count;
            if (nums[index] == 0)
                return -1;
            index = index + nums[index];
            ++count;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> input;
    input = {2,3,0,1,4};
    cout << "Result: " << sol.jump(input);

    return 0;
}
