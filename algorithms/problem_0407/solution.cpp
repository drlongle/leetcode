/*
407. Trapping Rain Water II
Hard

Given an m x n matrix of positive integers representing the height of each unit cell
in a 2D elevation map, compute the volume of water it is able to trap after raining.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

struct Pos {
    Pos(int i, int j, int height) : m_i(i), m_j(j), m_height(height) {}
    bool operator<(const Pos& other) const {
        return m_height > other.m_height;
    }
    int m_i, m_j, m_height;
};

struct Direction {
    int r;
    int c;
};

array<Direction, 4> offsets{{ {0, 1}, {0,-1}, {1,0}, {-1,0} }};

class Solution {
public:

    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        if (!rows) return 0;
        int columns = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));

        priority_queue<Pos> q;

        for (int i = 0; i < rows; ++i) {
            q.emplace(i, 0, heightMap[i][0]);
            visited[i][0] = true;
            q.emplace(i, columns-1, heightMap[i][columns-1]);
            visited[i][columns-1] = true;
        }
        for (int j = 1; j < columns-1; ++j) {
            q.emplace(0, j, heightMap[0][j]);
            visited[0][j] = true;
            q.emplace(rows-1, j, heightMap[rows-1][j]);
            visited[rows-1][j] = true;
        }

        int res = 0;
        while (!q.empty()) {
            const Pos p = q.top();
            res += p.m_height - heightMap[p.m_i][p.m_j];
            for (auto& off: offsets) {
                int ni = p.m_i + off.r;
                int nj = p.m_j + off.c;
                if (ni >= 0 && ni < rows && nj >= 0 && nj < columns && !visited[ni][nj]) {
                    q.emplace(ni, nj, max(p.m_height, heightMap[ni][nj]));
                    visited[ni][nj] = true;
                }
            }
            q.pop();
        }


        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> height;

    // Expected: 4
    height = {{1,4,3,1,3,2}, {3,2,1,3,2,4}, {2,3,3,2,3,1}};

    // 17 / 40 test cases passed.
    // Expected: 14
    height = {{12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};


    //height = {{18,2,3},{4,5,6},{7,8,9}};

    // 21 / 40 test cases passed.
    // Expected: 5
    //height = {{3,3,4,4,4,2},{3,1,3,2,1,4},{7,3,1,6,4,1}};

    // 23 / 40 test cases passed.
    // Expected: 215
    //height = {{9,9,9,9,9,9,8,9,9,9,9},{9,0,0,0,0,0,1,0,0,0,9},{9,0,0,0,0,0,0,0,0,0,9},{9,0,0,0,0,0,0,0,0,0,9},{9,9,9,9,9,9,9,9,9,9,9}};

    // 23 / 40 test cases passed.
    // Expected: 44
    height = {{78,16,94,36},{87,93,50,22},{63,28,91,60},{64,27,41,27},{73,37,12,69},{68,30,83,31},{63,24,68,36}};

    cout << "Result: " << sol.trapRainWater(height) << endl;

    return 0;
}

