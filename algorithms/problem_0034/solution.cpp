/*
34. Search for a Range

Given a sorted array of integers, find the starting and ending position of a given target value. Your algorithm's runtime complexity must be in the order of O(log n). If the target is not found in the array, return [-1, -1].

For example: Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
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
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int low = 0;
        int high = static_cast<int>(nums.size())-1;
        int s_size = high;
        if (high == -1) return {-1, -1};
        int begin = -1, end = -1;
        int middle = low;
        while(low < high)
        {
            if (nums[low] == target && nums[high] == target) return {low, high};
            if (nums[low] == target)
            {
                middle = low;
                break;
            }
            if (nums[high] == target)
            {
                middle = high;
                break;
            }
            middle = low + ((high-low) >> 1);
            if (nums[middle] == target)
                break;
            else if (nums[middle] > target)
                high = middle-1;
            else
                low = middle+1;
        }

        if (nums[middle] == target)
        {
            begin = end = middle;
            int old_middle = middle;
            low = 0;
            high = middle-1;
            while (low < high)
            {
                middle = low + ((high-low) >> 1);
                if (nums[middle] == target)
                {
                    begin = min(begin, middle);
                    high = middle-1;
                } else
                    low = middle+1;
            }

            if (low >= 0 && nums[low] == target)
                begin = min(begin, low);

            low = old_middle+1;
            high = s_size-1;
            while(low < high)
            {
                middle = low + ((high-low) >> 1);
                if (nums[middle] == target)
                {
                    end = max(end, middle);
                    low = middle+1;
                }
                else
                    high = middle-1;
            }
            if (low < s_size && nums[low] == target)
                end = max(end, low);
        }

        return {begin, end};
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int target;

    nums = {5, 7, 7, 8, 8, 8, 8, 8, 8, 10};
    target = 8;

    vector<int> result = sol.searchRange(nums, target);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, ","));
    return 0;
}

