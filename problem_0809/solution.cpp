/*
809. Expressive Words
Medium

Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  In these strings like "heeellooo", we have groups of adjacent letters that are all the same:  "h", "eee", "ll", "ooo".

For some given string S, a query word is stretchy if it can be made to be equal to S by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is 3 or more.

For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has size less than 3.  Also, we could do another extension like "ll" -> "lllll" to get "helllllooo".  If S = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = S.

Given a list of query words, return the number of words that are stretchy. 

Example:
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1

Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.

Notes:
0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters
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
    vector<pair<char, int>> encode(string& s) {
        int sz = s.size(), cnt = 1;
        vector<pair<char, int>> res;
        if (sz == 0)
            return res;
        char curr = s[0];
        for (int i = 1; i < sz; ++i) {
            char ch = s[i];
            if (curr == ch)
                ++cnt;
            else {
                res.emplace_back(curr, cnt);
                curr = ch;
                cnt = 1;
            }
        }
        res.emplace_back(curr, cnt);
        return res;
    }

    bool match(vector<pair<char, int>>& pattern, vector<pair<char, int>>& encoded) {
        if (pattern.size() != encoded.size())
            return false;
        int n = pattern.size();
        for (int i = 0; i < n; ++i) {
            if (pattern[i].first != encoded[i].first || pattern[i].second > encoded[i].second ||
                (pattern[i].second != encoded[i].second && encoded[i].second < 3))
                return false;
        }
        return true;
    }
    
    int expressiveWords(string S, vector<string>& words) {
        auto se = encode(S);
        int res = 0;
        for (auto& word: words) {
            auto sw = encode(word);
            res += match(sw, se);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    string S;

    // Output: 1
    S = "heeellooo";
    words = {"hello", "hi", "helo"};
    cout << sol.expressiveWords(S, words) << endl;

    // Output: 0
    S = "aaa";
    words = {"aaaa"};
    cout << sol.expressiveWords(S, words) << endl;
    
    return 0;
}
