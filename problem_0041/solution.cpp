/*
41. First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3, and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
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
    int firstMissingPositive(vector<int>& nums)
    {
        auto it = partition(nums.begin(), nums.end(), [](const int& n)
            {return n > 0;});
        int s_size = distance(nums.begin(), it);
        if (!s_size) return 1;

        for (int i = 0; i < s_size; ++i)
        {
            int n = nums[i];
            int index = abs(n)-1;
            if (index < s_size && nums[index] > 0)
                nums[index] = - nums[index];
        }

        for (int i = 0; i < s_size; ++i)
            if (nums[i] > 0) return i+1;

        return s_size+1;
    }
};

int main()
{
    Solution sol;
    vector<int> input;

    // Expected: 2
    input = {3,4,-1,1};
    cout << "Result: " << sol.firstMissingPositive(input);

    return 0;
}
