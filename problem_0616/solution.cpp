/*
616. Add Bold Tag in String
Medium

Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b>
to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them
together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are
consecutive, you need to combine them.

Example 1:
Input:
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"

Example 2:
Input:
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"

Constraints:
The given dict won't contain duplicates, and its length won't exceed 100.
All the strings in input have length in range [1, 1000].
Note: This question is the same as 758: https://leetcode.com/problems/bold-words-in-string/
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

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    vector<pair<int, int>> occurs;
    static constexpr int hash = 997;

    void find(string& needle, string& s) {
        int sz = needle.size();
        int n = s.size();
        int nsum = 0;
        for (char c: needle) {
            nsum = (nsum * 10 + c - '0') % hash;
        }

        int mult = 1;
        for (int i = 0; i < sz-1; ++i)
            mult = mult * 10 % hash;

        for (int i = 0, sum = 0; i < n; ++i) {
            sum = (sum * 10 + s[i] - '0') % hash;
            if (i >= sz - 1) {
                if (sum == nsum && s.compare(i-sz+1, sz, needle) == 0) {
                    occurs.emplace_back(i-sz+1, -1);
                    occurs.emplace_back(i, 1);
                }
                sum = (sum - (s[i-sz+1] - '0') * mult) % hash;
                if (sum < 0)
                    sum += hash;
            }
        }

    }

    string addBoldTag(string s, vector<string>& dict) {
        occurs.clear();
        for (auto& d: dict)
            find(d, s);
        sort(begin(occurs), end(occurs));
        string res;
        int sum = 0;
        for (int i = 0, j = 0, sz = s.size(), n = occurs.size(); i < sz; ++i) {
            if (sum == 0 && j < n && occurs[j].first == i) {
                if (res.size() >= 4 && res[res.size()-3] == '/') {
                    for (int i = 0; i < 4; ++i)
                        res.pop_back();
                } else
                    res += "<b>";
            }
            res += s[i];
            bool changed = false;
            while (j < n && occurs[j].first == i) {
                sum += occurs[j].second;
                ++j;
                changed = true;
            }
            if (sum == 0 && changed)
                res += "</b>";
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s;
    vector<string> dict;

    s = "abcxyz123";
    dict = {"abc","123"};
    cout << sol.addBoldTag(s, dict) << endl;

    s = "aaabbcc";
    dict = {"aaa","aab","bc"};
    cout << sol.addBoldTag(s, dict) << endl;

    return 0;
}
