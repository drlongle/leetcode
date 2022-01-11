/*
33. Search in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). You are given a target value to search. If found in the array return its index, otherwise return -1. You may assume no duplicate exists in the array.
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
    int search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = static_cast<int>(nums.size()) -1;
        if (high == -1) return -1;
        if (high == 0) return (nums[0] == target) ? 0 : -1;
        int middle;
        while (low < high)
        {
            if (nums[low] == target) return low;
            if (nums[high] == target) return high;
            middle = low + ((high-low) >> 1);
            if (nums[middle] == target) return middle;
            if (nums[low] < nums[middle])
            {
                if (nums[low ] < target && target < nums[middle])
                    high = middle-1;
                else
                    low = middle+1;
            }
            else
            {
                if (nums[middle ] < target && target < nums[high])
                    low = middle+1;
                else
                    high = middle-1;
            }
        }
        return (nums[low] == target) ? low : -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target = -1;

    cout << "Result: " << sol.search(nums, target) << endl;
    return 0;
}

