/*
48. Rotate Image

    Total Accepted: 81238
    Total Submissions: 224456
    Difficulty: Medium

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?
*/

import java.io.*;
import java.util.*;

public class Solution {
    public void rotate(int[][] matrix)
    {
	int size = matrix[0].length;
	if (size == 0) return;

	for (int i = 0; i < size/2; ++i)
	{
	    for (int j = i; j < size-i-1; ++j)
	    {
		int topleft = matrix[i][j];
		matrix[i][j] = matrix[size-1-j][i];
		matrix[size-1-j][i] = matrix[size-1-i][size-1-j];
		matrix[size-1-i][size-1-j] = matrix[j][size-1-i];
		matrix[j][size-1-i] = topleft;
	    }
	}
    }

    public static void main(String[] args)
    {
        Solution sol = new Solution();
        int[][] matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{14,14,15,16}};
        sol.rotate(matrix);
        for (int i = 0; i < matrix.length; ++i)
        {
            for (int j = 0; j < matrix[0].length; ++j)
    	         System.out.print(matrix[i][j] + " ");
            System.out.println("");
        }
    }
}
