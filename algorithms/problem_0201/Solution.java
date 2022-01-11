/*
201. Bitwise AND of Numbers Range

    Total Accepted: 37445
    Total Submissions: 119571
    Difficulty: Medium

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4. 
*/

import java.io.*;
import java.util.*;

public class Solution {

    public int rangeBitwiseAndSlow(int m, int n) {
        int res = m;
        for (int i = m+1; res != 0 && i <= n; ++i)
            res &= i;
        return res;
    }

    int highestBit(int n)
    {
        int s = 31;
        while (((1 << s) & n) == 0 && s >= 0)
            --s;
        return s;
    }

    public int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;
        int h_m = highestBit(m);
        int h_n = highestBit(n);
        if (h_m != h_n)
            return 0;

        int res = 1 << h_m;
        res |= rangeBitwiseAnd(m & (~(1<< h_m)), n & (~(1<<h_n)));

        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int m, n;
        m = 3;
        n = 4;

        System.out.println("Slow: " + sol.rangeBitwiseAndSlow(m,n) +
            ", fast: " + sol.rangeBitwiseAnd(m,n));
    }
}

