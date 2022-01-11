/*
211. Add and Search Word - Data structure design

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

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

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class WordDictionary {
public:
    struct TreeNode {
        TreeNode(): leaf(false), children(26, nullptr)
        {
        }

        bool leaf;
        vector<TreeNode*> children;
    };

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TreeNode* node = &root;
        for (char ch: word) {
            int index = ch - 'a';
            auto& next = node->children[index];
            if (!next) {
                next = new TreeNode();
            }
            node = next;
        }
        if (!word.empty())
            node->leaf = true;
    }
    
    bool search(TreeNode* node, string& word, size_t index) {
        if (!node)
            return false;
        if (index == word.size())
            return node->leaf;
        char ch = word[index];
        if (ch != '.') {
            node = node->children[ch - 'a'];
            return search(node, word, index+1);
        }
        for (auto next: node->children) {
            if (search(next, word, index+1))
                return true;
        }
        return false;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(&root, word, 0);
    }

    TreeNode root;
};

void test_1()
{
    WordDictionary dict;
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    cout << dict.search("pad") << endl;
    cout << dict.search("bad") << endl;
    cout << dict.search(".ad") << endl;
    cout << dict.search("b..") << endl;
}

/*
["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
[[],["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]
*/
void test_2()
{
    WordDictionary dict;
    dict.addWord("at");
    dict.addWord("and");
    dict.addWord("an");
    dict.addWord("add");
    dict.addWord("a");
    cout << dict.search(".at") << endl;
}

int main() {
    test_1();
    //test_2();

    return 0;
}
