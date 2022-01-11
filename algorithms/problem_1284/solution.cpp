/*
1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
Hard

Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbours
of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighboors if they share
one edge.

Binary matrix is a matrix with all cells equal to 0 or 1 only.
Zero matrix is a matrix with all cells equal to 0.

Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.

Example 1:
Input: mat = [[0,0],[0,1]]
Output: 3
Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.

Example 2:
Input: mat = [[0]]
Output: 0
Explanation: Given matrix is a zero matrix. We don't need to change it.

Example 3:
Input: mat = [[1,1,1],[1,0,1],[0,0,0]]
Output: 6

Example 4:
Input: mat = [[1,0,0],[1,0,0]]
Output: -1
Explanation: Given matrix can't be a zero matrix

Constraints:
m == mat.length
n == mat[0].length
1 <= m <= 3
1 <= n <= 3
mat[i][j] is 0 or 1.
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
    struct Move {
        int i, j, steps;
        vector<vector<int>> mat;
    };

    bool is_zero(vector<vector<int>>& mat) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; ++j)
                if (mat[i][j])
                    return false;
        return true;
    }

    int M;
    int N;

    void flip(vector<vector<int>>& mat, pair<int, int>& pos) {
        vector<vector<int>> offsets{{0,0},{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& offset: offsets) {
            int i = pos.first + offset[0];
            int j = pos.second + offset[1];
            if (i >= 0 && i < M && j >= 0 && j < N)
                mat[i][j] = !mat[i][j];
        }
    }
    
    int calc(vector<vector<int>> mat, pair<int, int>& pos, int step, set<pair<int,int>>& visited) {
        //queue<Move> q;
        visited.emplace(pos);
        flip(mat, pos);
        ++step;
        if (is_zero(mat))
            return step;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; ++j) {
                pair<int, int> newpos = {i, j};
                if (visited.count(newpos) == 0 && mat[i][j]) {
                    int temp = calc(mat, newpos, step, visited);
                    if (temp > 0)
                        return temp;
                }
            }
        visited.erase(pos);
        return -1;
    }
        
    int minFlips(vector<vector<int>>& mat) {
        M = mat.size();
        N = mat[0].size();
        if (is_zero(mat))
            return 0;
        int res = -1;
        set<pair<int,int>> visited;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; ++j) {
                pair<int, int> pos{i, j};
                auto r = calc(mat, pos, 0, visited);
                if (r > 0)
                    res = (res < 0) ? r : min(res, r);
            }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat;
    
    // Output: 3
    mat = {{0,0},{0,1}};

    // Output: 0
    mat = {{0}};

    // Output: 6
    mat = {{1,1,1},{1,0,1},{0,0,0}};

    // Output: -1
    //mat = {{1,0,0},{1,0,0}};

    cout << "Result: " << sol.minFlips(mat) << endl;
    
    return 0;
}
