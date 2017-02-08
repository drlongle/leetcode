/*
200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3
*/

import java.io.*;
import java.util.*;

public class Solution {

    public class Entry {
        public Entry(int i, int j) {
            this.i = i;
            this.j = j;
        }

        public int i;
        public int j;
    }

    public void explore(char[][] grid, int i, int j) {
        int max_i = grid.length-1;
        int max_j = grid[0].length-1;
        Queue<Entry> queue = new ArrayDeque<>();
        queue.add(new Entry(i,j));
        grid[i][j] = '0';
        while (!queue.isEmpty()) {
            Entry e = queue.remove();
            if (e.i > 0 && grid[e.i-1][e.j] == '1') {
                grid[e.i-1][e.j] = '0';
                queue.add(new Entry(e.i-1,e.j));
            }
            if (e.i < max_i && grid[e.i+1][e.j] == '1') {
                grid[e.i+1][e.j] = '0';
                queue.add(new Entry(e.i+1,e.j));
            }
            if (e.j > 0 && grid[e.i][e.j-1] == '1') {
                grid[e.i][e.j-1] = '0';
                queue.add(new Entry(e.i,e.j-1));
            }
            if (e.j < max_j && grid[e.i][e.j+1] == '1') {
                grid[e.i][e.j+1] = '0';
                queue.add(new Entry(e.i,e.j+1));
            }
        }
    }

    public int numIslands(char[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; ++i)
        {
            for (int j = 0; j < grid[i].length; ++j)
            {
                if (grid[i][j] == '1') {
                    ++res;
                    explore(grid, i,j);
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        char[][] grid;
        grid = new char[][] {{1,1,0,0,0},{1,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,1}};
        System.out.println("Result: " + sol.numIslands(grid));
    }
}

