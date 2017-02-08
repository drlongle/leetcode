/*
140. Word Break II

    Total Accepted: 59700
    Total Submissions: 293118
    Difficulty: Hard

Given a string s and a dictionary of words dict, add spaces in s to construct
a sentence where each word is a valid dictionary word.
Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

import java.io.*;
import java.util.*;

public class Solution {

    public List<String> wordBreak_1(String s, Set<String> wordDict) {
        int len = s.length();
        List<ArrayList<String>> res = new ArrayList<>();

        for (int i = 0; i < len; ++i)
        {
            res.add(new ArrayList<String>());
            String temp = s.substring(0,i+1);
            if (wordDict.contains(temp))
                res.get(i).add(temp);
            for (int j = 0; j < i; ++j)
            {
                temp = s.substring(j+1,i+1);
                if (res.get(j).size() > 0 && wordDict.contains(temp))
                {
                    for (int k = 0; k < res.get(j).size(); ++k)
                    {
                        String st = res.get(j).get(k);
                        st += " " + temp;
                        res.get(i).add(st);
                    }
                }
            }
        }

        return res.get(len-1);
    }

    class Entry
    {
        Entry(int i, String w)
        {
            index = i;
            word = w;
        }

        int index;
        String word;
    }

    public List<String> getStrings(List<ArrayList<Entry>> entries, int index)
    {
        List<String> res = new ArrayList<String>();
        if (index == 0)
        {
            res.add(new String());
            return res;
        }

        List<String> ls;
        for (Entry e: entries.get(index))
        {
            ls = getStrings(entries, e.index);
            for (String s: ls)
            {
                if (s.isEmpty())
                    res.add(e.word);
                else
                    res.add(s + " " + e.word);
            }
        }

        return res;
    }

    public List<String> wordBreak(String s, Set<String> wordDict)
    {
        int len = s.length();
        if (len == 0 || wordDict.size() == 0)
            return new ArrayList<>();

        List<ArrayList<Entry>> res = new ArrayList<>();
        for (int i = 0; i <= len; ++i)
            res.add(new ArrayList<Entry>());

        for (int i = 0; i < len; ++i)
        {
            if (i != 0 && res.get(i).size() == 0)
                continue;
            for (String w : wordDict)
            {
                int wlen = w.length();
                if (i+wlen <= len && s.regionMatches(i, w, 0, wlen))
                    res.get(i+wlen).add(new Entry(i,w));
            }
        }

        return getStrings(res, len);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        Set<String> dict;
        String s;
        List<String> result;

        dict = new HashSet<String>(Arrays.asList("leet","code"));
        s = "leetcode";
        result = sol.wordBreak(s,dict);
        for (int i = 0; i < result.size(); ++i)
            System.out.println(i + " -> " + result.get(i));
    }
}

