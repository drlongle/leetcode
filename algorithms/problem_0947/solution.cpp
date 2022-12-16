/*
947. Most Stones Removed with Same Row or Column
Medium

On a 2D plane, we place n stones at some integer coordinate points. Each
coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as
another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the
location of the ith stone, return the largest possible number of stones that can
be removed.

Example 1:
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another
stone still on the plane.

Example 2:
Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column
with another stone still on the plane.

Example 3:
Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.

Constraints:
1 <= stones.length <= 1000
0 <= xi, yi <= 10^4
No two stones are at the same coordinate point
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
    void dfs(vector<vector<int>> &stones, vector<bool> &visited, int id) {
        visited[id] = true;
        for (int i = 0, n = stones.size(); i < n; ++i) {
            if (!visited[i] && (stones[i][0] == stones[id][0] ||
                                stones[i][1] == stones[id][1])) {
                dfs(stones, visited, i);
            }
        }
    }

    int removeStones(vector<vector<int>> &stones) {
        int connected_components = 0, n = stones.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++connected_components;
                dfs(stones, visited, i);
            }
        }

        return n - connected_components;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> stones;

    // Expected: 5
    stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << sol.removeStones(stones) << endl;

    // Expected: 3
    stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    cout << sol.removeStones(stones) << endl;

    // Expected: 5
    stones = {{0, 1}, {1, 2}, {1, 3}, {3, 3}, {2, 3}, {0, 2}};
    cout << sol.removeStones(stones) << endl;

    // Expected: 19
    stones = {{5, 9}, {9, 0}, {0, 0}, {7, 0}, {4, 3}, {8, 5}, {5, 8},
              {1, 1}, {0, 6}, {7, 5}, {1, 6}, {1, 9}, {9, 4}, {2, 8},
              {1, 3}, {4, 2}, {2, 5}, {4, 1}, {0, 2}, {6, 5}};
    cout << sol.removeStones(stones) << endl;

    // Expected: 8
    stones = {{0, 0}, {7, 0}, {1, 1}, {0, 6}, {7, 5},
              {1, 6}, {1, 3}, {2, 5}, {6, 5}};
    cout << sol.removeStones(stones) << endl;

    // Expected: 196
    stones = {
        {42, 6},  {45, 45}, {16, 29}, {80, 40}, {43, 3},  {39, 83}, {18, 19},
        {77, 80}, {65, 39}, {21, 6},  {80, 78}, {1, 11},  {80, 12}, {26, 70},
        {98, 9},  {54, 13}, {53, 40}, {85, 3},  {75, 32}, {20, 9},  {37, 85},
        {48, 14}, {31, 65}, {9, 57},  {58, 47}, {29, 92}, {58, 20}, {38, 38},
        {71, 12}, {27, 50}, {17, 62}, {89, 89}, {51, 32}, {10, 85}, {19, 45},
        {66, 88}, {31, 21}, {5, 34},  {33, 34}, {70, 7},  {93, 93}, {19, 23},
        {49, 10}, {12, 39}, {92, 35}, {82, 71}, {69, 47}, {60, 65}, {70, 82},
        {59, 36}, {76, 87}, {3, 71},  {98, 36}, {26, 24}, {97, 86}, {51, 16},
        {92, 10}, {39, 88}, {82, 77}, {30, 51}, {28, 68}, {75, 88}, {97, 13},
        {91, 22}, {30, 70}, {11, 10}, {77, 23}, {33, 54}, {43, 78}, {2, 85},
        {66, 18}, {41, 22}, {72, 74}, {98, 65}, {8, 51},  {47, 72}, {96, 60},
        {71, 8},  {10, 66}, {40, 67}, {12, 52}, {9, 91},  {35, 86}, {39, 3},
        {90, 64}, {83, 58}, {24, 90}, {54, 16}, {22, 83}, {58, 43}, {53, 49},
        {59, 34}, {22, 0},  {89, 30}, {28, 94}, {3, 22},  {53, 61}, {56, 46},
        {72, 51}, {7, 74},  {67, 93}, {56, 33}, {55, 59}, {20, 15}, {20, 68},
        {75, 70}, {78, 28}, {97, 76}, {4, 8},   {55, 33}, {62, 61}, {19, 37},
        {21, 89}, {68, 53}, {96, 66}, {18, 1},  {42, 15}, {4, 60},  {4, 90},
        {81, 61}, {2, 75},  {0, 50},  {41, 60}, {14, 38}, {45, 17}, {29, 3},
        {59, 2},  {40, 5},  {40, 90}, {28, 56}, {75, 39}, {99, 34}, {16, 73},
        {43, 67}, {14, 97}, {28, 90}, {70, 22}, {67, 66}, {85, 76}, {82, 1},
        {63, 33}, {4, 29},  {75, 47}, {11, 69}, {45, 46}, {59, 79}, {24, 91},
        {55, 55}, {91, 10}, {73, 94}, {36, 86}, {94, 5},  {1, 7},   {27, 18},
        {76, 3},  {54, 20}, {83, 36}, {69, 39}, {25, 80}, {47, 42}, {71, 36},
        {21, 16}, {88, 97}, {92, 76}, {99, 79}, {15, 54}, {70, 71}, {84, 24},
        {64, 19}, {72, 44}, {19, 36}, {68, 59}, {47, 60}, {19, 98}, {77, 93},
        {82, 18}, {31, 1},  {24, 85}, {80, 49}, {15, 56}, {84, 34}, {24, 48},
        {3, 75},  {87, 98}, {16, 59}, {48, 96}, {45, 29}, {50, 31}, {50, 35},
        {37, 66}, {47, 44}, {79, 27}, {65, 55}, {86, 76}, {10, 45}, {43, 9},
        {33, 46}, {15, 6},  {37, 61}, {3, 29},  {77, 62}, {12, 54}};
    cout << sol.removeStones(stones) << endl;

    // Expected: 31
    stones = {{42, 6},  {59, 36}, {76, 87}, {30, 51}, {28, 68}, {41, 22},
              {72, 74}, {98, 65}, {71, 8},  {90, 64}, {22, 83}, {59, 34},
              {22, 0},  {89, 30}, {28, 94}, {3, 22},  {53, 61}, {20, 15},
              {4, 8},   {55, 33}, {96, 66}, {18, 1},  {42, 15}, {4, 60},
              {41, 60}, {14, 38}, {45, 17}, {40, 90}, {28, 56}, {75, 39},
              {99, 34}, {16, 73}, {43, 67}, {4, 29},  {45, 46}, {59, 79},
              {73, 94}, {36, 86}, {94, 5},  {47, 42}, {71, 36}, {21, 16},
              {88, 97}, {92, 76}, {99, 79}, {15, 54}, {3, 75},  {87, 98},
              {16, 59}, {37, 66}, {47, 44}, {79, 27}, {65, 55}, {86, 76},
              {10, 45}, {43, 9},  {33, 46}, {15, 6},  {37, 61}, {3, 29}};
    cout << sol.removeStones(stones) << endl;

    // Expected: 19
    stones = {{42, 6},  {59, 36}, {76, 87}, {41, 22}, {71, 8},  {90, 64},
              {22, 83}, {59, 34}, {28, 94}, {3, 22},  {53, 61}, {20, 15},
              {4, 8},   {4, 60},  {41, 60}, {14, 38}, {45, 17}, {99, 34},
              {16, 73}, {43, 67}, {4, 29},  {45, 46}, {59, 79}, {73, 94},
              {47, 42}, {71, 36}, {92, 76}, {99, 79}, {16, 59}, {65, 55},
              {86, 76}, {10, 45}, {43, 9},  {37, 61}, {3, 29}};
    cout << sol.removeStones(stones) << endl;

    // Expected: 13
    stones = {{59, 36}, {41, 22}, {71, 8},  {59, 34}, {3, 22},
              {4, 8},   {4, 60},  {41, 60}, {99, 34}, {4, 29},
              {59, 79}, {71, 36}, {99, 79}, {3, 29}};
    cout << sol.removeStones(stones) << endl;

    // Expected: 26
    stones = {{10, 45}, {10, 66}, {10, 85}, {15, 6},  {15, 54}, {19, 36},
              {19, 45}, {21, 6},  {21, 16}, {31, 1},  {31, 65}, {33, 46},
              {33, 54}, {37, 66}, {37, 85}, {45, 45}, {45, 46}, {51, 16},
              {51, 32}, {66, 18}, {66, 88}, {75, 32}, {75, 88}, {82, 1},
              {82, 18}, {98, 36}, {98, 65}};
    cout << sol.removeStones(stones) << endl;

    return 0;
}
