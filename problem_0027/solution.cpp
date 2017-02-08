/*
27. Remove Element
Total Accepted: 122852 Total Submissions: 357372 Difficulty: Easy

Given an array and a value, remove all instances of that value in place and return the new length. Do not allocate extra space for another array, you must do this in place with constant memory. The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

Hint:
    Try two pointers.
    Did you use the property of "the order of elements can be changed"?
    What happens when the elements to remove are rare?
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
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

#define ll long long
#define ull unsigned long long

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int begin = 0, end = nums.size()-1;
        while (begin <= end)
        {
            while (begin <= end && nums[begin] != val)
                ++begin;
            while (begin <= end && nums[end] == val)
                --end;
            if (begin < end)
                swap(nums[begin++], nums[end--]);
            else
                break;
        }
        return begin;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int val, res;

    nums = {0,2,4,3,0,0};
    val = 4;
    res = sol.removeElement(nums, val);
    cout << "Result: " << res << endl;
    for (int i = 0; i < res; ++i)
        cout << nums[i] << ",";
    cout << endl;

    return 0;
}

