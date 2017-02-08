/*
35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 -> 2
[1,3,5,6], 2 -> 1
[1,3,5,6], 7 -> 4
[1,3,5,6], 0 -> 0 
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
    int searchInsert(vector<int>& nums, int target) {
        int s_size = static_cast<int>(nums.size());
        if (s_size == 0) return 0;
        if (s_size == 1) {
            if (nums[0] >= target) return 0;
            else return 1;
        }
        if (nums[0] > target) return 0;
        if (nums[s_size-1] < target) return s_size;

        int low = 0, high = s_size-1;
        int middle;
        while (low < high)
        {
            if (nums[low]== target) return (low>0) ? low : 0;
            if (nums[high]== target) return (high>0) ? high : 0;
            middle = low + ((high-low) >> 1);
            if (nums[middle]== target) return (middle>0) ? middle-1 : 0;
            else if (nums[middle] > target) high = middle-1;
            else low = middle+1;
        }

        int result;
        if (nums[low] < target)
        {
            if (low == s_size-1) return s_size;
            else if (nums[low+1] > target) return low+1;
                result = s_size-1;
            low = low+1;
            high = s_size-1;
        }
        else
        {
            result = low;
            low = 0;
            high = low-1;
        }

        while (low < high)
        {
            middle = low + ((high-low) >> 1);
            if (nums[middle] < target) low = middle+1;
            else
            {
                result = middle;
                high = middle-1;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int target;
    nums = {1,3,5,6};
    target = 5;

    cout << "Result: " << sol.searchInsert(nums, target);
    return 0;
}
