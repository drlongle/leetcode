/*
318. Maximum Product of Word Lengths

    Total Accepted: 25710
    Total Submissions: 63956
    Difficulty: Medium

Given a string array words, find the maximum value of
length(word[i]) * length(word[j]) where the two words do not share common
letters. You may assume that each word will contain only lower case letters.
If no such two words exist, return 0.

Example 1:

Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:

Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:

Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words. 
*/

import java.io.*;
import java.util.*;

public class Solution {

    public int maxProduct(String[] words) {
        int wlen = words.length;

        boolean[][] matrix = new boolean[wlen][wlen];
        for (int i = 0; i < wlen; ++i)
            for (int j = i+1; j < wlen; ++j)
                matrix[i][j] = true;

        List<Set<Character>> lookup = new ArrayList<>();
        for (int i = 0; i < wlen; ++i)
        {
            Set<Character> chars = new HashSet<>();
            String s = words[i];
            for (int j = 0; j < s.length(); ++j)
            {
                char ch = s.charAt(j);
                if (chars.contains(ch))
                    continue;
                for (int k = 0; k < i; ++k)
                {
                    if (matrix[k][i] && lookup.get(k).contains(ch))
                        matrix[k][i] = false; 
                }
                chars.add(ch);
            }
            lookup.add(chars);
        }

        int res = 0;
        for (int i = 0; i < wlen; ++i)
        {
            for (int j = i+1; j < wlen; ++j)
            {
                if (matrix[i][j])
                {
                    int r = words[i].length() * words[j].length();
                    if (r > res)
                        res = r;
                }
            }
        }

       return res; 
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] input;

        input = new String[] {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
        System.out.println("Result: " + sol.maxProduct(input));
    }
}

