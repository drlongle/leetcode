/*
1150. Check If a Number Is Majority Element in a Sorted Array
Easy

Given an array nums sorted in non-decreasing order, and a number target, return True if and only if target is a majority element.

A majority element is an element that appears more than N/2 times in an array of length N.

Example 1:

Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: 
The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.

Example 2:
Input: nums = [10,100,101,101], target = 101
Output: false
Explanation: 
The value 101 appears 2 times and the length of the array is 4.
Thus, 101 is not a majority element because 2 > 4/2 is false.
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
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:

    int find_index(vector<int>& nums, int target, bool first) {
        int begin = 0, end = nums.size() - 1;
        int res = - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                res = mid;
                if (first)
                    end = mid- 1;
                else
                    begin = mid + 1;
            } else if (nums[mid] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        
        return res;
    }
    
    bool isMajorityElement(vector<int>& nums, int target) {
        int first = find_index(nums, target, true);
        int last = find_index(nums, target, false);
        if (first < 0)
            return false;
        return last - first + 1 > static_cast<int>(nums.size()) / 2;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int target;

    // Expected: true
    nums = {2,4,5,5,5,5,5,6,6}, target = 5;

    // Expected: false
    nums = {10,100,101,101}, target = 101;
    
    cout << "Result: " << sol.isMajorityElement(nums, target) << endl;
    
    return 0;
}

