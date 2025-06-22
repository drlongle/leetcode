/*
3325. Count Substrings With K-Frequency Characters I
Medium

Given a string s and an integer k, return the total number of substrings of s where
at least one character appears at least k times.

Example 1:
Input: s = "abacb", k = 2
Output: 4
Explanation:
The valid substrings are:
"aba" (character 'a' appears 2 times).
"abac" (character 'a' appears 2 times).
"abacb" (character 'a' appears 2 times).
"bacb" (character 'b' appears 2 times).

Example 2:
Input: s = "abcde", k = 1
Output: 15
Explanation:
All substrings are valid because every character appears at least once.

Constraints:
1 <= s.length <= 3000
1 <= k <= s.length
s consists only of lowercase English letters.
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
    int numberOfSubstrings(string s, int k) {
        int res = 0, sz = s.size();
        for (int i = 0 ; i < sz; ++i ) {
            array<int, 26> cnt{};
            int c = 0;
            for (int j = i; j < sz; ++j) {
                c = max(c, ++cnt[s[j]-'a']);
                if (c >= k) {
                    res += sz - j;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    s = "abacb", k = 2;
    cout << sol.numberOfSubstrings(s, k) << endl;

    s = "abcde", k = 1;
    cout << sol.numberOfSubstrings(s, k) << endl;

    return 0;
}
