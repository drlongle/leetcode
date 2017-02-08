/*
90. Subsets II
Total Accepted: 68460 Total Submissions: 222134 Difficulty: Medium

Given a collection of integers that might contain duplicates, return all possible subsets.
Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
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
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
};

void get_unique_subsets(vector<int>& nums, vector<bool>& used, int index,
    vector<int>& one_subset, vector<vector<int> >& result)
{
    int nsize = nums.size();
    unordered_set<int> seen_numbers;
    for (int i = index; i < nsize; ++i)
    {
        if (!used[i] && seen_numbers.find(nums[i]) == seen_numbers.end())
        {
            seen_numbers.emplace(nums[i]);
            one_subset.emplace_back(nums[i]);
            result.emplace_back(one_subset);
            used[i] = true;
            get_unique_subsets(nums, used, i+1, one_subset, result);
            used[i] = false;
            one_subset.pop_back();
        }
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<bool> used(nums.size(), false);
    vector<int> one_subset;
    result.emplace_back(one_subset);
    sort(nums.begin(), nums.end());
    get_unique_subsets(nums, used, 0, one_subset, result);

    return result;
}

int main()
{
    Solution sol;
    vector<vector<int> > result;
    vector<int> nums;
    nums = {1,2,2};
    result = sol.subsetsWithDup(nums);
    for (size_t i = 0; i < result.size(); ++i)
    {
        copy(result[i].begin(), result[i].end(),
            ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
 
    return 0;
}

