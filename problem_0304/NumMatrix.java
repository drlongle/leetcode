/*
304. Range Sum Query 2D - Immutable

    Total Accepted: 22069
    Total Submissions: 97379
    Difficulty: Medium
    Contributors: Admin

Given a 2D matrix matrix, find the sum of the elements inside the rectangle
defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1)
and (row2, col2) = (4, 3), which contains sum = 8.

Example:

Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

Note:

    You may assume that the matrix does not change.
    There are many calls to sumRegion function.
    You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

import java.io.*;
import java.util.*;

public class NumMatrix {

    public NumMatrix(int[][] matrix) {
        int rows = matrix.length;
        int columns = (rows > 0) ? matrix[0].length : 0;
        prefix = new int[rows][columns];
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < columns; ++c)
                prefix[r][c] = matrix[r][c]
                    + ((c > 0) ? prefix[r][c-1] : 0);
        }
        
        for (int r = 1; r < rows; ++r)
        {
            for (int c = 0; c < columns; ++c)
                prefix[r][c] += prefix[r-1][c];
        }
    }

    private int[][] prefix;

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int res = prefix[row2][col2];
        if (row1 > 0 && col1 > 0)
            res += prefix[row1-1][col1-1];
        if (row1 > 0)
            res -= prefix[row1-1][col2];
        if (col1 > 0)
            res -= prefix[row2][col1-1];
        return res;
    }
}
