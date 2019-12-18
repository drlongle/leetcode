/*
1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
Medium

Given a m x n matrix mat and an integer threshold. Return the maximum side-length of a
square with a sum less than or equal to threshold or return 0 if there is no such square.

Example 1:
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

Example 2:
Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
Output: 0

Example 3:
Input: mat = [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]], threshold = 6
Output: 3

Example 4:
Input: mat = [[18,70],[61,1],[25,85],[14,40],[11,96],[97,96],[63,45]], threshold = 40184
Output: 2

Constraints:
1 <= m, n <= 300
m == mat.length
n == mat[i].length
0 <= mat[i][j] <= 10000
0 <= threshold <= 10^5
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

    vector<vector<int>> check(vector<vector<int>>& cands, int sz, int threshold) {
        vector<vector<int>> new_cands;
        for (auto& cand: cands) {
            int low_x = cand[0], low_y = cand[1];
            int high_x = cand[0] + sz - 1, high_y = cand[1] + sz -1;
            if (high_x < m && high_y < n) {
                int s = sum[high_x][high_y] + (low_x > 0 && low_y > 0 ? sum[low_x-1][low_y-1] : 0);
                if (low_x > 0)
                    s -= sum[low_x-1][high_y];
                if (low_y > 0)
                    s -= sum[high_x][low_y-1];
                if (s <= threshold)
                    new_cands.emplace_back(cand);
            }
        }
        return new_cands;
    }
    
    vector<vector<int>> sum;
    int m;
    int n;
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size(), n = mat[0].size();
        sum.resize(m, vector<int>(n));
        vector<vector<int>> cands;
        
        for (int i = 0; i < m; ++i) {
            int running = 0;
            for (int j = 0; j < n; ++j) {
                running += mat[i][j];
                sum[i][j] = (i > 0 ? sum[i-1][j] : 0) + running;
                if (mat[i][j] <= threshold) {
                    cands.emplace_back(vector<int>{i,j});
                }
            }
        }
        if (cands.empty())
            return 0;
        int low = 1, high = min(m, n), res = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            auto new_cands = check(cands, mid, threshold);
            if (new_cands.empty())
                high = mid -1;
            else {
                res = mid;
                cands = new_cands;
                low = mid+1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat;
    int threshold;
    
    // Output: 2
    mat = {{1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}}, threshold = 4;

    // Output: 0
    mat = {{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2},{2,2,2,2,2}}, threshold = 1;

    // Output: 3
    mat = {{1,1,1,1},{1,0,0,0},{1,0,0,0},{1,0,0,0}}, threshold = 6;

    // Output: 2
    mat = {{18,70},{61,1},{25,85},{14,40},{11,96},{97,96},{63,45}}, threshold = 40184;
    
    cout << "Result: " << sol.maxSideLength(mat, threshold) << endl;
    
    return 0;
}
