/*
554. Brick Wall
Medium

There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks
have the same height but different width. You want to draw a vertical line from the top to the bottom
and cross the least bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the width
of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need
to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

You cannot draw a line just along one of the two vertical edges of the wall, in which case the line
will obviously cross no bricks.

Example:
Input: [[1,2,2,1],
        [3,1,2],
        [1,3,2],
        [2,4],
        [3,1,2],
        [1,3,1,1]]
Output: 2

Note:
- The width sum of bricks in different rows are the same and won't exceed INT_MAX.
- The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000].
  Total number of bricks of the wall won't exceed 20,000.
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
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (auto& line: wall) {
            int c = 0;
            for (int point: line) {
                c += point;
                ++cnt[c];
            }
            --cnt[c];
        }

        int n = wall.size(), res = n;
        for (auto& [k, v]: cnt) {
            res = min(res, n-v);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> wall;

    // Output: 2
    wall = {{1,2,2,1},
            {3,1,2},
            {1,3,2},
            {2,4},
            {3,1,2},
            {1,3,1,1}};
    cout << sol.leastBricks(wall) << endl;

    return 0;
}
