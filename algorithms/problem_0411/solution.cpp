/*
411. Minimum Unique Word Abbreviation

A string such as "word" contains the following abbreviations:

["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Given a target string and a set of strings in a dictionary, find an abbreviation of this target string with the
smallest possible length such that it does not conflict with abbreviations of the strings in the dictionary.

Each number or letter in the abbreviation is considered length = 1. For example, the abbreviation "a32bc"
has length = 4.

Examples:

"apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")

"apple", ["plain", "amber", "blade"] -> "1p3"
(other valid answers include "ap3", "a3e", "2p2", "3le", "3l1").


Constraints:
In the case of multiple answers as shown in the second example below, you may return any one of them.
Assume length of target string = m, and dictionary size = n. You may assume that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
 */

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#define ll long long int
#define ull unsigned long long int

using namespace std;

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dict) {
        string res = target;
        int wlen = target.size(), len = target.size();
        vector<unordered_map<char, set<int>>> table(len);
        bool empty = true;
        for (int j = 0, dsz = dict.size(); j < dsz; ++j) {
            string& s = dict[j];
            if (s.size() != wlen)
                continue;
            empty = false;
            for (int i = 0; i < wlen; ++i) {
                table[i][s[i]].emplace(j);
            }
        }
        if (empty)
            return to_string(wlen);

        ostringstream oss;
        for (int i = 0; i < wlen; ++i) {
            if (!table[i].count(target[i])) {
                if (i == 0)
                    return target[0] + (wlen > 1 ? to_string(wlen - 1) : "");
                if (i == wlen - 1)
                    return (wlen > 1 ? to_string(wlen - 1) : "") + target[i];
                else {
                    if (len > 3) {
                        len = 3;
                        res = to_string(i) + target[i] + to_string(wlen - 1 - i);
                    }
                }
            }

            auto& set_i = table[i][target[i]];
            for (int j = i+1; j < wlen; ++j) {
                vector<int> v_intersect;
                if (!table[j].count(target[j]))
                    continue;
                set_intersection(set_i.begin(), set_i.end(),
                                 table[j][target[j]].begin(), table[j][target[j]].end(),
                                 back_inserter(v_intersect));
                if (v_intersect.empty()) {
                    oss.str("");
                    int nlen = 0;
                    if (i > 0) {
                        oss << i;
                        ++nlen;
                    }
                    oss << target[i];
                    ++nlen;

                    if (j - i > 1) {
                        oss << j - i -1;
                        ++nlen;
                    }

                    oss << target[j];
                    ++nlen;

                    if (j < wlen - 1) {
                        oss << wlen - 1 -j;
                        ++nlen;
                    }
                    if (nlen < len) {
                        len = nlen;
                        res = oss.str();
                    }
                }
            }
        }

        for (int i = 0; i < wlen; ++i) {
            for (int j = i; j < wlen; ++j) {
                bool matched = false;
                for (auto& w: dict)  {
                    if (w.size() != wlen)
                        continue;
                    if (w.compare(i, j - i + 1, target, i, j - i + 1) == 0) {
                        matched = true;
                        break;
                    }
                }

                if (!matched) {
                    oss.str("");
                    int nlen = 0;
                    if (i > 0) {
                        oss << i;
                        ++nlen;
                    }
                    oss << target.substr(i, j - i + 1);
                    nlen += j - i + 1;

                    if (j < wlen - 1) {
                        oss << wlen - 1 -j;
                        ++nlen;
                    }
                    if (nlen < len) {
                        len = nlen;
                        res = oss.str();
                    }
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> dict;
    string target;

    // "a4"
    target = "apple", dict = {"blade"};
    cout << sol.minAbbreviation(target, dict) << endl;

    // "1p3" (other valid answers include "ap3", "a3e", "2p2", "3le", "3l1")
    target = "apple", dict = {"plain", "amber", "blade"};
    cout << sol.minAbbreviation(target, dict) << endl;

    // "2bad2"
    target = "aabadaa", dict = {"aabaxaa","aaxadaa"};
    cout << sol.minAbbreviation(target, dict) << endl;

    // "2r2"
    target = "world", dict = {"hello","would","lord","hell","language"};
    cout << sol.minAbbreviation(target, dict) << endl;

    // "abc"
    target = "abc", dict = {"abd","acd","acc"};
    cout << sol.minAbbreviation(target, dict) << endl;


    // "5othree"
    target = "onetwothree";
    dict = {"onetwothkke","onetwothbbe","onetwoghree","onetwoteree","onetwothrae","onetwotaree","onetwofhree","onetwathree","onetwothrle"};
    cout << sol.minAbbreviation(target, dict) << endl;

    return 0;
}

