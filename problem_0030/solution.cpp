/*
30. Substring with Concatenation of All Words

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].

Input: "wordgoodgoodgoodbestword"
["word","good","best","good"]
Expected: [8] 

Input: "barfoofoobarthefoobarman"
["bar","foo","the"]
Expected: [6,9,12] 
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
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
#include <vector>

#include <string.h>

using namespace std;

class TTreeNode {
public:
    TTreeNode(const string& word) : m_leaves(0), m_visits(0), m_word(word)
    {

    }

    ~TTreeNode()
    {
        for (auto& c: m_children)
            delete c.second;
    }

    void reSet()
    {
        m_visits = 0;
        for (auto& c: m_children)
            c.second->reSet();;
    }

    bool leaves_visited()
    {
        for (auto& c: m_children)
        if (c.second->leaves_visited() == false) return false;
        if (m_leaves) return m_visits == m_leaves;
        else return true;
    }

    int leaf_count()
    {
        int result = m_leaves;
        for (auto& c: m_children)
            result += c.second->leaf_count();
        return result;
    }

    int node_count()
    {
        int result = m_leaves ? 1 : 0;
        for (auto& c: m_children)
            result += c.second->node_count();
        return result;
    }

    int m_leaves;
    int m_visits;
    string m_word;
    map<char, TTreeNode*> m_children;
};

class Solution {
public:
    Solution() : m_root(0) { }

    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> result;
        set<string*> allwords;
        map<string*, set<int>>::iterator it;
        for (auto& w: words)
            allwords.emplace(&w);

        delete m_root;
        m_root = new TTreeNode("");
        int all_word_size = 0;
        for (auto& w: words)
        {
            TTreeNode* node = m_root;
            int s_size = static_cast<int>(w.size());
            all_word_size += s_size;
            if (s_size == 0) m_root->m_leaves += 1;
            for (int i = 0; i < s_size; ++i)
            {
                if (node->m_children.find(w[i]) == node->m_children.end())
                    node->m_children[w[i]] = new TTreeNode(node->m_word + w[i]);
                node = node->m_children[w[i]];
                if (i == s_size - 1)
                    node->m_leaves += 1;
            } 
        }

        int node_count = m_root->node_count();
        m_leaves = m_root->leaf_count();
        if (node_count == 1)
        {
            string::size_type pos = 0;
            string pattern;
            for (int count = 0; count < m_root->leaf_count(); ++count)
                pattern.append(words[0]);
            pos = s.find(pattern, 0);
            while (pos != string::npos)
            {
                result.push_back(static_cast<int>(pos));
                pos = s.find(pattern, pos+1);
            }
            return result;
        }

        int i, s_size =  static_cast<int>(s.size());
        for (i = 0; i <= s_size - all_word_size; ++i)
        {
            if ((node_count > 10) ?
                matchNode_recursive(s, i, m_root) :
                matchNode_iterative(s, i, m_root))
                result.emplace_back(i);
        }

        return result;
    }

    ~Solution()
    {
        delete m_root;
    }

    bool matchNode_iterative(const string& s, int pos, TTreeNode* node)
    {
        m_root->reSet();
        int visit = 0;
        while (node != NULL)
        {
            if (node->m_visits < node->m_leaves)
            {
                node->m_visits += 1;
                ++visit;
                if (node->m_visits == node->m_leaves && m_leaves == visit)
                    return true;
                else
                    node = m_root;
            } else {
                map<char, TTreeNode*>::iterator it = node->m_children.end();
                it = node->m_children.find(s[pos]);
                if (it != node->m_children.end() &&
                    pos+1 <= static_cast<int>(s.size()))
                {
                    ++pos;
                    node = it->second;
                } else
                    return false;
            }
        }
        return false;
    }

    bool matchNode_recursive(const string& s, int pos, TTreeNode* node)
    {
        bool result = false;
        if (node->m_visits < node->m_leaves)
        {
            node->m_visits += 1;
            if (node->m_visits == node->m_leaves && m_root->leaves_visited())
                result = true;
            else if (matchNode_recursive(s, pos, m_root))
                result = true;
            node->m_visits -= 1;
        }

        map<char, TTreeNode*>::iterator it = node->m_children.end();
        if (!result)
            it = node->m_children.find(s[pos]);

        if (it != node->m_children.end() && pos+1 <= static_cast<int>(s.size()))
            result = matchNode_recursive(s, pos+1, it->second);
        return result;
    }

    int m_leaves;
    TTreeNode* m_root;
};

int main()
{
    Solution sol;
    string s("wordgoodgoodgoodbestword");
    vector<string> words{"word","good","best","good"};
    vector<int> result = sol.findSubstring(s, words);
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}

