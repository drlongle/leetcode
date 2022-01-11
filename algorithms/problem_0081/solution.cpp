/*
81. Search in Rotated Sorted Array II  
Total Accepted: 61243 Total Submissions: 191935 Difficulty: Medium

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
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


using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int begin, int end, int target) {
        if (begin > end)
            return false;
        int mid = begin + ((end-begin) >> 1);
        if (nums[mid] == target || nums[begin] == target || nums[end] == target)
            return true;
        if (nums[begin] == nums[mid] || nums[mid] == nums[end])
            return search(nums, begin+1, mid-1, target) ||
                search(nums, mid+1, end-1, target);
        if (nums[begin] < nums[mid])
        {
            if (nums[begin] < target && target < nums[mid])
                return search(nums,begin, mid-1, target);
            else
                return search(nums,mid+1, end, target);
        }

        if (nums[mid] < target && target < nums[end])
            return search(nums, mid+1, end, target);
        else
            return search(nums, begin, mid-1, target);
    }

    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int target;
    nums = {1,1,3,1};
    target = 3,
    cout << boolalpha << sol.search(nums, target) << endl;

    return 0;
}

