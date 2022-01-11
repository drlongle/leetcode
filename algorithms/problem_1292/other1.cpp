/*
The solution has two steps:
1. Compute the prefixSum matrix via dynamic-programming method, where prefixSum[i][j] is the sum of submatrix mat[0...i][0...j]

2. A key observation:mat contains only non-negative elements as the problem statement says.
   2.1. recall the 1d version problem: find longest subarray whose sum is less than thres in a non-negative size N array. We can do a O(N) sliding-window to solve it.
   2,2, apply same idea to all the diagonals of prefixSum (m+n-1 diagonals in total). Elements on the same diagonal forms a non-negative array, and we can do the sliding window algorithm on it. (Actually, diagonal is not a must, you can also do sliding-window on rows or columns)

Time complexity:
compute prefixSum: O(MN)
sliding window on each diagonal: O(sum of length of each diagonal) = O(MN)
Total complexity: O(MN)

Space complexity:
prefixSum: O(MN)
*/

class Solution {
    int squareSum(vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
        return prefixSum[x2][y2] - prefixSum[x1][y2] - prefixSum[x2][y1] + prefixSum[x1][y1];
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // compute prefixSum via dynamic-programming method
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefixSum(m+1, vector<int>(n+1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int res = 0;
        
        for (int i = 0; i < m; i ++) {
            // do sliding-window on the diagonal line of (i, 0), (i+1, 1), ...
            int begin = 0, end = 0;
            int x1, x2, y1, y2;
            while (i+end <= m && end <= n) {
                x1 = i+begin, y1 = begin, x2 = i+end, y2 = end;
                while (begin < end && squareSum(prefixSum, x1, y1, x2, y2) > threshold) {
                    begin ++;
                    x1 = i+begin, y1 = begin;
                }
                res = max(res, end - begin);
                end ++;
            }
        }
        
        for (int i = 1; i < n; i ++) {
            // do sliding-window on the diagonal line of (0, i), (1, i+1), ...
            int begin = 0, end = 0;
            int x1, x2, y1, y2;
            while (end <= m && i+end <= n) {
                x1 = begin, y1 = i+begin, x2 = end, y2 = i+end;
                while (begin < end && squareSum(prefixSum, x1, y1, x2, y2) > threshold) {
                    begin ++;
                    x1 = begin, y1 = i+begin;
                }
                res = max(res, end - begin);
                end ++;
            }
        }
        return res;
    }
};


