/*
208. Implement Trie (Prefix Tree)
Total Accepted: 38440 Total Submissions: 151444 Difficulty: Medium

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
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
    TrieNode(char ch): m_char(ch), m_leaf(false)
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
        TrieNode* child = new TrieNode(ch);
        m_children[ch] = child;
        return child;
    }

    char m_char;
    bool m_leaf;
    unordered_map<char, TrieNode*> m_children;
};

class Trie {
public:
    Trie() {
        m_root = new TrieNode('0');
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

private:
    TrieNode* m_root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


int main()
{
    return 0;
}

