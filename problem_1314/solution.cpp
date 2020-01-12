/*
1314. Matrix Block Sum
Medium

Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.
 
Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n, K <= 100
1 <= mat[i][j] <= 100
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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int M = mat.size(), N = mat[0].size();
        vector<vector<int>> res(M, vector<int>(N)), sum(M, vector<int>(N));        
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; ++j) {
                sum[i][j] = mat[i][j];
                sum[i][j] += (i > 0) ? sum[i-1][j] : 0;
                sum[i][j] += (j > 0) ? sum[i][j-1] : 0;
                sum[i][j] -= (i > 0 && j > 0) ? sum[i-1][j-1] : 0;                    
            }
        
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; ++j) {
                int low_x = max(i - K, 0);
                int low_y = max(j - K, 0);
                int high_x = min(i + K, M-1);
                int high_y = min(j + K, N-1);
                res[i][j] = sum[high_x][high_y];
                res[i][j] -= (low_x > 0) ? sum[low_x-1][high_y] : 0;
                res[i][j] -= (low_y > 0) ? sum[high_x][low_y-1] : 0;
                res[i][j] += (low_x > 0 && low_y > 0) ? sum[low_x-1][low_y-1] : 0;                    
            }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat;
    int K;

    // Output: {{12,21,16},{27,45,33},{24,39,28}}
    mat = {{1,2,3},{4,5,6},{7,8,9}}, K = 1;

    // Output: {{45,45,45},{45,45,45},{45,45,45}}
    //mat = {{1,2,3},{4,5,6},{7,8,9}}, K = 2;

    auto res = sol.matrixBlockSum(mat, K);

    for (auto& r: res) {
        copy(begin(r), end(r), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    
    return 0;
}
