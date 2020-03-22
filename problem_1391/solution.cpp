/*
1391. Check if There is a Valid Path in a Grid
Medium

Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.

You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

Example 1:
Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).

Example 2:
Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)

Example 3:
Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).

Example 4:
Input: grid = [[1,1,1,1,1,1,3]]
Output: true

Example 5:
Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
Output: true

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    static constexpr int bs_size = 301;
    using BS = bitset<bs_size>;
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return true;
        vector<BS> visited(m);
        pair<int, int> prev{-1, -1}, curr{0, 0}, src{0, 0}, dest{m-1, n-1};
        while (true) {
            auto& [i, j] = curr;
            if (i < 0 || i >= m || j < 0 || j >= n || visited[i].test(j))
                return false;
            visited[i].set(j);
            int val = grid[i][j];
            if (curr == src) {
                prev = curr;
                switch (val) {
                    case 1:
                    case 6:
                        ++curr.second;
                        break;
                    case 2:
                    case 3:
                    case 4:
                        ++curr.first;
                        break;
                    case 5:
                        return false;
                }
            } else {
                pair<int, int> next;
                int diff_x = curr.first - prev.first;
                int diff_y = curr.second - prev.second;
                switch (val) {
                    case 1:
                        next.first = curr.first;
                        if (diff_y > 0)
                            next.second = curr.second + 1;
                        else if (diff_y < 0)
                            next.second = curr.second - 1;
                        else
                            return false;
                        break;
                    case 2:
                        next.second = curr.second;
                        if (diff_x > 0)
                            next.first = curr.first + 1;
                        else if (diff_x < 0)
                            next.first = curr.first - 1;
                        else
                            return false;
                        break;
                    case 3:
                        if (diff_x < 0) {
                            next = {curr.first, curr.second - 1};
                        } else if (diff_y > 0) {
                            next = {curr.first + 1,  curr.second};
                        } else
                            return false;
                        break;
                    case 4:
                        if (diff_x < 0) {
                            next = {curr.first, curr.second + 1};
                        } else if (diff_y < 0) {
                            next = {curr.first + 1, curr.second};
                        } else
                            return false;
                        break;
                    case 5:
                        if (diff_x > 0) {
                            next = {curr.first, curr.second - 1};
                        } else if (diff_y > 0) {
                            next = {curr.first - 1, curr.second};
                        } else
                            return false;
                        break;
                    case 6:
                        if (diff_x > 0) {
                            next = {curr.first, curr.second + 1};
                        } else if (diff_y < 0) {
                            next = {curr.first - 1, curr.second};
                        } else
                            return false;
                        break;
                }
                if (curr == dest)
                    return true;
                prev = curr;
                curr = next;
            }
        }
    }
    

};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    // Output: true
    grid = {{2,4,3},{6,5,2}};
    cout << boolalpha << sol.hasValidPath(grid) << endl;
    
    // Output: false
    grid = {{1,2,1},{1,2,1}};
    cout << boolalpha << sol.hasValidPath(grid) << endl;
    
    // Output: false
    grid = {{1,1,2}};
    cout << boolalpha << sol.hasValidPath(grid) << endl;
    
    // Output: true
    grid = {{1,1,1,1,1,1,3}};
    cout << boolalpha << sol.hasValidPath(grid) << endl;
    
    // Output: true
    grid = {{2},{2},{2},{2},{2},{2},{6}};
    cout << boolalpha << sol.hasValidPath(grid) << endl;

    // Output: true
    grid = {{1}};
    cout << boolalpha << sol.hasValidPath(grid) << endl;

    // Output: true
    grid = {{3,4,3,4},{2,2,2,2},{6,5,6,5}};
    cout << boolalpha << sol.hasValidPath(grid) << endl;
    
    return 0;
}
