/*
361. Bomb Enemy
Medium

Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return
the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it
hits the wall since it is too strong to be destroyed.

Example 1:
Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3

Example 2:
Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
Output: 1

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 'W', 'E', or '0'.
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
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] != '0')
                    continue;
                int t = 0;
                for(int k = j - 1; k >= 0 && grid[i][k] != 'W'; --k)
                    t += (grid[i][k] == 'E');
                for (int k = j+1; k < n && grid[i][k] != 'W'; ++k)
                    t += (grid[i][k] == 'E');
                for (int k = i - 1; k >= 0 && grid[k][j] != 'W'; --k)
                    t += (grid[k][j] =='E');
                for (int k = i + 1; k < m && grid[k][j] != 'W'; ++k)
                    t += (grid[k][j] == 'E');
                res = max(res, t);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
