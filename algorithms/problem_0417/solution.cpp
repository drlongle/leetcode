/*
417. Pacific Atlantic Water Flow

    User Accepted: 235
    User Tried: 366
    Total Accepted: 241
    Total Submissions: 1061
    Difficulty: Medium

Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the
Pacific and Atlantic ocean.

Note:
    The order of returned grid coordinates does not matter.
    Both m and n are less than 150.

Example:
Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]
(positions with parentheses in above matrix).
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:

    int rows;
    int columns;
    queue<pair<int, int>> q;
    vector<vector<int>> visited, res;
    
    void bfs(const vector<vector<int>>& matrix, int mask) {
        const array<array<int, 2>, 4> offsets{1, 0, -1, 0, 0, 1, 0, -1};
        while (!q.empty()) {
            auto& c = q.front();
            int x = c.first;
            int y = c.second;
            if (visited[x][y] != 3 && (visited[x][y] | mask) == 3)
                res.emplace_back(vector<int>{x, y});
            visited[x][y] |= mask;

            for (auto& off: offsets) {
                int new_x = x + off[0];
                int new_y = y + off[1];
                if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < columns
                    && matrix[x][y] <= matrix[new_x][new_y] && (visited[new_x][new_y] & mask) == 0)
                    q.emplace(new_x, new_y);
            }
            q.pop();
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if (rows == 0)
            return res;
        columns = matrix[0].size();
        if (columns == 0)
            return res;
        
        visited.resize(rows, vector<int>(columns, 0));
        for (int j = 0; j < columns; ++j)
            q.emplace(0, j);
        for (int i = 0; i < rows; ++i)
            q.emplace(i, 0);
        bfs(matrix, 1);

        for (int j = 0; j < columns; ++j)
            q.emplace(rows-1, j);
        for (int i = 0; i < rows; ++i)
            q.emplace(i, columns-1);
        bfs(matrix, 2);
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix;

    matrix = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    auto res = sol.pacificAtlantic(matrix);

    for (auto& p: res) {
        copy(begin(p), end(p), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    
    return 0;
}

