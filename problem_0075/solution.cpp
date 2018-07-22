/*
75. Sort Colors  
Total Accepted: 97818 Total Submissions: 281427 Difficulty: Medium

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively. 

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with an one-pass algorithm using only constant space?
*/

#include <algorithm>
#include <cassert>
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
    void sortColors(vector<int>& nums) {
        int lower = 0, equal = 0, upper = nums.size()-1;
        while (equal <= upper) {
            if (nums[equal] == 0) {
                swap(nums[equal++], nums[lower]);
                ++lower;
            } else if (nums[equal] == 1)
                equal++;
            else
                swap(nums[equal], nums[upper--]);
        }
    } 
};

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {1,2,1,2,0,1,2,1,0,2,2,1,0,2,1,0,1};
    sol.sortColors(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));

    return 0;
}

