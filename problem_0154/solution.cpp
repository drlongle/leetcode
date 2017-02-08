/*
154. Find Minimum in Rotated Sorted Array II  
Total Accepted: 49683 Total Submissions: 145026 Difficulty: Hard

    Follow up for "Find Minimum in Rotated Sorted Array":
    What if duplicates are allowed?
    Would this affect the run-time complexity? How and why?

Suppose a sorted array is rotated at some pivot unknown to you beforehand
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.  The array may contain duplicates.
*/

#include <algorithm>
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
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size()-1;
        int ans = nums[0];
        while (begin < end) {
            if (nums[begin] < nums[end])
                return min(ans,nums[begin]);
            if (nums[begin] == nums[end])
                return min(ans, find_min_sequential(nums,begin,end));
            int mid = begin + ((end-begin)>>1);
            if (nums[mid] < ans)
                ans = nums[mid];
            if (nums[begin] > nums[mid] || nums[mid] < nums[end])
                end = mid-1;
            else
                begin = mid+1;
        }

        return min(ans,nums[begin]);
    }

    int find_min_sequential(vector<int>& nums, int begin, int end)
    {
        int ans = nums[begin];
        for (int i = begin+1; i <= end; i++)
        {
            if (nums[i] < ans)
                ans = nums[i];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Answer: " << sol.findMin(nums) << endl;

    return 0;
}

