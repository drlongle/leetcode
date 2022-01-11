/*
162. Find Peak Element  
Total Accepted: 63134 Total Submissions: 191514 Difficulty: Medium

A peak element is an element that is greater than its neighbors.
Given an input array where num[i] != num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -infinity

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
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
    int findPeakElement(vector<int>& nums) {
        int size = static_cast<int>(nums.size()); 
        if (!size) return 0;

        // dir: true for going up, false for going down
        bool prev_dir = true, dir;
        for (int i = 0; i < size-1; ++i)
        {
            dir = nums[i+1] > nums[i];
            if (dir != prev_dir)
                return i;
            prev_dir = dir;
        }
        dir = false;
        if (prev_dir != dir)
            return size-1;
        else
            return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {1, 2, 3, 1};
    cout << "Answer: " << sol.findPeakElement(nums) << endl;

    return 0;
}

