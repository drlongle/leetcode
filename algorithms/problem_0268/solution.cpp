/*
268. Missing Number
Total Accepted: 52965 Total Submissions: 130664 Difficulty: Medium

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it
using only constant extra space complexity?
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums);
};

int Solution::missingNumber(vector<int>& nums) {
    int nsize = nums.size();
    int result = nsize;
    for (int i = 0; i < nsize; ++i)
        result ^= i ^ nums[i];
    return result;
}

int main()
{
    Solution sol;
    vector<int> nums;
    nums = {0, 1, 3};
    nums = {2, 1, 4, 3};
    cout << "Result: " << sol.missingNumber(nums) << endl;

    return 0;
}

