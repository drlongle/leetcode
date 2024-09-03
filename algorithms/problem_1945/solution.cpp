/*
1945. Sum of Digits of String After Convert
Easy

You are given a string s consisting of lowercase English letters, and an integer
k.

First, convert s into an integer by replacing each letter with its position in
the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then,
transform the integer by replacing it with the sum of its digits. Repeat the
transform operation k times in total.

For example, if s = "zbax" and k = 2, then the resulting integer would be 8 by
the following operations:

Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
Transform #2: 17 ➝ 1 + 7 ➝ 8
Return the resulting integer after performing the operations described above.

Example 1:
Input: s = "iiii", k = 1
Output: 36
Explanation: The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.

Example 2:
Input: s = "leetcode", k = 2
Output: 6
Explanation: The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝
12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.

Example 3:
Input: s = "zbax", k = 2
Output: 8

Constraints:
1 <= s.length <= 100
1 <= k <= 10
s consists of lowercase English letters.
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
    string transform(string &s) {
        long long sum =
            std::accumulate(s.begin(), s.end(), 0,
                            [](int acc, char c) { return acc + c - '0'; });

        return to_string(sum);
    }

    int getLucky(string s, int k) {
        string st;
        for (char c : s) {
            st += std::to_string(c - 'a' + 1);
        }

        for (int i = 0; i < k; ++i)
            st = transform(st);

        return stoi(st);
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    s = "iiii", k = 1;
    cout << sol.getLucky(s, k) << endl;

    s = "leetcode", k = 2;
    cout << sol.getLucky(s, k) << endl;

    s = "zbax", k = 2;
    cout << sol.getLucky(s, k) << endl;

    return 0;
}
