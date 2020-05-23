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

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < A.size() && j < B.size(); ) {
            const auto& a = A[i];
            const auto& b = B[j];
            if (intersect(a, b))
                res.emplace_back(vector<int>{max(a[0], b[0]), min(a[1], b[1])});
            if (a[1] < b[1])
                ++i;
            else if (a[1] == b[1])
                ++i, ++j;
            else
                ++j;
        }

        return res;
    }

    bool intersect(const vector<int>& a, const vector<int>& b) {
        return a[1] >= b[0] && b[1] >= a[0];
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<vector<int>> A, B, res;

    // Expected: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
    A = {{0,2},{5,10},{13,23},{24,25}}, B = {{1,5},{8,12},{15,24},{25,26}};
    res = sol.intervalIntersection(A, B);
    for (auto& interval: res)
        cout << "[" << interval[0] << "," << interval[1] << "}" << endl;

    return 0;
}
