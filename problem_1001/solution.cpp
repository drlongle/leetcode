/*
1001. Grid Illumination
Difficulty: Hard

On a N x N grid of cells, each cell (x, y) with 0 <= x < N and 0 <= y < N has a lamp.

Initially, some number of lamps are on.  lamps[i] tells us the location of the i-th lamp that is on.  Each lamp that is on illuminates every square on its x-axis, y-axis, and both diagonals (similar to a Queen in chess).

For the i-th query queries[i] = (x, y), the answer to the query is 1 if the cell (x, y) is illuminated, else 0.

After each query (x, y) [in the order given by queries], we turn off any lamps that are at cell (x, y) or are adjacent 8-directionally (ie., share a corner or edge with cell (x, y).)

Return an array of answers.  Each value answer[i] should be equal to the answer of the i-th query queries[i]

Example 1:

Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
Output: [1,0]
Explanation: 
Before performing the first query we have both lamps [0,0] and [4,4] on.
The grid representing which cells are lit looks like this, where [0,0] is the top left corner, and [4,4] is the bottom right corner:
1 1 1 1 1
1 1 0 0 1
1 0 1 0 1
1 0 0 1 1
1 1 1 1 1
Then the query at [1, 1] returns 1 because the cell is lit.  After this query, the lamp at [0, 0] turns off, and the grid now looks like this:
1 0 0 0 1
0 1 0 0 1
0 0 1 0 1
0 0 0 1 1
1 1 1 1 1
Before performing the second query we have only the lamp [4,4] on.  Now the query at [1,0] returns 0, because the cell is no longer lit.
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
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

#define ll long long
#define ull unsigned long long

namespace std {
    template <> struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& param) const {
            return param.first ^ param.second;
        }
    };
}

class Solution {
public:

    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries)
    {
        vector<int> res;
        unordered_map<int, int> rows, columns, forwards, backwards;
        unordered_set<pair<int, int>> lamp_cells;

        for (auto& lamp: lamps) {
            int x = lamp[0], y = lamp[1];
            ++rows[x], ++columns[y];
            ++forwards[y-x], ++backwards[y+x];
            lamp_cells.emplace(x,y);
        }

        for (auto& q : queries) {
            int x = q[0], y = q[1];
            bool lit = rows[x] || columns[y] || forwards[y-x] || backwards[y+x];
            res.push_back(lit);
            for (auto& off: offsets) {
                int n_x = x + off[0];
                int n_y = y + off[1];
                pair<int, int> nxy{n_x, n_y};
                auto nit = lamp_cells.find(nxy);
                if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N && nit != lamp_cells.end()) {
                    --rows[n_x], --columns[n_y];
                    --forwards[n_y-n_x], --backwards[n_y+n_x];
                    lamp_cells.erase(nit);
                }
            }
        }

        return res;
    }

    vector<vector<int>> offsets{{0,0},{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
};

int main() {
    Solution sol;
    int N;
    vector<vector<int>> lamps, queries;

    N = 5, lamps = {{0,0},{4,4}}, queries = {{1,1},{1,0}};

    // 8 / 38 test cases passed
    // Expected: [1,1]
    N = 5, lamps = {{0,0},{4,4}}, queries = {{1,1},{1,1}};

    // 11 / 38 test cases passed
    // Expected: [1,0]
    N = 5, lamps = {{0,0},{1,0}}, queries = {{1,1},{1,1}};

    // 18 / 38 test cases passed.
    //N = 5, lamps = {{0,0},{0,1},{0,4}}, queries = {{0,0},{0,1},{0,2}};

    // 33 / 38 test cases passed.
    // Expected: [1,0]
    N = 5, lamps = {{0,0},{4,4}}, queries = {{1,1},{1,0}};

    // 34 / 38 test cases passed.
    // Expected: [1,1]
    //N = 5, lamps = {{0,0},{4,4}}, queries = {{1,1},{1,1}};

    //N = 5, lamps = {{0,0},{0,4}}, queries = {{0,4},{0,1},{1,4}};


    //37 / 38 test cases passed.
    // Expected: [1,1,1]
    N = 5, lamps = {{0,0},{4,4}}, queries = {{1,1},{0,0},{2,2}};
    
    auto res = sol.gridIllumination(N, lamps, queries);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}

