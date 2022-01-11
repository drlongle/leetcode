/*
77. Combinations
Total Accepted: 76126 Total Submissions: 219760 Difficulty: Medium

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
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
    vector<vector<int>> combine(int n, int k);
};

void do_combinations(vector<int>& nums, vector<int>& tempresult, int index,
    int k, vector<vector<int>>& result)
{
    int nsize = nums.size();
    if (static_cast<int>(tempresult.size()) >= k)
        return;

    for (int i = index; i < nsize; ++i)
    {
        tempresult.emplace_back(nums[i]);
        if (static_cast<int>(tempresult.size()) == k)
            result.emplace_back(tempresult);
        else
            do_combinations(nums, tempresult, i+1, k, result);
        tempresult.pop_back();
    }
}

vector<vector<int>> Solution::combine(int n, int k)
{
    vector<vector<int>> result;
    vector<int> numbers(n), tempresult;
    iota(numbers.begin(), numbers.end(), 1);
    do_combinations(numbers, tempresult, 0, k, result);

    return result;
}

int main()
{
    Solution sol;
    vector<vector<int>> result;
    int n, k;
    n = 4, k = 2;
    result = sol.combine(n,k);
    for (size_t i = 0; i < result.size(); ++i)
    {
        copy(result[i].begin(), result[i].end(),
            ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}

