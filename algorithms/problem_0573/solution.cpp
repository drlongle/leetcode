/*
573. Squirrel Simulation
Medium

There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid.
Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under
the tree one by one. The squirrel can only take at most one nut at one time and can move in four
directions - up, down, left and right, to the adjacent cell. The distance is represented by
the number of moves.

Example 1:
Input:
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12

Note:
All given positions won't overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.
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
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    int distance(vector<int>& pos1, vector<int>& pos2) {
        return abs(pos1[0] - pos2[0]) + abs(pos1[1] - pos2[1]);
    }
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int res = INT_MAX, sum = 0, n = nuts.size();

        for (int i = 0; i < n; ++i) {
            int d1 = distance(nuts[i], tree);
            sum += d1;
            int d = distance(squirrel, nuts[i]) - d1;
            res = min(res, d);
        }

        return res + 2 * sum;
    }
};

int main() {
    Solution sol;
    int height, width;
    vector<int> tree, squirrel;
    vector<vector<int>> nuts;

    // Output: 12
    height = 5;
    width = 7;
    tree = {2,2};
    squirrel = {4,4};
    nuts ={{3,0},{2,5}};
    cout << sol.minDistance(height, width, tree, squirrel, nuts) << endl;

    // Output: 100
    height = 5, width = 5;
    tree = {3,2};
    squirrel = {0,1};
    nuts = {{2,0},{4,1},{0,4},{1,3},{1,0},{3,4},{3,0},{2,3},{0,2},{0,0},
            {2,2},{4,2},{3,3},{4,4},{4,0},{4,3},{3,1},{2,1},{1,4},{2,4}};
    cout << sol.minDistance(height, width, tree, squirrel, nuts) << endl;

    // Output: 12
    height = 5, width = 5;
    tree = {3,2};
    squirrel = {0,1};
    nuts = {{4,1},{0,4}};
    cout << sol.minDistance(height, width, tree, squirrel, nuts) << endl;

    return 0;
}
