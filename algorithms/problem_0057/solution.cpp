/*
57. Insert Interval
Total Accepted: 52072 Total Submissions: 224765 Difficulty: Hard

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary). You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
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

bool overlap(vector<int>& i1, vector<int>& i2)
{
    if (i1[1] < i2[0] || i2[1] < i1[0]) return false;
    else return true;
}

bool is_inside(const vector<int>& i1, const vector<int>& i2)
{
    return (i1[0] >= i2[0] && i1[1] <= i2[1]);
}

vector<int> merge_intervals(const vector<int>& i1, const vector<int>& i2)
{
    vector<int> result{min(i1[0],i2[0]), max(i1[1],i2[1])};
    return result; 
}

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        if (!intervals.empty())
        {
            if (is_inside(intervals.front(), newInterval) &&
                is_inside(intervals.back(), newInterval))
                return {newInterval};
        }
        vector<vector<int>> result = intervals;
        vector<int> interval = newInterval;
        vector<vector<int>>::iterator it;
        it = result.begin();
        while (it != result.end()) {
            if (overlap(*it, interval)) {
                interval = merge_intervals(*it, interval);
                it = result.erase(it);
            } else
                ++it;
        }
        result.emplace_back(interval);
        sort(result.begin(), result.end(),
          [](const vector<int>&i1, const vector<int>& i2)
          { return i1[0] < i2[0];});
        return result;
    }
};

void printIntervals(const vector<vector<int>>& intervals)
{
    for (const auto& r: intervals)
        cout << "[" << r[0] << "," << r[1] << "]" << endl;
}

int main()
{
    Solution sol;
    vector<vector<int>> input, result;
    vector<int> interval;

    input = {{1,3},{2,6},{8,10},{15,18}};
    interval = {2,5};

    result = sol.insert(input, interval);
    printIntervals(result);

    input = {{1,3},{6,9}};
    interval = {2,5};
    result = sol.insert(input, interval);
    printIntervals(result);

    return 0;
}
