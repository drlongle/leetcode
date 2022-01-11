/*
174. Dungeon Game

    Total Accepted: 30096
    Total Submissions: 135036
    Difficulty: Hard

The demons had captured the princess (P) and imprisoned her in the bottom-right
corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid.
Our valiant knight (K) was initially positioned in the top-left room and must
fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at
any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers)
upon entering these rooms; other rooms are either empty (0's) or contain magic
orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move
only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is
able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at
least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)  -3      3
-5      -10     1
10       30     -5 (P)

Notes:
    The knight's health has no upper bound.
    Any room can contain threats or power-ups, even the first room the knight
    enters and the bottom-right room where the princess is imprisoned.
*/

import java.io.*;
import java.util.*;

public class Solution
{
    public class Pair
    {
        Pair(int i, int j)
        {
            this.i = i;
            this.j = j;
        }

        @Override
        public int hashCode()
        {
            return i*5 + j*7;
        }

        @Override
        public boolean equals(Object o)
        {
            if (o != null && o instanceof Pair)
            {
                Pair p = (Pair) o;
                return i == p.i && j == p.j;
            }
            else
                return false;
        }

        int i, j;
    }

    public int calculateMinimumHP(int[][] dungeon, int i, int j)
    {
        Pair pair = new Pair(i,j);
        if (cache.containsKey(pair))
            return cache.get(pair);
        
        boolean isStartCell = (i == 0 && j == 0);
        int cell = dungeon[i][j];
        int result;
        if (cell > 0)
            result = 0;
        else
            result = (isStartCell ? 1 : 0) - dungeon[i][j] ;

        if (i < dungeon.length - 1 || j < dungeon[0].length-1)
        {
            int x = Integer.MAX_VALUE, y = Integer.MAX_VALUE;
            if (i < dungeon.length - 1)
                x = calculateMinimumHP(dungeon, i+1, j);
            if (j < dungeon[0].length-1)
                y = calculateMinimumHP(dungeon, i, j+1);
            if (y < x)
                x = y;
            if (x > 0)
            {
                if (cell > 0)
                    x -= cell - (isStartCell ? 1 : 0);
                if (x > 0)
                    result += x;
            }
        }
        cache.put(pair, result);

        return result;
    }

    public int calculateMinimumHP(int[][] dungeon)
    {
        if (dungeon.length == 0 || dungeon[0].length == 0)
            return 1;
        cache = new HashMap<>();
        int result = calculateMinimumHP(dungeon, 0, 0);
        if (result == 0)
            return 1;
        else
            return result;
    }
    Map<Pair, Integer> cache;

    public static void main(String[] args)
    {
        Solution sol = new Solution();
        int[][] dungeon;
        dungeon = new int[][] {{0}};
        dungeon = new int[][] {{-3,5}};

        System.out.println("Result: " + sol.calculateMinimumHP(dungeon));
    }
}
