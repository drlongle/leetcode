/*
39. Combination Sum

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. The same repeated number may be chosen from C unlimited number of times.

Note:
  All numbers (including target) will be positive integers.
  Elements in a combination (a1, a2, ... , ak) must be in non-descending order (i.e., a1 <= a2 <= ... = ak).
  The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
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
        vector<int>& currpath, vector<vector<int>>& result, int target)
    {
        for (int i = begin; i < end; ++i)
        {
            if (target < candidates[i])
                return;
            else
            {
                currpath.emplace_back(candidates[i]);
                if (target == candidates[i])
                    result.emplace_back(currpath);
                else
                    combine(candidates,i, end, currpath, result,
                        target-candidates[i]);
                currpath.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        auto last = unique(candidates.begin(), candidates.end());
        candidates.erase(last, candidates.end());
        vector<vector<int>> result;
        vector<int> currpath;
        combine(candidates, 0, candidates.size(), currpath, result, target);

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> input;
    int target;
    vector<vector<int>> result;

    input = {2,3,6,7};
    target = 7;
    result = sol.combinationSum(input, target);
    for (const auto& r: result)
    {
        copy(r.begin(), r.end(), ostream_iterator<int>(cout, ","));
        cout << endl;
    }

    return 0;
}
