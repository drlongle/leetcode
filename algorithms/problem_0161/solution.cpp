/*
161. One Edit Distance
Medium

Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.

Example 1:
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Example 2:
Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.

Example 3:
Input: s = "a", t = ""
Output: true

Example 4:
Input: s = "", t = "A"
Output: true

Constraints:
0 <= s.length <= 10^4
0 <= t.length <= 10^4
s and t consist of lower-case letters, upper-case letters and/or digits.
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
    bool isOneEditDistance(string s, string t) {
        if (s.size() > t.size())
            swap(s, t);
        if (t.size() > s.size() + 1)
            return false;
        if (s.size() == t.size()) {
            int cnt = 0;
            for (size_t i = 0; i < s.size() && cnt <= 1; ++i) {
                cnt += s[i] != t[i] ? 1 : 0;
            }
            return cnt == 1;
        } else {
            int cnt = 0;
            size_t i, j;
            for (i = 0, j = 0; i < s.size() && cnt <= 1;) {
                if (s[i] == t[j])
                    ++i, ++j;
                else {
                    ++cnt;
                    ++j;
                }
            }
            return cnt == 1 || i == s.size();
        }
    }
};

int main() {
    Solution sol;
    string s, t;

    // Output: true
    s = "ab", t = "acb";
    cout << boolalpha << sol.isOneEditDistance(s, t) << endl;

    // Output: false
    s = "", t = "";
    cout << boolalpha << sol.isOneEditDistance(s, t) << endl;

    // Output: true
    s = "a", t = "";
    cout << boolalpha << sol.isOneEditDistance(s, t) << endl;

    // Output: true
    s = "", t = "A";
    cout << boolalpha << sol.isOneEditDistance(s, t) << endl;

    return 0;
}
