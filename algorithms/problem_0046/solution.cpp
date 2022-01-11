/*
46. Permutations
Total Accepted: 100534 Total Submissions: 279224 Difficulty: Medium

Given a collection of distinct numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
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
    void permute(vector<int>& nums, vector<bool>& used,
        vector<int>& tempresult, vector<vector<int>>& result)
    {
        int nsize = nums.size();
        if (tempresult.size() == nums.size())
        {
            result.emplace_back(tempresult);
            return;
        }

        for (int i = 0; i < nsize; ++i)
        {
            if (!used[i])
            {
                used[i] = true;
                tempresult.emplace_back(nums[i]);
                permute(nums, used, tempresult, result);
                tempresult.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        int nsize = nums.size();
        vector<int> tempresult;
        vector<bool> used(nsize, false);
        permute(nums, used, tempresult, result);
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> result;
    vector<int> nums;

    nums = {1,2,3};
    result = sol.permute(nums);
    for (int i = 0; i < static_cast<int>(result.size()); ++i)
    {
        copy(result[i].begin(), result[i].end(),
            ostream_iterator<int>(cout, ","));
        cout << endl;
    }
    return 0;
}

