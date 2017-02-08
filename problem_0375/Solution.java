/*
375. Guess Number Higher or Lower II

    Total Accepted: 1042
    Total Submissions: 3765
    Difficulty: Medium

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher
or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x.
You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.

Given a particular n >= 1, find out how much money you need to have to guarantee
a win.

Hint:
     1. The best strategy to play the game is to minimize the maximum loss you could possibly face. Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
    2. Take a small example (n = 3). What do you end up paying in the worst case?
    3. Check out this article if you're still stuck.
      https://en.wikipedia.org/wiki/Minimax
    4. The purely recursive implementation of minimax would be worthless for even a small n. You MUST use dynamic programming.
    5. As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss, instead of the worst-case loss?
*/

import java.io.*;
import java.util.*;

public class Solution {

    private int[][] m_cache;

    public int getMoneyAmount(int low, int high)
    {
        if (m_cache[low][high] >= 0)
            return m_cache[low][high];
        int diff = high-low;
        switch(diff)
        {
            case 0: return 0;
            case 1: return low;
            case 2: return low+1;
        }

        int result = Integer.MAX_VALUE;
        for (int index = low+1; index < high; ++index)
        {
            int res1 = getMoneyAmount(low,index-1);
            int res2 = getMoneyAmount(index+1,high);
            int temp = index + Math.max(res1,res2);
            if (temp < result) result = temp;
            if (res1 > res2) break;
        }

        m_cache[low][high] = result;
        return result;
    }

    public int getMoneyAmount(int n) {
        m_cache = new int[n+1][n+1];
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                m_cache[i][j] = -1;
        return getMoneyAmount(1,n);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.print("Enter a number: ");
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        for (int i = 1; i <= num; ++i)
            System.out.println(i + " --> " + sol.getMoneyAmount(i));
    }
}

