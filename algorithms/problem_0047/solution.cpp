/*
47. Permutations II
Total Accepted: 71535 Total Submissions: 254101 Difficulty: Medium

Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
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

void permute_unique(const vector<int>& nums, int index,
    vector<vector<int>>& result)
{
    int nsize = nums.size();
    if (index == nsize)
        return;
    vector<int> numbers = nums;

    sort(numbers.begin() + index, numbers.end());
    unordered_set<int> seen_numbers;
    for (int i = index; i < nsize; ++i)
    {
        if (seen_numbers.find(numbers[i]) != seen_numbers.end())
            continue;
        seen_numbers.emplace(numbers[i]);
        swap(numbers[i],numbers[index]);
        if (index+1 == nsize)
            result.emplace_back(numbers);
        else
            permute_unique(numbers, index+1, result);
        swap(numbers[i],numbers[index]);
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums);
};

vector<vector<int>> Solution::permuteUnique(vector<int>& nums)
{
    vector<vector<int>> result;
    permute_unique(nums, 0, result);

    return result;
}

int main()
{
    Solution sol;
    vector<vector<int>> result;
    vector<int> nums;

    nums = {1,2,3};
    result = sol.permuteUnique(nums);
    for (int i = 0; i < static_cast<int>(result.size()); ++i)
    {
        copy(result[i].begin(), result[i].end(),
            ostream_iterator<int>(cout, ","));
        cout << endl;
    }
    return 0;
}

