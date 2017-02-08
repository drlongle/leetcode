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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool overlap(const Interval& i1, const Interval& i2)
{
    if (i1.end < i2.start || i2.end < i1.start) return false;
    else return true;
}

bool is_inside(const Interval& i1, const Interval& i2)
{
    return (i1.start >= i2.start && i1.end <= i2.end);
}

Interval merge_intervals(const Interval& i1, const Interval& i2)
{
    Interval result(min(i1.start,i2.start), max(i1.end,i2.end));
    return result; 
}

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        if (!intervals.empty())
        {
            if (is_inside(intervals.front(), newInterval) &&
                is_inside(intervals.back(), newInterval))
                return {newInterval};
        }
        vector<Interval> result = intervals;
        Interval interval = newInterval;
        vector<Interval>::iterator it;
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
          [](const Interval&i1, const Interval& i2)
          { return i1.start < i2.start;});
        return result;
    }
};

void printIntervals(const vector<Interval>& intervals)
{
    for (const auto& r: intervals)
        cout << "[" << r.start << "," << r.end << "]" << endl;
}

int main()
{
    Solution sol;
    vector<Interval> input, result;
    Interval interval;

    input = {{1,3},{2,6},{8,10},{15,18}};
    interval = {2,5};

    result = sol.insert(input, interval);
    printIntervals(result);
    return 0;
}
