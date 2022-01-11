/*
745. Prefix and Suffix Search
Hard

Design a special dictionary which has some words and allows you to search the words in it
by a prefix and a suffix.

Implement the WordFilter class:
WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary
which has the prefix prefix and the suffix suffix. If there is more than one valid index,
return the largest of them. If there is no such word in the dictionary, return -1.

Example 1:
Input
["WordFilter", "f"]
[[["apple"]], ["a", "e"]]
Output
[null, 0]
Explanation
WordFilter wordFilter = new WordFilter(["apple"]);
wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix = "a" and suffix = 'e".

Constraints:
1 <= words.length <= 15000
1 <= words[i].length <= 10
1 <= prefix.length, suffix.length <= 10
words[i], prefix and suffix consist of lower-case English letters only.
At most 15000 calls will be made to the function f.
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

#include "common/TreeNode.h"

using namespace std;

struct Node {
    Node(): index(-1) {}
    int index;
    map<int, Node> kids;
};

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for (int n = 0, wsz = words.size(); n < wsz; ++n) {
            auto& word = words[n];
            int sz = word.size();
            string pref;
            for (int i = 0; i < sz; ++i) {
                pref.push_back(word[i]);
                string suff;
                for (int j = sz-1; j >= 0; --j) {
                    suff.push_back(word[j]);
                    insert(pref + ' ' + suff, n);
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        reverse(begin(suffix), end(suffix));
        string s = prefix + ' ' + suffix;
        Node* node = &root;
        for (char ch: s) {
            auto it = node->kids.find(ch);
            if (it == node->kids.end())
                return -1;
            node = &it->second;
        }
        return node->index;
    }

    void insert(string s, int index) {
        Node* node = &root;
        for (char ch: s) {
            node = &node->kids[ch];
        }
        node->index = max(index, node->index);
    }

    Node root;
};

void test_1() {
    vector<string> words{"apple"};
    WordFilter wf(words);
    cout << wf.f("a", "e") << endl;
}

void test_5() {
    vector<string> words{"cabaabaaaa","ccbcababac","bacaabccba","bcbbcbacaa","abcaccbcaa","accabaccaa",
                         "cabcbbbcca","ababccabcb","caccbbcbab","bccbacbcba"};
    WordFilter wf(words);

    vector<vector<string>> queries {{"bccbacbcba","a"},{"ab","abcaccbcaa"},{"a","aa"},{"cabaaba","abaaaa"},
                                    {"cacc","accbbcbab"},{"ccbcab","bac"},{"bac","cba"},{"ac","accabaccaa"},
                                    {"bcbb","aa"},{"ccbca","cbcababac"}};
    for (auto& q: queries)
        cout << wf.f(q[0], q[1]) << endl;
}

int main() {
    //test_1();
    test_5();
    return 0;
}
