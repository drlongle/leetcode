/*
363. Max Sum of Rectangle No Larger Than K
Difficulty: Hard

Given a non-empty 2D matrix matrix and an integer k, find the max sum
of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.

Example:
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2 
Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
             and 2 is the max number no larger than k (k = 2).
Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
 */

#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int M = matrix.size();
        int N = matrix[0].size();        
        vector<vector<int>> sum = matrix;

        for (int i = 0; i < M; ++i)
            for (int j = 1; j < N; ++j)
                sum[i][j] += sum[i][j-1];
        for (int i = 1; i < M; ++i)
            for (int j = 0; j < N; ++j)
                sum[i][j] += sum[i-1][j];
        
        int result = numeric_limits<int>::min();
        int temp;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; ++j)
                for (int m = i; m < M; ++m)
                    for (int n = j; n < N; ++n) {
                        if (m == i && n == j)
                            continue;
                        if (i == m || n == j)
                            temp = sum[m][n] - sum[i][j];
                        else temp = sum[m][n] + sum[i][j]
                            - sum[m][j] - sum[i][n];
                        if (temp > result && temp <= k)
                            result = temp;
                    }
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; ++j) {
                temp = sum[i][j];
                if (temp > result && temp <= k)
                    result = temp;
            }
        return result;
    }
};

int main(int argc, char** argv) {
    Solution sol;
    vector<vector<int>> matrix;
    int k;
    
    matrix = {{1,0,1},{0,-2,3}}, k = 2;
    matrix = {{2,2,-1}}, k = 3;
    matrix = {{5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}}, k = 8;
    
    cout << "Result " << sol.maxSumSubmatrix(matrix, k) << endl;
    return 0;
}
