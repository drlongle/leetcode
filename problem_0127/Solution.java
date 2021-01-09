/*
127. Word Ladder

    Total Accepted: 90546
    Total Submissions: 462748
    Difficulty: Medium

Given two words (beginWord and endWord), and a dictionary's word list, find the
length of shortest transformation sequence from beginWord to endWord, such that:
    Only one letter can be changed at a time
    Each intermediate word must exist in the word list

For example,
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Note:
    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
*/

import java.io.*;
import java.util.*;
import java.util.logging.Logger;

public class Solution {
    public class QueueEntry
    {
        QueueEntry(String w, int h)
        {
            word = w;
            hops = h;
        }
        String word;
        int hops;
    }

    public int ladderLength(String beginWord, String endWord,
        List<String> wList)
    {
    Set<String> wordList = new HashSet<String>(wList);
	Deque<QueueEntry> queue = new ArrayDeque<>();
	queue.offer(new QueueEntry(beginWord,1));
	while (!queue.isEmpty())
	{
	    QueueEntry e = queue.poll();
	    if (e.word.equals(endWord))
          return e.hops;
  	    for (int i = 0; i < e.word.length(); ++i)
	    {
		char[] chars = e.word.toCharArray();
	        for (char ch = 'a'; ch <= 'z'; ++ch)
	        {
  	            chars[i] = ch;
  	            String word = new String(chars);
	            if (wordList.contains(word))
	            {
	                QueueEntry newEntry = new QueueEntry(word, e.hops+1);
	                queue.offer(newEntry);
	                wordList.remove(word);
	            }
	        }
	    }
	}

	return 0; 
    }

    public static void main(String[] args) {
	Solution sol = new Solution();
	String beginWord = "hit";
	String endWord = "cog";
	List<String> wordList = Arrays.asList( "hot","dot","dog","lot","log");
	int res = sol.ladderLength(beginWord, endWord, wordList);
	Logger.getGlobal().info("Result: " + res);
    }
}
