/*
115. Distinct Subsequences

Given a string S and a string T, count the number of distinct subsequences of
T in S. A subsequence of a string is a new string which is formed from the
original string by deleting some (can be none) of the characters without
disturbing the relative positions of the remaining characters. (i.e.,
"ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 

Give a sequence S and T, how many distinct subsequences from S equals to T? How
do you define "distinct" subsequence? Clearly, the 'distinct' here mean
different operation combination, not the final string of subsequence.
Otherwise, the result is always 0 or 1.

When you see string problem that is about subsequence or matching, dynamic
programming method should come to mind naturally. The key is to find the initial
and changing condition.
*/

import java.io.*;
import java.util.*;

public class Solution {

    public int numDistinct(String s, int sindex, String t, int tindex)
    {
        if (sindex >= slen)
            return 0;

        if (cached[sindex][tindex] >= 0)
            return cached[sindex][tindex];

        int index = sindex, res = 0;
        char ch = t.charAt(tindex);
        while ((index = s.indexOf(ch, index)) >= 0)
        {
            res += (tindex+1 == tlen) ? 1 :
                numDistinct(s, index+1, t, tindex+1);
            ++index;
        }
        cached[sindex][tindex] = res;

        return res;
    }

    public int numDistinct(String s, String t)
    {
        slen = s.length();
        tlen = t.length();
        if (slen == 0 || tlen == 0)
            return 0;
        cached = new int [slen][tlen];
        for (int i = 0; i < slen; ++i)
            for (int j = 0; j < tlen; ++j)
                cached[i][j] = -1;
        return numDistinct(s, 0, t, 0);
    }

    public int[][] cached;
    int slen, tlen;
    public static void main(String[] args)
    {
        Solution sol = new Solution();
        String s, t;

        // Expected: 4
        s = "aabb";
        t = "ab";
        System.out.println("Result: " + sol.numDistinct(s, t));
    }
}
