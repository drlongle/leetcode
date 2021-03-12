/*
291. Word Pattern II
Medium

Given a pattern and a string s, return true if s matches the pattern.

A string s matches a pattern if there is some bijective mapping of single characters to strings
such that if each character in pattern is replaced by the string it maps to, then the resulting
string is s. A bijective mapping means that no two characters map to the same string, and no
character maps to two different strings.

Example 1:
Input: pattern = "abab", s = "redblueredblue"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "red"
'b' -> "blue"

Example 2:
Input: pattern = "aaaa", s = "asdasdasdasd"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "asd"

Example 3:
Input: pattern = "abab", s = "asdasdasdasd"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "a"
'b' -> "sdasd"
Note that 'a' and 'b' cannot both map to "asd" since the mapping is a bijection.

Example 4:
Input: pattern = "aabb", s = "xyzabcxzyabc"
Output: false

Constraints:
1 <= pattern.length, s.length <= 20
pattern and s consist of only lower-case English letters.
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

    unordered_map<char, string> cs;
    unordered_map<string, char> sc;

    bool check(string& p, string &s, int i, int j) {
        if (i == p.size() && j == s.size())
            return true;
        if (i == p.size() || j == s.size())
            return false;
        char c = p[i];
        auto it = cs.find(c);
        if (it != cs.end()) {
            if (it->second == s.substr(j, it->second.size()))
                return check (p, s, i+1, j + it->second.size());
            else
                return false;
        }
        for (int k = j; k < s.size(); ++k) {
            string su = s.substr (j, k-j+1);
            if (sc.count(su))
                continue;
            cs[c] = su;
            sc[su] = c;
            if (check(p, s, i+1, k+1))
                return true;
            cs.erase(c);
            sc.erase(su);
        }
        return false;
    }

    bool wordPatternMatch(string p, string s) {
        return check(p, s, 0, 0);
    }
};

int main() {
    Solution sol;

    return 0;
}
