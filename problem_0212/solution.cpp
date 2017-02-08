/*
212. Word Search II
Total Accepted: 21099 Total Submissions: 105280 Difficulty: Hard

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Return ["eat","oath"].

Note:
You may assume that all inputs are consist of lowercase letters a-z.

You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.
*/

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(): m_leaf(false), m_taken(false)
    {

    }

    TrieNode* find_child(char ch)
    {
        unordered_map<char, TrieNode*>::const_iterator it = m_children.find(ch);
        if (it == m_children.end())
            return 0;
        return it->second;
    }

    TrieNode* insert_child(char ch)
    {
        TrieNode* child = new TrieNode();
        m_children[ch] = child;
        return child;
    }

    string m_word;
    bool m_leaf;
    bool m_taken;
    unordered_map<char, TrieNode*> m_children;
};

class Trie {
public:
    Trie() {
        m_root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* curr = m_root;
        int index, wsize = word.size();
        if (!wsize)
        {
            m_root->m_leaf = true;
            return;
        }

        for (index = 0; index < wsize; ++index)
        {
            char ch = word[index];
            TrieNode* child = curr->find_child(ch);
            if (!child)
                child = curr->insert_child(ch);
            curr = child;
        }
        curr->m_word = word;
        curr->m_leaf = true;
    }

    TrieNode* internal_search(string word) {
        TrieNode* curr = m_root;
        int index, wsize = word.size();
        if (!wsize)
            return m_root;

        for (index = 0; index < wsize; ++index)
        {
            char ch = word[index];
            TrieNode* child = curr->find_child(ch);
            if (!child)
                return NULL;
            curr = child;
        }
        return curr;
    }

    // Returns if the word is in the trie.
    bool search(string word)
    {
        TrieNode* node = internal_search(word);
        if (!node)
            return false;
        return node->m_leaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = internal_search(prefix);
        return node != NULL;
    }

    TrieNode* m_root;
};

void find_words(vector<vector<char>>& board, int i, int j,
    TrieNode* node, vector<vector<bool>>& used, vector<string>& result)
{
    if (node->m_leaf && !node->m_taken)
    {
        node->m_taken = true;
        result.emplace_back(node->m_word);
    }
    int rows = board.size();
    int columns = board[0].size();
    array<array<int,2>, 4> offsets = {1,0,-1,0,0,1,0,-1};
    used[i][j] = true;
    for (const auto& offset: offsets)
    {
        int next_i = i + offset[0];
        int next_j = j + offset[1];
        if (next_i >= 0 && next_i < rows && next_j >= 0 && next_j < columns &&
            !used[next_i][next_j])
        {
            TrieNode* child = node->find_child(board[next_i][next_j]);
            if (child)
                find_words(board, next_i, next_j, child, used, result);
        }
    }
    used[i][j] = false;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board,
        vector<string>& words) {
        vector<string> res;
        int rows = board.size();
        if (!rows) return res;
        int columns = board[0].size();
        if (!columns) return res;

        Trie trie;
        for (const auto& w: words)
            trie.insert(w);
        vector<vector<bool> > used =
            vector<vector<bool>>(rows, vector<bool>(columns, false));

        TrieNode* root = trie.m_root;
        if (root->m_leaf)
        {
            root->m_taken = true;
            res.emplace_back(root->m_word);
        }

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < columns; ++j)
            {
                TrieNode* node = root->find_child(board[i][j]);
                if (node)
                    find_words(board, i, j, node, used, res);
            }

        return res; 
    }
};

int main()
{
    Solution sol;
    vector<vector<char>> board;
    vector<string> input, words, res;

    //Expected: ["eat","oath"] 
    input = {"oaan","etae","ihkr","iflv"};
    words = {"oath","pea","eat","rain"};

    board = vector<vector<char>>(input.size());
    for (size_t i =  0; i < input.size(); ++i)
        copy(input[i].begin(), input[i].end(), back_inserter(board[i]));

    res = sol.findWords(board, words);
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, ","));
    cout << endl;

    return 0;
}

