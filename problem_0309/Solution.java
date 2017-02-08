/*
309. Best Time to Buy and Sell Stock with Cooldown

    Total Accepted: 25369

    Total Submissions: 65403
    Difficulty: Medium

Say you have an array for which the i-th element is the price of a given stock
on day i. Design an algorithm to find the maximum profit. You may complete as
many transactions as you like (ie, buy one and sell one share of the stock
multiple times) with the following restrictions:

    - You may not engage in multiple transactions at the same time (i.e., you
      must sell the stock before you buy again).
    - After you sell your stock, you cannot buy stock on next day (i.e.,
      cooldown 1 day)

Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

import java.io.*;
import java.util.*;

public class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null)
            return 0;
        int nsize = prices.length;
        if (nsize <= 1)
            return 0;
        
        int maxProfit = 0;
        int[][] profit = new int[nsize][nsize];

        for (int i = 0; i < nsize; ++i)
        {
            int lowIndex = i;
            int highIndex = i;
            for (int j = i+1; j < Math.min(i+3, nsize); ++j)
            {
                profit[i][j] = 0;
                if (prices[lowIndex] > prices[j])
                    lowIndex = j;
                if (prices[highIndex] < prices[j])
                    highIndex = j;
                if (lowIndex < highIndex)
                {
                    int diff = prices[highIndex] - prices[lowIndex];
                    if (profit[i][j] < diff)
                        profit[i][j] = diff;
                    if (maxProfit < diff)
                        maxProfit = diff;
                }
            }
        }
        
        for (int len = 5; len < nsize; ++len)
        {
            for (int i = 0; i < nsize-len; ++i)
            {
                for (int j = 2; j < nsize-len-1; ++j)
                {
                    int temp = profit[i][j-1] + profit[j+1][nsize-len-1];
                    if (profit[i][j] < temp)
                        profit[i][j] = temp;
                    if (maxProfit < temp)
                        maxProfit = temp;
                }
            }
        }

        return maxProfit;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] prices;
        
        // Expected: 3
        prices = new int[] {1, 2, 3, 0, 2};

        // Expected: 1
        // prices = new int[] {1, 2};

        // Expected: 0
        // prices = new int[] {2, 1};
        
        // 78 / 212 test cases passed.
        // Expected: 1
        //prices = new int[] {4, 1, 2};

        // 78 / 212 test cases passed.
        // Expected: 1
        //prices = new int[] {2,1,2,0,1};
        
        // 82 / 212 test cases passed.
        // Expected: 0
        // prices = new int[] {4, 2, 1};
        
        // 83 / 212 test cases passed.
        // Expected: 7
        //prices = new int[] {3,2,6,5,0,3};

        // 88 / 212 test cases passed.
        // Expected: 3
        // prices = new int[] {1,2,4};

        // 95 / 212 test cases passed.
        // Expected: 3
        // prices = new int[] {2,1,2,0,1};

        // 104 / 212 test cases passed.
        // Expected: 10
        // prices = new int[] {2,1,4,5,2,9,7};
        
        System.out.println("Result: " + sol.maxProfit(prices));
    }
}
