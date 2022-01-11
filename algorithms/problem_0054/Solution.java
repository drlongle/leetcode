/*
54. Spiral Matrix
Total Accepted: 63999 Total Submissions: 277307 Difficulty: Medium

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].
*/

import java.io.*;
import java.util.*;

public class Solution {

    public List<Integer> spiralOrder(int[][] matrix)
    {
        List<Integer> res = new ArrayList<Integer>();
        int m = matrix.length;
        if (m == 0) return res;
        int n = matrix[0].length;
        if (n == 0) return res;

        for (int i = 0; i < m/2; ++i)
        {
            for (int j = i; j < n-i; ++j)
                res.add(matrix[i][j]);

            for (int j = i+1; j < m-1-i && 2*i <= n-1; ++j)
                res.add(matrix[j][n-1-i]);

            for (int j = n-1-i; j >= i; --j)
                res.add(matrix[m-1-i][j]);

            for (int j = m-2-i; j > i && 2*i < n-1; --j)
                res.add(matrix[j][i]);
        }

        if ((m & 1) != 0)
        {
            int i = m >> 1;
            for (int j = i; j < n-i; ++j)
                res.add(matrix[i][j]);
        }

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        List<Integer> res;
        int[][] matrix;

        matrix = new int[][] {{2,5,8},{4,0,-1}};

        res = sol.spiralOrder(matrix);
        for (int i = 0; i < res.size(); ++i)
            System.out.println(res.get(i));
    }
}

