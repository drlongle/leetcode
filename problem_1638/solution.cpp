/*
1638. Count Substrings That Differ by One Character
Medium

Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single
character by a different character such that the resulting substring is a substring of t. In other words,
find the number of substrings in s that differ from some substring in t by exactly one character.

For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

Return the number of substrings that satisfy the condition above.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "aba", t = "baba"
Output: 6
Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
The underlined portions are the substrings that are chosen from s and t.

Example 2:
Input: s = "ab", t = "bb"
Output: 3
Explanation: The following are the pairs of substrings from s and t that differ by 1 character:
("ab", "bb")
("ab", "bb")
("ab", "bb")
The underlined portions are the substrings that are chosen from s and t.

Example 3:
Input: s = "a", t = "a"
Output: 0

Example 4:
Input: s = "abe", t = "bbc"
Output: 10

Constraints:
1 <= s.length, t.length <= 100
s and t consist of lowercase English letters only.
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

class Solution {
public:
    struct Node {
        Node(): cnt(0) {}
        int cnt;
        map<char, Node> children;
    };

    void add(string& t, size_t index, Node& node) {
        if (index == t.size())
            return;

        Node& child = node.children[t[index]];
        ++child.cnt;
        add(t, index+1, child);
    }

    int visit(string& s, Node& node, size_t index, int changes) {
        if (index == s.size())
            return 0;
        int res = 0;
        for (auto& [ch, child]: node.children) {
            if (changes == 1 && s[index] == ch) {
                res += child.cnt;
                res += visit(s, child, index + 1, 1);
            } else if (changes == 0 && s[index] != ch) {
                res += child.cnt;
                res += visit(s, child, index + 1, 1);
            } else if (changes == 0 && s[index] == ch)
                res += visit(s, child, index + 1, 0);
        }

        return res;
    }
    int countSubstrings(string s, string t) {
        for (size_t i = 0; i < t.size(); ++i)
            add(t, i, root);

        int res = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            res += visit(s, root, i, 0);
        }

        return res;
    }

    Node root;
};

int main() {
    string s, t;

    // Output: 6
    {
        Solution sol;
        s = "aba", t = "baba";
        cout << sol.countSubstrings(s, t) << endl;
    }


    // Output: 3
    {
        Solution sol;
        s = "ab", t = "bb";
        cout << sol.countSubstrings(s, t) << endl;
    }

    // Output: 0
    {
        Solution sol;
        s = "a", t = "a";
        cout << sol.countSubstrings(s, t) << endl;
    }

    // Output: 10
    {
        Solution sol;
        s = "abe", t = "bbc";
        cout << sol.countSubstrings(s, t) << endl;
    }

    // Output: 33
    {
        Solution sol;
        s = "abbab", t = "bbbbb";
        cout << sol.countSubstrings(s, t) << endl;
    }
    return 0;
}
