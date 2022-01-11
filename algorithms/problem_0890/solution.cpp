/*
890. Find and Replace Pattern
Medium

Given a list of strings words and a string pattern, return a list of words[i] that match pattern.
You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every
letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter,
and no two letters map to the same letter.

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Example 2:
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]

Constraints:
1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    bool match(string& s, string& p) {
        if (s.size() != p.size())
            return false;
        unordered_map<char, char> m1, m2;
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            char c = s[i], d = p[i];
            int c1 = m1.count(c), c2 = m2.count(d);
            if (c1 + c2 == 1)
                return false;
            if (c1 == 0) {
                m1[c] = d;
                m2[d] = c;
            } else {
                if (m1[c] != d || m2[d] != c)
                    return false;
            }
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto& w: words) {
            if (match(w, pattern))
                res.push_back(w);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words, res;
    string pattern;

    // Output: {"mee","aqq"}
    words = {"abc","deq","mee","aqq","dkd","ccc"}, pattern = "abb";
    res = sol.findAndReplacePattern(words, pattern);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    // Output: {"a","b","c"}
    words = {"a","b","c"}, pattern = "a";
    res = sol.findAndReplacePattern(words, pattern);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;

    return 0;
}
