/*
482. License Key Formatting
Easy

You are given a license key represented as a string s that consists of only
alphanumeric characters and dashes. The string is separated into n + 1 groups by
n dashes. You are also given an integer k.

We want to reformat the string s such that each group contains exactly k
characters, except for the first group, which could be shorter than k but still
must contain at least one character. Furthermore, there must be a dash inserted
between two groups, and you should convert all lowercase letters to uppercase.

Return the reformatted license key.

Example 1:
Input: s = "5F3Z-2e-9-w", k = 4
Output: "5F3Z-2E9W"
Explanation: The string s has been split into two parts, each part has 4
characters. Note that the two extra dashes are not needed and can be removed.

Example 2:
Input: s = "2-5g-3-J", k = 2
Output: "2-5G-3J"
Explanation: The string s has been split into three parts, each part has 2
characters except the first part as it could be shorter as mentioned above.

Constraints:
1 <= s.length <= 10^5
s consists of English letters, digits, and dashes '-'.
1 <= k <= 10^4
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
    string licenseKeyFormatting(string s, int k) {
        string r;
        for (char ch : s) {
            if (ch != '-')
                r.push_back(toupper(ch));
        }

        ostringstream oss;
        for (int i = 0, sz = r.size(), len; i < sz; i += len) {
            if (i != 0) {
                oss << '-';
                len = k;
            } else {
                len = sz % k;
                if (len == 0)
                    len = k;
            }
            oss << r.substr(i, len);
        }

        return oss.str();
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    // Expected: "5F3Z-2E9W"
    s = "5F3Z-2e-9-w", k = 4;
    cout << "res: " << sol.licenseKeyFormatting(s, k) << endl;

    // Expected: "2-5G-3J"
    s = "2-5g-3-J", k = 2;
    cout << "res: " << sol.licenseKeyFormatting(s, k) << endl;

    return 0;
}
