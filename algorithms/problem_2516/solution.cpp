/*
2516. Take K of Each Character From Left and Right
Medium

You are given a string s consisting of the characters 'a', 'b', and 'c' and a
non-negative integer k. Each minute, you may take either the leftmost character
of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each
character, or return -1 if it is not possible to take k of each character.

Example 1:
Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation:
Take three characters from the left of s. You now have two 'a' characters, and
one 'b' character. Take five characters from the right of s. You now have four
'a' characters, two 'b' characters, and two 'c' characters. A total of 3 + 5 = 8
minutes is needed. It can be proven that 8 is the minimum number of minutes
needed.

Example 2:
Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.

Constraints:
1 <= s.length <= 10^5
s consists of only the letters 'a', 'b', and 'c'.
0 <= k <= s.length
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
    int takeCharacters(string s, int k) {
        array<unordered_map<int, int>, 3> lookup;
        array<int, 3> count{};
        int sz = s.size();

        for (int i = 0; i < sz; ++i) {
            char c = s[i];
            int index = c - 'a';
            ++count[index];
            lookup[index][count[index]] = i;
        }

        count = {};
        int res = std::numeric_limits<int>::max();
        for (int i = sz; i >= 0; --i) {
            if (i < sz) {
                char c = s[i];
                int index = c - 'a';
                ++count[index];
            }

            int offset = -1;
            bool valid = true;
            for (int j = 0; j < 3 && valid; ++j) {
                if (count[j] >= k)
                    continue;
                if (auto it = lookup[j].find(k - count[j]);
                    it != lookup[j].end()) {
                    if (it->second >= i) {
                        valid = false;
                    } else
                        offset = max(offset, it->second);
                } else
                    valid = false;
            }
            if (valid) {
                res = min(res, offset + 1 + (sz - i));
            }
        }

        return res == std::numeric_limits<int>::max() ? -1 : res;
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    s = "aabaaaacaabc", k = 2;
    cout << sol.takeCharacters(s, k) << endl;

    s = "a", k = 1;
    cout << sol.takeCharacters(s, k) << endl;

    return 0;
}
