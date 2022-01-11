/*
459. Repeated Substring Pattern

    User Accepted: 452
    User Tried: 535
    Total Accepted: 465
    Total Submissions: 1204
    Difficulty: Easy

Given a non-empty string check if it can be constructed by taking a substring
of it and appending multiple copies of the substring together. You may assume
the given string consists of lowercase English letters only and its length
will not exceed 10000.

Example 1:

Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.

Example 2:

Input: "aba"

Output: False

Example 3:

Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc"
twice.)
 */

import java.io.*;
import java.util.*;

public class Solution {
    public List<Integer> getDivisors(int n)
    {
        List<Integer> res = new ArrayList<>();
        boolean[] flags = new boolean[n];
        for (int i = 0; i < n; ++i)
            flags[i] = false;

        for (int i = 2; i < n; ++i)
        {
            if (flags[i] || n % i != 0)
                continue;
            for (int j = i; j < n; j += i)
            {
                if (j < n && n % j == 0)
                {
                    flags[j] = true;
                    res.add(j);
                }
            }
        }

        return res;
    }

    
    public boolean repeatedSubstringPattern(String str) {
        int slen = str.length();
        if (slen <= 1)
            return false;
        List<Integer> div = getDivisors(slen);
        div.add(1);
        for (int sublen: div)
        {
            int index = sublen;
            boolean match = true;
            String pattern = str.substring(0, sublen);
            while (index +sublen <= slen && match)
            {
                String substr = str.substring(index, index + sublen);
                if (!substr.equals(pattern))
                    match = false;
                index += sublen;
            }
            if (match)
                return true;
        }

        return false;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String str;
        
        str = "abab";
        str = "aba";
        str = "abcabcabcabc";
        str = "bb";
        str = "abcabc";
        str = "ab";
        str = "aaaabaaaab";
        
        System.out.println("Result: " + sol.repeatedSubstringPattern(str));
    }
}
