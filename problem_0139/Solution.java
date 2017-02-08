/*
139. Word Break
    Total Accepted: 92410
    Total Submissions: 356258
    Difficulty: Medium

Given a string s and a dictionary of words dict, determine if s can be segmented
into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code". 
*/

import java.io.*;
import java.util.*;

public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        int len = s.length();
        boolean[] res = new boolean[len];

        for (int i = 0; i < len; ++i)
        {
            if (wordDict.contains(s.substring(0,i+1)))
                res[i] = true;
            for (int j = 0; j < i && !res[i]; ++j)
            {
                if (res[j] && wordDict.contains(s.substring(j+1,i+1)))
                    res[i] = true;
            }
        }

        return res[len-1];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        Set<String> dict;
        String s;

        dict = new HashSet<String>(Arrays.asList("leet","code"));
        s = "leetcode";
        System.out.println("Result: " + sol.wordBreak(s,dict));
    }
}

