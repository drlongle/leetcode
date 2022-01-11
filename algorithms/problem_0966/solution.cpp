/*
966. Vowel Spellchecker
Medium

Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"

Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)

In addition, the spell checker operates under the following precedence rules:
When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

Example 1:
Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]

Note:
1 <= wordlist.length <= 5000
1 <= queries.length <= 5000
1 <= wordlist[i].length <= 7
1 <= queries[i].length <= 7
All strings in wordlist and queries consist only of english letters.
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

    string tolower(const string& s) {
        string res(s);
        for (char& c: res)
            c = std::tolower(c);
        return res;
    }

    string mask_vowels(const string& s) {
        static unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        string res(s);
        for (char& c: res) {
            if (vowels.count(c))
                c = '#';
        }
        return res;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

        unordered_map<string, int> exact_match;
        unordered_map<string, int> case_match, vowel_match;
        for (int i = 0, n = wordlist.size(); i < n; ++i) {
            string word = wordlist[i];
            exact_match.emplace(word, i);
            word = tolower(word);
            case_match.emplace(word, i);
            vowel_match.emplace(mask_vowels(word), i);
        }

        vector<string> res;
        for (string& s: queries) {
            if (exact_match.count(s)) {
                res.push_back(s);
                continue;
            }
            s = tolower(s);
            auto it = case_match.find(s);
            if (it != case_match.end()) {
                res.push_back(wordlist[it->second]);
                continue;
            }

            it = vowel_match.find(mask_vowels(s));
            if (it != vowel_match.end()) {
                res.push_back(wordlist[it->second]);
                continue;
            }

            res.emplace_back("");
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> wordlist, queries, res;

    // ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
    wordlist = {"KiTe","kite","hare","Hare"};
    queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    res = sol.spellchecker(wordlist, queries);
    copy(begin(res), end(res), ostream_iterator<string>(cout, ", "));
    cout << endl;


    return 0;
}
