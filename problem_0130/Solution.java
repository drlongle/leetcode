/*
130. Surrounded Regions

    Total Accepted: 59763
    Total Submissions: 358472
    Difficulty: Medium

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
*/

import java.io.*;
import java.util.*;

public class Solution {
    public class Cell {
        Cell(int i, int j) {
            this.i = i;
            this.j = j;
        }
        int i, j;
    }

    public void solve(char[][] board)
    {
        int rows = board.length;
        if (rows == 0) return;
        int columns = board[0].length;
        if (columns == 0) return;

        Queue<Cell> cells = new ArrayDeque<>();

        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = 'o';
                cells.offer(new Cell(i,0));
            }
            if (board[i][columns-1] == 'O') {
                board[i][columns-1] = 'o';
                cells.offer(new Cell(i,columns-1));
            }
        }

        for (int j = 0; j < columns; ++j) {
            if (board[0][j] == 'O') {
                board[0][j] = 'o';
                cells.offer(new Cell(0,j));
            }
            if (board[rows-1][j] == 'O') {
                board[rows-1][j] = 'o';
                cells.offer(new Cell(rows-1,j));
            }
        }

        while (!cells.isEmpty()) {
            Cell cell = cells.poll();
            int i = cell.i;
            int j = cell.j;
            if (i - 1 >= 0 && board[i-1][j] == 'O') {
                board[i-1][j] = 'o';
                cells.offer(new Cell(i-1,j));
            }
            if (i + 1 < rows && board[i+1][j] == 'O') {
                board[i+1][j] = 'o';
                cells.offer(new Cell(i+1,j));
            }
            if (j - 1 >= 0 && board[i][j-1] == 'O') {
                board[i][j-1] = 'o';
                cells.offer(new Cell(i,j-1));
            }
            if (j + 1 < columns && board[i][j+1] == 'O') {
                board[i][j+1] = 'o';
                cells.offer(new Cell(i,j+1));
            }
        }

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'o')
                    board[i][j] = 'O';
            }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        char[][] board = new char[][] {
            "XXXX".toCharArray(),
            "XOOX".toCharArray(),
            "XXOX".toCharArray(),
            "XOXX".toCharArray()
        };

        sol.solve(board);
        for (char[] b: board)
            System.out.println(b);
    }
}

