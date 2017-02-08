/*
289. Game of Life

    Total Accepted: 28533
    Total Submissions: 79807
    Difficulty: Medium

According to the Wikipedia's article: "The Game of Life, also known simply as
Life, is a cellular automaton devised by the British mathematician John Horton
Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or
dead (0). Each cell interacts with its eight neighbors (horizontal, vertical,
diagonal) using the following four rules (taken from the above Wikipedia article):

 Any live cell with fewer than two live neighbors dies, as if caused by under-population.
 Any live cell with two or three live neighbors lives on to the next generation.
 Any live cell with more than three live neighbors dies, as if by over-population..
 Any dead cell with exactly three live neighbors becomes a live cell, as if by
 reproduction.

Write a function to compute the next state (after one update) of the board given
its current state.

Follow up:
 Could you solve it in-place? Remember that the board needs to be updated at the
 same time: You cannot update some cells first and then use their updated values
 to update other cells. In this question, we represent the board using a 2D array.
 In principle, the board is infinite, which would cause problems when the active
 area encroaches the border of the array. How would you address these problems?
*/

import java.io.*;
import java.util.*;

/*
 * Input:
 *   0 -> dead
 *   1 -> live
 *   
 * Intermediate state:
 *   (past dead, current dead) : 8
 *   (past dead, current live) : 9
 *   (past live, current dead) : 16
 *   (past live, current live) : 17
 *   
 *   To check past dead: board[i][j] & 0b0100
 *   To check past live: board[i][j] & 0b1000
 *   To check current live: board[i][j] & 0b1
 */

public class Solution {

    public void gameOfLife(int[][] board)
    {
	int rows = board.length;
	if (rows == 0)
	    return;
	int columns = board[0].length;
	for (int i = 0; i < rows; ++i)
	{
            boolean canGoDown = i > 0;
            boolean canGoUp = i < rows-1;
	    int liveNeighs = 0;
	    for (int j = 0; j < columns; ++j)
	    {
		if (j == 0)
		{
		    if (canGoDown && ((board[i-1][j] & 16) != 0))
                        ++liveNeighs;
		    if (canGoUp && (board[i+1][j] == 1))
                        ++liveNeighs;
		}
		else
		{
		    if ((board[i][j-1] & 16) != 0) ++liveNeighs;
		    if (board[i][j] != 0) --liveNeighs;
		    if (j >= 2)
		    {
			if ((board[i][j-2] & 16) != 0) --liveNeighs;
			if (canGoDown && ((board[i-1][j-2] & 16) != 0))
                            --liveNeighs;
			if (canGoUp && (board[i+1][j-2] != 0))
                            --liveNeighs;
		    }
		}

		if (j < columns-1)
		{
		    if (board[i][j+1] > 0) ++liveNeighs;
		    if (canGoDown && ((board[i-1][j+1] & 16) != 0))
                        ++liveNeighs;
		    if (canGoUp && (board[i+1][j+1] > 0))
                        ++liveNeighs;
		}

		if (board[i][j] > 0)
		{
		    if (liveNeighs < 2 || liveNeighs > 3)
			board[i][j] = 16;
		    else
			board[i][j] = 17;
		}
		else if (liveNeighs == 3)
		  board[i][j] = 9;
	    }
	}

        for (int i = 0; i < board.length; ++i)
            for (int j = 0; j < board[i].length; ++j)
  	        board[i][j] = ((board[i][j] & 1) != 0) ? 1 : 0;

    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] board;
        board = new int[][] {{1,0,0},{0,1,1},{1,0,1}};

        for (int i = 0; i < board.length; ++i)
        {
            for (int j = 0; j < board[i].length; ++j)
        	System.out.print(board[i][j] + " ");
            System.out.println();
        }

        System.out.println("\n--------------");
        sol.gameOfLife(board);

        System.out.println("\n\nResult:");
        for (int i = 0; i < board.length; ++i)
        {
            for (int j = 0; j < board[i].length; ++j)
        	System.out.print(board[i][j] + " ");
            System.out.println();
        }
    }
}

