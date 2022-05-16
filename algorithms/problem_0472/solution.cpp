/*
472. Concatenated Words
Hard

Given an array of strings words (without duplicates), return all the
concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at
least two shorter words in the given array.

Example 1:
Input: words =
["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
"dogcatsdog" can be concatenated by "dog", "cats" and "dog";
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

Example 2:
Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <climits>
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

#include "common/ListNode.h"
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    struct Node {
        bool leaf = false;
        map<char, Node> children;
    };

    Node root;
    vector<string> res;

    void insert(string &word) {
        Node *node = &root;
        for (char c : word) {
            node = &(node->children[c]);
        }
        node->leaf = true;
    }

    bool visit(string &word, size_t index, int count) {
        Node *node = &root;
        size_t sz = word.size();
        while (index < sz) {
            char ch = word[index];
            auto it = node->children.find(ch);
            if (it == node->children.end())
                return false;
            node = &(it->second);
            if (node->leaf && index < sz - 1 && visit(word, index + 1, 1))
                return true;
            ++index;
        }
        return node->leaf && count > 0;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        for (auto &word : words)
            insert(word);
        res.resize(0);
        for (auto &word : words) {
            if (visit(word, 0, 0))
                res.push_back(word);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words;

    words = {"cat",        "cats",           "catsdogcats", "dog",
             "dogcatsdog", "hippopotamuses", "rat",         "ratcatdogcat"};
    words = sol.findAllConcatenatedWordsInADict(words);
    copy(begin(words), end(words), ostream_iterator<string>(cout, ", "));
    cout << endl;

    words = {"cat", "dog", "catdog"};
    words = sol.findAllConcatenatedWordsInADict(words);
    copy(begin(words), end(words), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
