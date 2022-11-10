/*
699. Falling Squares
Hard

There are several squares being dropped onto the X-axis of a 2D plane.

You are given a 2D integer array positions where positions[i] = [lefti,
sideLengthi] represents the ith square with a side length of sideLengthi that is
dropped with its left edge aligned with X-coordinate lefti.

Each square is dropped one at a time from a height above any landed squares. It
then falls downward (negative Y direction) until it either lands on the top side
of another square or on the X-axis. A square brushing the left/right side of
another square does not count as landing on it. Once it lands, it freezes in
place and cannot be moved.

After each square is dropped, you must record the height of the current tallest
stack of squares.

Return an integer array ans where ans[i] represents the height described above
after dropping the ith square.

Example 1:
Input: positions = [[1,2],[2,3],[6,1]]
Output: [2,5,5]
Explanation:
After the first drop, the tallest stack is square 1 with a height of 2.
After the second drop, the tallest stack is squares 1 and 2 with a height of 5.
After the third drop, the tallest stack is still squares 1 and 2 with a height
of 5. Thus, we return an answer of [2, 5, 5].

Example 2:
Input: positions = [[100,100],[200,100]]
Output: [100,100]
Explanation:
After the first drop, the tallest stack is square 1 with a height of 100.
After the second drop, the tallest stack is either square 1 or square 2, both
with heights of 100. Thus, we return an answer of [100, 100]. Note that square 2
only brushes the right side of square 1, which does not count as landing on it.

Constraints:
1 <= positions.length <= 1000
1 <= left[i] <= 10^8
1 <= sideLength[i] <= 10^6
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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
#include <ranges>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    struct Line {
        Line(int s, int e, int h) : start{s}, end{e}, height{h} {}
        int start, end, height;
    };

    bool overlap(Line &a, Line &b) {
        return b.end > a.start && a.end > b.start;
    }

    bool contain(Line &a, Line &b) {
        return (a.start <= b.start && b.end <= a.end);
    }

    int get_height(vector<Line> &lines, Line &line) {
        int height = 0;
        for (auto it = begin(lines); it != end(lines);) {
            auto overlapped = overlap(*it, line);
            if (overlapped)
                height = max(height, it->height);
            auto contained = overlapped && contain(line, *it);
            if (contained)
                it = lines.erase(it);
            else
                ++it;
        }
        return height;
    }
    vector<int> fallingSquares(vector<vector<int>> &positions) {
        vector<Line> lines;
        vector<int> res;
        int max_h{0};
        for (auto &position : positions) {
            int x = position[0], y = position[1];
            Line line(x, x + y, 0);
            line.height = get_height(lines, line) + y;
            max_h = max(max_h, line.height);
            lines.push_back(line);
            res.push_back(max_h);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> positions;
    vector<int> res;

    // Output: {2,5,5}
    positions = {{1, 2}, {2, 3}, {6, 1}};
    res = sol.fallingSquares(positions);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {100,100}
    positions = {{100, 100}, {200, 100}};
    res = sol.fallingSquares(positions);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,2,4}
    positions = {{6, 1}, {9, 2}, {2, 4}};
    res = sol.fallingSquares(positions);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {5,7,7}
    positions = {{1, 5}, {2, 2}, {7, 5}};
    res = sol.fallingSquares(positions);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {10,17,19,20,25}
    positions = {{5, 10}, {1, 7}, {1, 2}, {9, 3}, {1, 6}};
    res = sol.fallingSquares(positions);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    // Output: {1,6,13]
    positions = {{9, 1}, {6, 5}, {6, 7}};
    res = sol.fallingSquares(positions);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
