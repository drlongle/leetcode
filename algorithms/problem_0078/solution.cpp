/*
78. Subsets
Total Accepted: 96662 Total Submissions: 305340 Difficulty: Medium

Given a set of distinct integers, nums, return all possible subsets.
Note:
    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
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

#define ll long long int
#define ull unsigned long long int

using namespace std;

void get_subset(vector<int>& nums, ll i, vector<vector<int> >& result)
{
    vector<int> one_subset;
    while (i)
    {
        size_t index = log2(i & ~(i-1));
        one_subset.emplace_back(nums[index]);
        i &= (i-1);
    }
    result.emplace_back(one_subset);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (ll i = 0; i < (1ll << nums.size()); ++i)
            get_subset(nums, i, result);

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;

    return 0;
}

