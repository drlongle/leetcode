/*
884. Uncommon Words from Two Sentences
Easy

A sentence is a string of single-space separated words where each word consists
only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does
not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may
return the answer in any order.

Example 1:
Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
Explanation:
The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:
Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]

Constraints:
1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.
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

#include "../common/FenwickTree.h"
#include "../common/ListNode.h"
#include "../common/Node.h"
#include "../common/SegmentTree.h"
#include "../common/TreeNode.h"
#include "../common/UnionFind.h"
#include "../common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    vector<string> split(const string &s) {
        vector<string> res;
        int index = 0;
        while (true) {
            auto new_index = s.find(' ', index);
            if (new_index != string::npos) {
                res.emplace_back(s.substr(index, new_index - index));
                index = new_index + 1;
            } else {
                res.emplace_back(s.substr(index));
                break;
            }
        }
        return res;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        auto r1 = split(s1);
        auto r2 = split(s2);
        map<string, int> cnt;
        for (auto &s : r1) {
            ++cnt[s];
        }

        for (auto &s : r2) {
            ++cnt[s];
        }
        for (auto &[k, v] : cnt) {
            if (v == 1)
                res.emplace_back(k);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> res;
    string s1, s2;

    s1 = "this apple is sweet", s2 = "this apple is sour";
    res = sol.uncommonFromSentences(s1, s2);
    for (auto &s : res)
        cout << s;
    cout << endl;

    s1 = "apple apple", s2 = "banana";
    res = sol.uncommonFromSentences(s1, s2);
    for (auto &s : res)
        cout << s;
    cout << endl;

    return 0;
}
