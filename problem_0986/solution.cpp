/*
986. Interval List Intersections
Difficulty: Medium

Given two lists of closed intervals, each list of intervals is pairwise disjoint
and in sorted order. Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real
numbers x with a <= x <= b.  The intersection of two closed intervals is a set
of real numbers that is either empty, or can be represented as a closed interval.
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> res;
        for (int i = 0, j = 0; i < A.size() && j < B.size(); ) {
            Interval& a = A[i];
            Interval& b = B[j];
            if (intersect(a, b))
                res.emplace_back(max(a.start, b.start), min(a.end, b.end));
            if (a.end < b.end)
                ++i;
            else if (a.end == b.end)
                ++i, ++j;
            else
                ++j;
        }
        
        return res;
    }
    
    bool intersect(const Interval& a, const Interval& b) {
        return a.end >= b.start && b.end >= a.start;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<Interval> A, B, res;

    // Expected: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
    A = {{0,2},{5,10},{13,23},{24,25}}, B = {{1,5},{8,12},{15,24},{25,26}};
    res = sol.intervalIntersection(A, B);
    for (auto& interval: res)
        cout << "[" << interval.start << "," << interval.end << "}" << endl;
    
    return 0;
}
