/*
56. Merge Intervals
Total Accepted: 58551 Total Submissions: 239494 Difficulty: Hard

Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18]. 
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

Interval merge_intervals(const Interval& i1, const Interval& i2)
{
    Interval result(min(i1.start,i2.start), max(i1.end,i2.end));
    return result; 
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        vector<Interval>::iterator it;
        for(auto& interval : intervals) {
            it = result.begin();
            while (it != result.end()) {
                if (overlap(*it, interval)) {
                    interval = merge_intervals(*it, interval);
                    it = result.erase(it);
                } else
                    ++it;
            }
            result.emplace_back(interval);
        }

        sort(result.begin(), result.end(),
            [](const Interval& i1, const Interval& i2)
            {return i1.start < i2.start;}); 
        return result;
    }
};

vector<Interval> generateIntervals()
{
    std::srand(std::time(0));
    vector<Interval> result;
    int size = rand() % 10; 
    for (int i = 0; i < size; ++i)
    {
        int i1 = rand() % 10000;
        int i2 = rand() % 100;
        result.emplace_back(i1,i1+i2);
    }
    return result;
}

void printIntervals(const vector<Interval>& intervals)
{
    for (const auto& r: intervals)
        cout << "[" << r.start << "," << r.end << "]" << endl;
}

int main()
{
    Solution sol;
    vector<Interval> input, result;
    input = {{1,3},{2,6},{8,10},{15,18}};
    input = generateIntervals();
    printIntervals(input);
    result = sol.merge(input);
    printIntervals(result);
    return 0;
}

