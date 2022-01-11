/*
1061. Lexicographically Smallest Equivalent String
Medium

Given strings s1 and s2 of the same length, we say s1[i] and s2[i] are equivalent characters. For example,
if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', 'c' == 'e'.

Equivalent characters follow the usual rules of any equivalence relation:
Reflexivity: 'a' == 'a'
Symmetry: 'a' == 'b' implies 'b' == 'a'
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'

For example, given the equivalency information from s1 and s2 above and baseStr = "eed", "acd" and "aab" are
equivalent strings of baseStr, and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

Example 1:

Input: s1 = "parker", s2 = "morris", baseStr = "parser"
Output: "makkek"
Explanation: Based on the equivalency information in s1 and s2, we can group their characters
as [m,p], [a,o], [k,r,s], [e,i]. The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".

Example 2:

Input: s1 = "hello", s2 = "world", baseStr = "hold"
Output: "hdld"
Explanation:  Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".

Example 3:
Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
Output: "aauaaaaada"
Explanation:  We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m],
thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".

Note:
Strings s1, s2, and baseStr consist of only lowercase English letters from 'a' - 'z'.
The lengths of string s1, s2, and baseStr are between 1 and 1000.
Strings s1 and s2 are of the same length.
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
#include "common/Node.h"
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:
    unordered_map<char, char> root;

    char get_root(char c) {
        root.emplace(c, c);
        char r = root[c];
        while (r != c) {
            c = r;
            r = root[r];
        }
        return r;
    }

    void join_root(char c, char r) {
        while (c != r) {
            char t = root[c];
            root[c] = r;
            c = t;
        }
    }

    string smallestEquivalentString(string a, string b, string s) {
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            char ca = a[i], cb = b[i];
            char ra = get_root(ca), rb = get_root(cb);
            if (ra < rb)
                join_root(cb, ra);
            else if (ra > rb)
                join_root (ca, rb);
        }

        for (char& c: s)
            c = get_root(c);
        return s;
    }
};

int main() {
    Solution sol;

    return 0;
}
