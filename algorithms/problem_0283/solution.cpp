/*
283. Move Zeroes
Total Accepted: 88113 Total Submissions: 196692 Difficulty: Easy

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.
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
    void moveZeroes(vector<int>& nums) {
        int w_index = 0;
        int nsize = nums.size();
        for (int i = 0; i < nsize; ++i)
        {
            if (nums[i])
                nums[w_index++] = nums[i];
        }
        for ( ; w_index < nsize; ++w_index)
            nums[w_index] = 0;
    }
};

int main()
{
    Solution sol;

    return 0;
}

