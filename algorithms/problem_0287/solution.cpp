/*
287. Find the Duplicate Number  
Total Accepted: 25605 Total Submissions: 66482 Difficulty: Hard

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
    You must not modify the array (assume the array is read only).
    You must use only constant, O(1) extra space.
    Your runtime complexity should be less than O(n^2).
    There is only one duplicate number in the array, but it could be repeated more than once.
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
    pair<int,int> countRange(vector<int>& nums, int upper_bound) {
        pair<int,bool> result{0, false};
        int count = 0;
        for (const auto n: nums) {
            if (n <= upper_bound)
                ++result.first;
            if (n == upper_bound)
                ++count;
        }

        if (count > 1)
            result.second = true;
        return result;
    }

    int findDuplicate(vector<int>& nums) {
        int begin = 1;
        int mid, end = nums.size()-1;
        while (begin < end) {
            mid = begin + ((end-begin) >> 1);
            pair<int,bool> temp = countRange(nums, mid);
            if (temp.second)
                return mid;
            if (temp.first > mid)
                end = mid-1;
            else
                begin = mid+1;
        }
        return begin;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {1,2,2};
    cout << "Answer: " << sol.findDuplicate(nums) << endl;

    return 0;
}

