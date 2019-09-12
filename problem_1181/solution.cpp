/*
1181. Before and After Puzzle
Medium

Given a list of phrases, generate a list of Before and After puzzles.

A phrase is a string that consists of lowercase English letters and spaces only. No space appears in the start or the end of a phrase. There are no consecutive spaces in a phrase.

Before and After puzzles are phrases that are formed by merging two phrases where the last word of the first phrase is the same as the first word of the second phrase.

Return the Before and After puzzles that can be formed by every two phrases phrases[i] and phrases[j] where i != j. Note that the order of matching two phrases matters, we want to consider both orders.

You should return a list of distinct strings sorted lexicographically. 

Example 1:
Input: phrases = ["writing code","code rocks"]
Output: ["writing code rocks"]

Example 2:

Input: phrases = ["mission statement",
                  "a quick bite to eat",
                  "a chip off the old block",
                  "chocolate bar",
                  "mission impossible",
                  "a man on a mission",
                  "block party",
                  "eat my words",
                  "bar of soap"]
Output: ["a chip off the old block party",
         "a man on a mission impossible",
         "a man on a mission statement",
         "a quick bite to eat my words",
         "chocolate bar of soap"]


Example 3:

Input: phrases = ["a","b","a"]
Output: ["a"]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

struct Phrase {
    Phrase(string& s, int f, int l, bool u): ref(s), first_len(f), last_len(l), used(u) {}
    string& ref;
    int first_len;
    int last_len;
    bool used;
};

class Solution {
public:
    map<string, vector<Phrase>> table;
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        table.clear();
        for (auto& ph: phrases) {
            auto index = ph.find_first_of(" ");
            if (index == string::npos) {
                table[ph].emplace_back(ph, ph.size(), -1, false);
                continue;
            }
            auto last_index = ph.find_last_of(" ");
            table[ph.substr(0, index)].emplace_back(ph, index, last_index, false);
        }
        
        set<string> res;
        vector<Phrase> puzzles;
        for (auto& p: table) {
            for (auto& phrase: p.second) {
                phrase.used = true;
                auto begin = phrase.ref.substr(0, phrase.first_len);
                auto end = phrase.ref.substr(phrase.last_len+1);
                for (auto& second_phrase: table[end]) {
                    if (second_phrase.used)
                        continue;
                    string s;
                    if (second_phrase.last_len > 0)
                        s = phrase.ref + second_phrase.ref.substr(second_phrase.first_len);
                    else
                        s = phrase.ref;
                    res.emplace(s);
                }
                phrase.used = false;
            }
        }
        return vector<string>(begin(res), end(res));
    }
};

int main() {
    Solution sol;
    vector<string> phrases;

    phrases = {"writing code","code rocks"};

    /*
    phrases = {"mission statement",
               "a quick bite to eat",
               "a chip off the old block",
               "chocolate bar",
               "mission impossible",
               "a man on a mission",
               "block party",
               "eat my words",
               "bar of soap"};
    */
    //phrases = {"a","b","a"};
    
    auto res = sol.beforeAndAfterPuzzles(phrases);
    copy(begin(res), end(res), ostream_iterator<string>(cout, "\n"));
    
    return 0;
}
