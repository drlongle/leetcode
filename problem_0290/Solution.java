/*
290. Word Pattern
Total Accepted: 41089 Total Submissions: 137093 Difficulty: Easy

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty word in str.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains
lowercase letters separated by a single space.
*/

import java.io.*;
import java.util.*;

public class Solution {
    public List<String> getWords(String str) {
        List<String> res = new ArrayList<>();
        int ssize = str.length();
        int index = 0;
        while (index < ssize)
        {
            while (index < ssize && str.charAt(index) == ' ')
                ++index;

            int end = index+1;
            while (end < ssize && str.charAt(end) != ' ')
                ++end;
            res.add(str.substring(index, end));
            index = end+1;
        }

        return res;
    }

    public boolean wordPattern(String pattern, String str) {
        List<String> words = getWords(str);
        int size = pattern.length();
        if (size != words.size())
            return false;

        Map<Character, String> forward = new HashMap<>();
        Map<String, Character> backward = new HashMap<>();
        for (int i = 0; i < size; ++i)
        {
            char ch = pattern.charAt(i);
            String word = words.get(i);
            if (forward.containsKey(ch))
            {
                if (forward.get(ch).equals(word) == false)
                    return false;
            }
            else
                forward.put(ch, word);

            if (backward.containsKey(word))
            {
                if (backward.get(word) != ch)
                    return false;
            }
            else
                backward.put(word, ch);
        }

        return true; 
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String pattern, str;

        // Expected: true
        pattern = "abba";
        str = "dog cat cat dog";
        System.out.println("Result: " + sol.wordPattern(pattern, str));
    }
}

