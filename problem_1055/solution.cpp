/*
1055. Shortest Way to Form String
Medium

From any string, we can form a subsequence of that string by deleting some number of characters
(possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that
their concatenation equals target. If the task is impossible, return -1.

Example 1:
Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".

Example 2:
Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due
to the character "d" in target string.

Example 3:
Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".

Constraints:
Both the source and target strings consist of only lowercase English letters from "a"-"z".
The lengths of source and target string are between 1 and 1000.
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
    int shortestWay(string source, string target) {
        vector<set<int>> table(26);
        for (int i = 0, sz = source.size(); i < sz; ++i) {
            table[source[i] - 'a'].emplace(i);
        }
        int cnt = 1, index = -1;
        for (char c: target) {
            auto& s = table[c - 'a'];
            if (s.empty())
                return -1;
            auto it = s.upper_bound(index);
            if (it == s.end()) {
                ++cnt;
                it = s.upper_bound(-1);
            }
            index = *it;
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    string source, target;

    // Output: 2
    source = "abc", target = "abcbc";
    cout << sol.shortestWay(source, target) << endl;

    // Output: -1
    source = "abc", target = "acdbc";
    cout << sol.shortestWay(source, target) << endl;

    // Output: 3
    source = "xyz", target = "xzyxz";
    cout << sol.shortestWay(source, target) << endl;

    return 0;
}
