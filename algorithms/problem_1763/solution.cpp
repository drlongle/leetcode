/*
1763. Longest Nice Substring
Easy

A string s is nice if, for every letter of the alphabet that s contains, it appears both in
uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear.
However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. If there are multiple,
return the substring of the earliest occurrence. If there are none, return an empty string.

Example 1:
Input: s = "YazaAay"
Output: "aAa"
Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s,
and both 'A' and 'a' appear. "aAa" is the longest nice substring.

Example 2:
Input: s = "Bb"
Output: "Bb"
Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.

Example 3:
Input: s = "c"
Output: ""
Explanation: There are no nice substrings.

Example 4:
Input: s = "dDzeE"
Output: "dD"
Explanation: Both "dD" and "eE" are the longest nice substrings.
As there are multiple longest nice substrings, return "dD" since it occurs earlier.

Constraints:
1 <= s.length <= 100
s consists of uppercase and lowercase English letters.
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

    bool is_nice(string& s, int begin, int end) {
        unordered_map<char, set<char>> table;
        for (int i = begin; i <= end; ++i) {
            char c = s[i];
            char key = isupper(c) ? tolower(c) : c;
            table[key].emplace(c);
        }

        for (auto& [k, v]: table) {
            if (v.size() == 1)
                return false;
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (is_nice(s, i, j) && j - i + 1 > res.size())
                    res = s.substr(i, j-i+1);
            }

        }
        return res;
    }
};

int main() {
    Solution sol;

    return 0;
}
