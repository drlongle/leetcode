/*
211. Add and Search Word - Data structure design

    Total Accepted: 33603
    Total Submissions: 166583
    Difficulty: Medium

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing
only letters a-z or '.'. A '.' means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.
*/

import java.io.*;
import java.util.*;

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

public class WordDictionary {
    public class TrieNode {
	TrieNode()
	{
	    children = new TrieNode[26];
	    isWord = false;
	    validLength = new HashSet<>();
	}
	
	void addWord(String word, int wordIndex)
	{
	    int wLen = word.length();
	    validLength.add(wLen-wordIndex);
	    if (wLen == wordIndex) {
		isWord = true;
		return;
	    }
	    int index = word.charAt(wordIndex)-'a';
	    if (children[index] == null)
		children[index] = new TrieNode();
	    children[index].addWord(word,wordIndex+1);
	}

	boolean searchWord(String word, int wordIndex)
	{
	    int wLen = word.length();
	    if (!validLength.contains(wLen-wordIndex))
		return false;
	    if (wLen == wordIndex)
		return isWord;
	    char ch = word.charAt(wordIndex);
	    boolean lastChar = (wLen == wordIndex+1);
	    if (ch != '.')
	    {
		TrieNode child = children[ch-'a'];
		if (child == null)
		    return false;
		else if (lastChar)
		    return child.isWord;
		else
		    return child.searchWord(word, wordIndex+1);
	    }
	    else
	    {
		if (lastChar)
		    return validLength.contains(1);
		for (TrieNode n: children)
		    if (n != null && n.searchWord(word, wordIndex+1))
		        return true;
		return false;
	    }
	}

	TrieNode[] children;
	boolean isWord;
	Set<Integer> validLength;
    }
  
    WordDictionary()
    {
	root = new TrieNode();
    }
    TrieNode root;

    // Adds a word into the data structure.
    public void addWord(String word) {
        root.addWord(word, 0);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
	return root.searchWord(word, 0);
    }

    public static void main(String[] args) {
        WordDictionary dict = new WordDictionary();

    dict.addWord("at");
    dict.addWord("and");
    dict.addWord("an");
    dict.addWord("add");
    System.out.println(dict.search("a"));
    System.out.println(dict.search(".at"));
    dict.addWord("bat");
    System.out.println(dict.search(".at"));
    System.out.println(dict.search("an."));
    System.out.println(dict.search("a.d."));
    System.out.println(dict.search("b."));
    System.out.println(dict.search("a.d"));
    System.out.println(dict.search("."));
    //Expected: [false,false,true,true,false,false,true,false]
  }
}

