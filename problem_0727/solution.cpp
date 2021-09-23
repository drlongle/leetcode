/*
727. Minimum Window Subsequence
Hard

Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.

If there is no such window in s1 that covers all characters in s2, return the empty string "". If there
are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:
Input: s1 = "abcdebdde", s2 = "bde"
Output: "bcde"
Explanation:
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of s2 in the window must occur in order.

Example 2:
Input: s1 = "jmeqksfrsdcmsiwvaovztaqenprpvnbstl", s2 = "u"
Output: ""

Constraints:
1 <= s1.length <= 2 * 10^4
1 <= s2.length <= 100
s1 and s2 consist of lowercase English letters.
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

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<ll>;
using vll = vector<vector<ll>>;

class Solution {
public:
    string minWindow(string s1, string s2) {
        vector<set<int>> pos(26);
        int sz1 = s1.size(), sz2 = s2.size();
        pair<int, int> res{-1, -1};

        for (int i = 0; i < sz1; ++i) {
            pos[s1[i] - 'a'].insert(i);
        }

        for (int i: pos[s2[0] - 'a']) {
            int k = i;
            bool found = true;
            for (int j = 1; found && j < sz2; ++j) {
                auto it = pos[s2[j] - 'a'].upper_bound(k);
                if (it == pos[s2[j] - 'a'].end())
                    found = false;
                else
                    k = *it;
            }
            if (found && (res.first < 0 || res.second - res.first > k - i))
                res = make_pair(i, k);
        }

        return res.first < 0 ? "" : s1.substr(res.first, res.second - res.first + 1);
    }
};

int main() {
    Solution sol;

    return 0;
}
