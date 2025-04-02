/*
3394. Check if Grid can be Cut into Sections
Medium

You are given an integer n representing the dimensions of an n x n grid, with
the origin at the bottom-left corner of the grid. You are also given a 2D array
of coordinates rectangles, where rectangles[i] is in the form [startx, starty,
endx, endy], representing a rectangle on the grid. Each rectangle is defined as
follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is
possible to make either two horizontal or two vertical cuts on the grid such
that:

Each of the three resulting sections formed by the cuts contains at least one
rectangle. Every rectangle belongs to exactly one section. Return true if such
cuts can be made; otherwise, return false.

Example 1:
Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
Output: true
Explanation:
The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y
= 4. Hence, output is true.

Example 2:
Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
Output: true
Explanation:
We can make vertical cuts at x = 2 and x = 3. Hence, output is true.

Example 3:
Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]
Output: false
Explanation:
We cannot make two horizontal or two vertical cuts that satisfy the conditions.
Hence, output is false.

Constraints:
3 <= n <= 109
3 <= rectangles.length <= 105
0 <= rectangles[i][0] < rectangles[i][2] <= n
0 <= rectangles[i][1] < rectangles[i][3] <= n
No two rectangles overlap.
*/

#include <algorithm>
#include <atomic>
#include <bit>
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

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
        vector<pair<int, bool>> x;
        vector<pair<int, bool>> y;

        for (auto &r : rectangles) {
            x.emplace_back(r[0], true);
            x.emplace_back(r[2], false);
            y.emplace_back(r[1], true);
            y.emplace_back(r[3], false);
        }

        ranges::sort(x);
        ranges::sort(y);
        for (auto &p : {x, y}) {
            for (int i = 0, sz = p.size(), count = 0, lines = 0; i < sz - 1;
                 ++i) {
                count += p[i].second ? 1 : -1;
                if (count == 0 && i > 0) {
                    if (++lines == 2)
                        return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    int n;
    vector<vector<int>> rectangles;

    n = 5,
    rectangles = {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
    cout << boolalpha << sol.checkValidCuts(n, rectangles) << endl;

    n = 4,
    rectangles = {{0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}};
    cout << boolalpha << sol.checkValidCuts(n, rectangles) << endl;

    n = 4,
    rectangles = {
        {0, 2, 2, 4}, {1, 0, 3, 2}, {2, 2, 3, 4}, {3, 0, 4, 2}, {3, 2, 4, 4}};
    cout << boolalpha << sol.checkValidCuts(n, rectangles) << endl;

    n = 3;
    rectangles = {{0, 0, 1, 3}, {1, 0, 2, 3}, {2, 0, 3, 3}};
    cout << boolalpha << sol.checkValidCuts(n, rectangles) << endl;

    return 0;
}
