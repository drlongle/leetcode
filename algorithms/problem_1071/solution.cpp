/*
1071. Greatest Common Divisor of Strings
Easy

For two strings s and t, we say "t divides s" if and only if s = t + ... + t
(i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides
both str1 and str2.

Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Example 3:
Input: str1 = "LEET", str2 = "CODE"
Output: ""

Constraints:
1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
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

#include "common/FenwickTree.h"
#include "common/ListNode.h"
#include "common/Node.h"
#include "common/SegmentTree.h"
#include "common/TreeNode.h"
#include "common/UnionFind.h"
#include "common/bits.h"

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
  public:
    set<string> substr(string &s) {
        set<string> res;
        for (int len = 1, sz = s.size(); len <= sz / 2; ++len) {
            bool flag = true;
            string sub = s.substr(0, len);
            for (int i = 0; i < sz && flag; i += len) {
                if (s.compare(i, len, sub))
                    flag = false;
            }
            if (flag)
                res.insert(sub);
        }
        res.insert(s);
        return res;
    }

    string gcdOfStrings(string str1, string str2) {
        set<string> subs1 = substr(str1);
        set<string> subs2 = substr(str2);
        string res;
        for (auto &a : subs1) {
            if (subs2.count(a)) {
                if (a.size() > res.size())
                    res = a;
            }
        }
        return res;
    }
};

int main() { return 0; }
