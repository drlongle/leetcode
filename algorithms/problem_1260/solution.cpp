/*
1260. Shift 2D Grid
Easy

Given a 2D grid of size n * m and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] becomes at grid[i][j + 1].
Element at grid[i][m - 1] becomes at grid[i + 1][0].
Element at grid[n - 1][m - 1] becomes at grid[0][0].
Return the 2D grid after applying shift operation k times.

Example 1:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[9,1,2],[3,4,5],[6,7,8]]

Example 2:
Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

Example 3:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
Output: [[1,2,3],[4,5,6],[7,8,9]]
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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> arr;
        for (auto& v: grid) {
            copy(begin(v), end(v), back_inserter(arr));
        }
        k %= arr.size();
        reverse(begin(arr), end(arr));
        reverse(begin(arr), begin(arr)+k);
        reverse(begin(arr)+k, end(arr));

        vector<vector<int>> res;
        int m = grid.size();
        int n = grid[0].size();
        auto start = begin(arr);
        for (int i = 0; i < m; ++i) {
            res.emplace_back();
            copy(start, start + n, back_inserter(res.back()));
            start += n;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;
    int k;

    // Output: {{9,1,2},{3,4,5},{6,7,8}}
    grid = {{1,2,3},{4,5,6},{7,8,9}}, k = 1;

    // Output: {{12,0,21,13},{3,8,1,9},{19,7,2,5},{4,6,11,10}}
    //grid = {{3,8,1,9},{19,7,2,5},{4,6,11,10},{12,0,21,13}}, k = 4;

    // Output: {{1,2,3},{4,5,6},{7,8,9}}
    //grid = {{1,2,3},{4,5,6},{7,8,9}}, k = 9;
    
    //grid = {{1}}, k = 100;
    
    auto res = sol.shiftGrid(grid, k);
    for (auto& r: res) {
        copy(begin(r), end(r), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    
    return 0;
}
