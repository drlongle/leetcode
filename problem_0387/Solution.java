/*
387. First Unique Character in a String

    Total Accepted: 14830
    Total Submissions: 34202
    Difficulty: Easy

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters. 
*/

import java.io.*;
import java.util.*;

public class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> lookup = new HashMap<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            char ch = s.charAt(i);
            if (lookup.containsKey(ch))
                lookup.put(ch, lookup.get(ch) + 1);
            else
                lookup.put(ch, 1);
        }

        for (int i = 0; i < n; ++i) {
            if (lookup.get(s.charAt(i)) == 1)
                return i;
        }

        return -1;
    }

    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("Usage: " + args[0] + " <string>");
            System.exit(1);
        }

        Solution sol = new Solution();
        int res = sol.firstUniqChar(args[0]);
        System.out.println("Result: " + res);
    }
}

