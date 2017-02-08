/*
40. Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. Each number in C may only be used once in the combination.

Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, ... , ak) must be in non-descending order (i.e., a1 <= a2 <= ... <= ak).
 The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <climits>
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

#include <string.h>

using namespace std;

class Solution {
public:
    void combine(vector<int>& candidates, int begin, int end,
        vector<int>& currpath, set<vector<int>>& result, int target)
    {
        for (int i = begin; i < end; ++i)
        {
            if (target < candidates[i])
                return;
            else
            {
                currpath.emplace_back(candidates[i]);
                if (target == candidates[i])
                    result.emplace(currpath);
                else
                    combine(candidates,i+1, end, currpath, result,
                        target-candidates[i]);
                currpath.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> result_set;
        vector<vector<int>> result;
        vector<int> currpath;
        combine(candidates, 0, candidates.size(), currpath, result_set, target);
        for (auto const& s: result_set)
            result.push_back(s);

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> input;
    int target;
    vector<vector<int>> result;

    input = {10,1,2,7,6,1,5};
    target = 8;
    result = sol.combinationSum2(input, target);
    for (const auto& r: result)
    {
        copy(r.begin(), r.end(), ostream_iterator<int>(cout, ","));
        cout << endl;
    }

    return 0;
}
