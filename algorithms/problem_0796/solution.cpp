/*
796. Rotate String
Easy

Given two strings s and goal, return true if and only if s can become goal after
some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost
position.

For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false

Constraints:
1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.
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
    void shift(string &s, int i) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + i);
        reverse(begin(s) + i, end(s));
    }
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        for (int i = 1, sz = s.size(); i < sz; ++i) {
            string t = goal;
            shift(t, i);
            if (s == t)
                return true;
        }
        return s == goal;
    }
};

int main() {
    Solution sol;

    return 0;
}
