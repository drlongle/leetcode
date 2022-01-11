/*
126. Word Ladder II

    Total Accepted: 51938
    Total Submissions: 379499
    Difficulty: Hard

Given two words (beginWord and endWord), and a dictionary's word list, find all
shortest transformation sequence(s) from beginWord to endWord, such that:
    Only one letter can be changed at a time
    Each intermediate word must exist in the word list

For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]

Note:
    All words have the same length.
    All words contain only lowercase alphabetic characters.

*/

import java.io.*;
import java.util.*;

public class Solution {
    public class Entry
    {
        Entry(String w, int h)
        {
            word = w;
            hops = h;
            prev = new HashSet<>();
        }

        public List<List<String>> getPath()
        {
            List<List<String>> res = new ArrayList<>();
            if (hops == 1)
            {
        	List<String> subres = new ArrayList<>();
    	        subres.add(word);
         	res.add(subres);
            }
            else
            {
        	for (String pre: prev)
    	        {
		    List<List<String>> subres = lookup.get(pre).getPath();
		    for (List<String> li: subres)
    	            {
			li.add(word);
			if (li.size() <= shortestPath)
    		            res.add(li);
		    }
    	        }
            }

	    return res;
        }

        String word;
        Set<String> prev;
        int hops;
    }

    Map<String, Entry> lookup;
    int shortestPath;

    public List<List<String>> findLadders(String beginWord, String endWord,
        Set<String> wordList)
    {
        List<List<String>> res;
        if (beginWord.equals(endWord))
        {
            List<String> list = new ArrayList<>();
            list.add(beginWord);
            res = new ArrayList<>();
            res.add(list);
            return res;
        }

        shortestPath = Integer.MAX_VALUE;
        Deque<Entry> queue = new ArrayDeque<>();
        Entry firstEntry = new Entry(beginWord,1);
        lookup = new HashMap<>();
        lookup.put(beginWord, firstEntry);
	queue.offer(firstEntry);

	while (!queue.isEmpty())
	{
	    Entry e = queue.poll();
	    if (e.hops+1 > shortestPath)
	        break;
            for (int i = 0; i < e.word.length(); ++i)
	    {
		char[] chars = e.word.toCharArray();
	        for (char ch = 'a'; ch <= 'z'; ++ch)
	        {
		    chars[i] = ch;
   	            if (ch == e.word.charAt(i))
	    	        continue;
  	            String word = new String(chars);
	            boolean wordEqual = word.equals(endWord);
	            if (!wordList.contains(word) && !wordEqual)
	    	        continue;
	            if (!lookup.containsKey(word))
	    	        lookup.put(word, new Entry(word, e.hops+1));
	            Entry newEntry = lookup.get(word);
	            if (newEntry.hops <= e.hops||newEntry.prev.contains(e.word))
	    	        continue;
		    newEntry.prev.add(e.word);
	            if (wordEqual)
			shortestPath = Math.min(shortestPath, e.hops+1);
		    else
			queue.offer(newEntry);
	        }
	    }
	}

	if (lookup.containsKey(endWord))
	    return lookup.get(endWord).getPath();
	else
	    return new ArrayList<>();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String beginWord = "hit";
	String endWord = "cog";
	Set<String> wordList = new HashSet<String>(Arrays.asList(
	    "hot","dot","dog","lot","log"));

	List<List<String>> res = sol.findLadders(beginWord, endWord, wordList);
	for (List<String> r: res)
	    System.out.println("Result: " + r);
    }
}

