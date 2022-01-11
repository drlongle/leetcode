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

bool overlap(const vector<int>& i1, const vector<int>& i2)
{
    if (i1[1] < i2[0] || i2[1] < i1[0]) return false;
    else return true;
}

vector<int> merge_intervals(const vector<int>& i1, const vector<int>& i2)
{
    return vector<int>{min(i1[0],i2[0]), max(i1[1],i2[1])};
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        vector<vector<int>>::iterator it;
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

        sort(result.begin(), result.end());

        return result;
    }
};

vector<vector<int>> generateIntervals()
{
    std::srand(std::time(0));
    vector<vector<int>> result;
    int size = rand() % 10; 
    for (int i = 0; i < size; ++i)
    {
        int i1 = rand() % 10000;
        int i2 = rand() % 100;
        result.emplace_back(vector<int>{i1,i1+i2});
    }
    return result;
}

void printIntervals(const vector<vector<int>>& intervals)
{
    for (const auto& r: intervals)
        cout << "[" << r[0] << "," << r[1] << "]" << endl;
}

int main()
{
    Solution sol;
    vector<vector<int>> input, result;
    input = {{1,3},{2,6},{8,10},{15,18}};
    input = generateIntervals();
    printIntervals(input);
    result = sol.merge(input);
    printIntervals(result);
    return 0;
}

