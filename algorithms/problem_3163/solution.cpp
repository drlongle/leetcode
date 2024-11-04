/*
3163. String Compression III
Medium

Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following
operation: Remove a maximum length prefix of word made of a single character c
repeating at most 9 times. Append the length of the prefix followed by c to
comp. Return the string comp.

Example 1:
Input: word = "abcde"
Output: "1a1b1c1d1e"
Explanation:
Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d",
and "e" as the prefix in each operation. For each prefix, append "1" followed by
the character to comp.

Example 2:
Input: word = "aaaaaaaaaaaaaabb"
Output: "9a5a2b"
Explanation:
Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa",
"aaaaa", and "bb" as the prefix in each operation. For prefix "aaaaaaaaa",
append "9" followed by "a" to comp. For prefix "aaaaa", append "5" followed by
"a" to comp. For prefix "bb", append "2" followed by "b" to comp.

Constraints:
1 <= word.length <= 2 * 10^5
word consists only of lowercase English letters.
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
    string compressedString(string word) {
        ostringstream oss;
        if (word.empty())
            return "";
        char prev = ' ';
        int cnt = 0;
        constexpr int max_cnt = 9;
        for (char c : word) {
            if ((cnt > 0 && prev != c) || cnt == max_cnt) {
                oss << cnt << prev;
                cnt = 0;
            }
            ++cnt;
            prev = c;
        }

        if (cnt > 0)
            oss << cnt << prev;
        return oss.str();
    }
};

int main() {
    Solution sol;
    string word;

    word = "abcde";
    cout << sol.compressedString(word) << endl;

    word = "aaaaaaaaaaaaaabb";
    cout << sol.compressedString(word) << endl;

    return 0;
}
