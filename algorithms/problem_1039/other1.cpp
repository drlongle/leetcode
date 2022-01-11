/*
Intuition: If we pick a side of our polygon, it can form n - 2 triangles. Each such triangle forms 2 sub-polygons. We can analyze n - 2 triangles, and get the minimum score for sub-polygons using the recursion.

Top-Down Solution
* Fix one side of the polygon i, j and move k within (i, j).
* Calculate score of the i, k, j "orange" triangle.
* Add the score of the "green" polygon i, k using recursion.
* Add the score of the "blue" polygon k, j using recursion.
* Use memoisation to remember minimum scores for each sub-polygons.

 */

class Solution {
public:
    int dp[50][50] = {};
    int minScoreTriangulation(vector<int>& A, int i = 0, int j = 0, int res = 0) {
        if (j == 0) j = A.size() - 1;
        if (dp[i][j] != 0) return dp[i][j];
        for (auto k = i + 1; k < j; ++k) {
            res = min(res == 0 ? INT_MAX : res, 
                      minScoreTriangulation(A, i, k) + A[i] * A[k] * A[j] + minScoreTriangulation(A, k, j));
        }
        return dp[i][j] = res;
    }
};


// Bottom down solution
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int dp[50][50] = {};
        for (int i = A.size() - 1; i >= 0; --i)
            for (int j = i + 1; j  < A.size();  ++j)
                for (auto k = i + 1; k < j; ++k)
                    dp[i][j] = min(dp[i][j] == 0 ? INT_MAX : dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
        return dp[0][A.size() - 1];
    }
};
