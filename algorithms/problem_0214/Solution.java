/*
214. Shortest Palindrome

    Total Accepted: 27127
    Total Submissions: 124639
    Difficulty: Hard

Given a string S, you are allowed to convert it to a palindrome by adding
characters in front of it. Find and return the shortest palindrome you can
find by performing this transformation.

For example:
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
 */

import java.io.*;
import java.util.*;

public class Solution {
    
    String getExtendedString(String s, int index)
    {
        String sub = s.substring(index, s.length());
        StringBuilder sb = new StringBuilder();
        sb.append(sub);
        sb = sb.reverse();
        return sb.toString();        
    }

    public boolean extendString(String s, int i, int j)
    {
        while (i >= 0 && j < s.length())
        {
            if (s.charAt(i) != s.charAt(j))
                return false;
            --i;
            ++j;
        }

        if (j == s.length())
        {
            if (i >= 0)
                return false;
            extension = new String();
        } else
            extension = getExtendedString(s, j);
        return true;
    }

    public String shortestPalindrome(String s)
    {
        int length = s.length();
        if (length == 0)
            return new String();

        for (int i = length >> 1; i >= 0; --i)
        {
            if (extendString(s, i, i+1))
                break;
            if (extendString(s, i, i))
                break;
        }

        if (extension == null)
            extension = getExtendedString(s, 0);
        StringBuilder sb = new StringBuilder();
        sb.append(extension).append(s);

        return sb.toString();
    }

    String extension;

    public static void main(String[] args) {
        Solution sol = new Solution();
        String s, res;
        s = "aabba"; // Expected: "abbaabba"
        res = sol.shortestPalindrome(s);
        System.out.println("Result: " + res);
    }
}
