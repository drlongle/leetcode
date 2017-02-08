/*
73. Set Matrix Zeroes

    Total Accepted: 78279
    Total Submissions: 226608
    Difficulty: Medium

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

import java.io.*;
import java.util.*;

public class Solution {

    public void setZeroes(int[][] matrix)
    {
        int rows = matrix.length;
        if (rows == 0) return;
        int columns = matrix[0].length;
        boolean firstRowHasZero = false;
        boolean firstColumnHasZero = false;

        for (int i = 0; i < columns && !firstRowHasZero; ++i)
            if (matrix[0][i] == 0)
         	firstRowHasZero = true;

        for (int i = 0; i < rows && !firstColumnHasZero; ++i)
            if (matrix[i][0] == 0)
        	firstColumnHasZero = true;

        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < columns; ++j)
            {
         	if (matrix[i][j] == 0)
    	        {
         	    matrix[0][j] = 0;
    	            matrix[i][0] = 0;
    	        }
            }
        }
	  
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < columns; ++j)
            {
        	if (matrix[0][j] == 0 || matrix[i][0] == 0)
    	            matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < columns && firstRowHasZero; ++i)
            matrix[0][i] = 0;
        for (int i = 0; i < rows && firstColumnHasZero; ++i)
            matrix[i][0] = 0;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] matrix = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};
        sol.setZeroes(matrix);
        for (int i = 0; i < matrix.length; ++i)
        {
            for (int j = 0; j < matrix[0].length; ++j)
         	System.out.print(matrix[i][j] + " ");
            System.out.println("");
        }
    }
}

