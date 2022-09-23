/*
788. Rotated Digits
Medium

An integer x is a good if after rotating each digit individually by 180 degrees,
we get a valid number that is different from x. Each digit must be rotated - we
cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different
direction, in other words, 2 or 5 gets mirrored), 6 and 9 rotate to each other,
and the rest of the numbers do not rotate to any other number and become
invalid. Given an integer n, return the number of good integers in the range [1,
n].

Example 1:
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after
rotating.

Example 2:
Input: n = 1
Output: 0

Example 3:
Input: n = 2
Output: 1

Constraints:
1 <= n <= 10^4
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
    map<char, char> m{{'0', '0'}, {'1', '1'}, {'8', '8'}, {'2', '5'},
                      {'5', '2'}, {'6', '9'}, {'9', '6'}};

    bool isGood(string s) {
        string t;
        for (char c : s) {
            auto it = m.find(c);
            if (it == m.end())
                return false;
            t.push_back(it->second);
        }
        return s != t;
    }

    int rotatedDigits(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res += isGood(to_string(i));
        return res;
    }
};

int main() { return 0; }
