/*
1639. Number of Ways to Form a Target String Given a Dictionary
Hard

You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:

target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth
character of the jth string in words if target[i] = words[j][k]. Once you use
the kth character of the jth string of words, you can no longer use the xth
character of any string in words where x <= k. In other words, all characters to
the left of or at index k become unusuable for every string. Repeat the process
until you form the string target. Notice that you can use multiple characters
from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too
large, return it modulo 10^9 + 7.

Example 1:
Input: words = ["acca","bbbb","caca"], target = "aba"
Output: 6
Explanation: There are 6 ways to form target.
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")

Example 2:
Input: words = ["abba","baab"], target = "bab"
Output: 4
Explanation: There are 4 ways to form target.
"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")

Constraints:
1 <= words.length <= 1000
1 <= words[i].length <= 1000
All strings in words have the same length.
1 <= target.length <= 1000
words[i] and target contain only lowercase English letters.
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
    static constexpr long long MOD = 1'000'000'007ull;
    vector<array<int, 26>> chars;
    vector<vector<long long>> dp;
    int m, n;

    long long find(string &target, int i, int j) {
        if (j >= n || m - i > n - j)
            return 0;

        auto &res = dp[i][j];
        if (res >= 0)
            return res;
        res = 0;

        char ch = target[i];
        if (i == m - 1) {
            for (int k = j; k < n; ++k) {
                res = (res + chars[k][ch - 'a']) % MOD;
            }
            return res;
        }

        for (int k = j; k < n; ++k) {
            int cnt = chars[k][ch - 'a'];
            if (cnt == 0)
                continue;
            res = (res + cnt * find(target, i + 1, k + 1)) % MOD;
        }

        return res;
    }

    int numWays(vector<string> &words, string target) {
        m = target.size(), n = words[0].size();
        dp.resize(m, vector<long long>(n, -1));
        chars.resize(n, array<int, 26>());

        for (auto &w : words) {
            for (int i = 0; i < n; ++i) {
                chars[i][w[i] - 'a'] += 1;
            }
        }

        return find(target, 0, 0) % MOD;
    }
};

int main() {

    vector<string> words;
    string target;

    {
        Solution sol;
        words = {"acca", "bbbb", "caca"}, target = "aba";
        cout << sol.numWays(words, target) << endl;
    }

    {
        Solution sol;
        words = {"abba", "baab"}, target = "bab";
        cout << sol.numWays(words, target) << endl;
    }

    {
        Solution sol;
        words = {"abab", "baba", "abba", "baab"};
        target = "abba";
        cout << sol.numWays(words, target) << endl;
    }

    return 0;
}
