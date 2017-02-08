/*
26. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length. 
*/

#include <algorithm>
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
    int removeDuplicates(vector<int>& nums)
    {
        int n_size = static_cast<int>(nums.size());
        if (n_size <= 1) return n_size;
        int plow = 1, pfast=1;
        for ( ; pfast < n_size; pfast++)
            if (nums[pfast] != nums[plow-1])
                nums[plow++] = nums[pfast];
        return plow;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{1, 1, 1, 1, 1, 1, 1};
    cout << "Result: " << sol.removeDuplicates(nums) << endl;

    return 0;
}

