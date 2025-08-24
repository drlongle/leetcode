/*
720. Longest Word in Dictionary
Medium

Given an array of strings words representing an English Dictionary, return the longest word
in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest
lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character
being added to the end of a previous word.

Example 1:
Input: words = ["w","wo","wor","worl","world"]
Output: "world"
Explanation: The word "world" can be built one character at a time by
"w", "wo", "wor", and "worl".

Example 2:
Input: words = ["a","banana","app","appl","ap","apply","apple"]
Output: "apple"
Explanation: Both "apply" and "apple" can be built from other words in the dictionary.
However, "apple" is lexicographically smaller than "apply".

Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 30
words[i] consists of lowercase English letters.
*/

#include <algorithm>
#include <atomic>
#include <bit>
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
#include <ranges>
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

struct Node {
    bool isLeaf = false;
    unordered_map<char, Node> children;
};

class Solution {
public:
    Node root;

    void insert(Node* node, string& word) {
        for (char ch: word) {
            node = &(node->children[ch]);
        }
        node->isLeaf = true;
    }

    void visit(Node* node, string& word) {
        for (char ch: word) {
            node = &(node->children[ch]);
            if (!node->isLeaf) {
                return;
            }
        }
        if (word.size() > result.size() ||
            (word.size() == result.size() && word < result)) {
            result = word;
        }
    }

    string result;

    string longestWord(vector<string>& words) {
        for (auto word: words) {
            insert(&root, word);
        }

        for (auto word: words) {
            visit(&root, word);
        }

        return result;
    }
};

int main() {
    return 0;
}
