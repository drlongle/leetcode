/*
593. Valid Square
Medium

Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    double distance(vector<int>& p1, vector<int>& p2) {
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        return sqrt(x*x + y*y);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        double d12 = distance(p1, p2);
        double d13 = distance(p1, p3);
        double d14 = distance(p1, p4);
        if (d12 != d13 && d13 != d14 && d12 != d14)
            return false;
        if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4)
            return false;
        if (d12 == d13) {
            swap(p3, p4);
            swap(d13, d14);
        }
        if (d13 == d14) {
            swap(p3, p2);
            swap(d12, d13);
        }

        double d23 = distance(p2, p3);
        double d24 = distance(p2, p4);
        double d34 = distance(p3, p4);
        if (d23 != d34 || d23 != d12)
            return false;

        return d13 == d24;
    }
};

int main() {
    Solution sol;
    vector<int> p1, p2, p3, p4;

    // True
    p1 = {0,0}, p2 = {1,1}, p3 = {1,0}, p4 = {0,1};
    cout << boolalpha << sol.validSquare(p1, p2, p3, p4) << endl;

    return 0;
}
