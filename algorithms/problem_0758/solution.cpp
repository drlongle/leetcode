/*
758. Bold Words in String
Easy

Given a set of keywords words and a string S, make all appearances of all keywords in S bold.
Any letters between <b> and </b> tags become bold.

The returned string should use the least number of tags possible, and of course the tags
should form a valid combination.

For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d".
Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Constraints:
words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.
Note: This question is the same as 616: https://leetcode.com/problems/add-bold-tag-in-string/
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

    void find(const string& needle, const string& s) {
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

    string boldWords(vector<string>& dict, const string& s) {
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
    return 0;
}
