/*
343. Integer Break
Total Accepted: 17128 Total Submissions: 40740 Difficulty: Medium

Given a positive integer n, break it into the sum of at least two positive
integers and maximize the product of those integers. Return the maximum
product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36
(10 = 3 + 3 + 4).

Note: you may assume that n is not less than 2.

Hint:
    There is a simple O(n) solution to this problem.
    You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public int integerBreak(int n) {
        if (n <= 3)
            return n-1;
        int[] cache = new int[] {3,1,2};
        for (int i = 4; i <= n; ++i)
            cache[i%3] = Math.max(2*cache[(i-2)%3],3*cache[(i-3)%3]);
        return cache[n%3];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int n;
        n = 10;
        System.out.println("Result: " + sol.integerBreak(n));
    }
}

