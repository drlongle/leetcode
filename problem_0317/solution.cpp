/*
317. Shortest Distance from All Buildings
Hard

You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according
to the above rules, return -1.
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> scores;
    int m, n;
    int *visited;
    void BFS(vector<vector<int>>& grid, int i, int j) {
        queue<tuple<int, int, int>> q;
        q.emplace(i, j, 0);
        visited[i*n + j] = 1;
        bzero(visited, m*n*sizeof(int));
        vector<vector<int>> offsets{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (q.size()) {
            auto[x, y, score] = q.front();
            q.pop();

            scores[x][y].push_back(score);
            for (auto& offset: offsets) {
                int nx = x + offset[0], ny = y + offset[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0 && visited[nx*n + ny] == 0) {
                    visited[nx*n + ny] = 1;
                    q.emplace(nx, ny, score+1);
                }
            }
        }
    }

    int shortestDistance(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        scores.resize(m, vector<vector<int>>(n));
        visited = (int*) malloc(m*n*sizeof(int));
        size_t houses = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    BFS(grid, i, j);
                    ++houses;
                }
            }
        }

        int res = numeric_limits<int>::max();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                auto& arr = scores[i][j];
                if (grid[i][j] == 0 && arr.size() == houses) {
                    res = min(res, accumulate(begin(arr), end(arr), 0));
                }
            }
        }
        free(visited);

        return res == numeric_limits<int>::max() ? -1 : res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    grid = {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    cout << sol.shortestDistance(grid) << endl;

    return 0;
}
