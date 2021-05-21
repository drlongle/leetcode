/*
320. Generalized Abbreviation
Medium

A word's generalized abbreviation can be constructed by taking any number of non-overlapping substrings and
replacing them with their respective lengths. For example, "abcde" can be abbreviated into "a3e" ("bcd" turned
into "3"), "1bcd1" ("a" and "e" both turned into "1"), and "23" ("ab" turned into "2" and "cde" turned into "3").

Given a string word, return a list of all the possible generalized abbreviations of word. Return the answer in any order.

Example 1:
Input: word = "word"
Output: ["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]

Example 2:
Input: word = "a"
Output: ["1","a"]

Constraints:
1 <= word.length <= 15
word consists of only lowercase English letters.
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
    vector<string> generateAbbreviations(string word) {
        vector<string> res{word, to_string(word.size())};
        for (int i = 1; i < word.size(); ++i){
            string s1 = to_string(i), s2 = word.substr(0, i);
            for (auto& w: generateAbbreviations(word.substr(i))) {
                if (w.empty() || isdigit(w[0]))
                    res.emplace_back (s2 + w);
                if (w.empty()|| isalpha(w[0]))
                    res.emplace_back (s1+w);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
