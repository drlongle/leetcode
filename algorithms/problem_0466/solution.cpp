/*
466. Count The Repetitions
Hard

We define str = [s, n] as the string str which consists of the string s
concatenated n times.

For example, str == ["abc", 3] =="abcabcabc".
We define that string s1 can be obtained from string s2 if we can remove some
characters from s2 such that it becomes s1.

For example, s1 = "abc" can be obtained from s2 = "abdbec" based on our
definition by removing the bolded underlined characters. You are given two
strings s1 and s2 and two integers n1 and n2. You have the two strings str1 =
[s1, n1] and str2 = [s2, n2].

Return the maximum integer m such that str = [str2, m] can be obtained from
str1.

Example 1:
Input: s1 = "acb", n1 = 4, s2 = "ab", n2 = 2
Output: 2

Example 2:
Input: s1 = "acb", n1 = 1, s2 = "acb", n2 = 1
Output: 1

Constraints:
1 <= s1.length, s2.length <= 100
s1 and s2 consist of lowercase English letters.
1 <= n1, n2 <= 10^6
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
    vector<vector<int>> lookup;
    vector<pair<int, int>> jump_table;
    int sz1;

    pair<int, int> jump(string &s2, int i1) {
        auto &r = jump_table[i1];
        if (r.first >= 0)
            return r;
        int count = 0;
        for (int i2 = 0, sz2 = s2.size(); i2 < sz2; ++i2) {
            auto &indices = lookup[s2[i2] - 'a'];
            if (indices.empty())
                return {-1, -1};
            auto it = lower_bound(indices.begin(), indices.end(), i1);
            if (it != indices.end())
                i1 = *it + 1;
            else {
                ++count;
                it = lower_bound(indices.begin(), indices.end(), 0);
                i1 = *it + 1;
            }
        }

        r.first = count;
        r.second = i1;
        return r;
    }

    bool check(string &s2, int n1, int n2, int count) {
        int i1 = 0, wraps = 0;
        while (count-- > 0) {
            for (int k = 0; k < n2; ++k) {
                auto r = jump(s2, i1);
                if (r.first < 0)
                    return false;
                wraps += r.first;
                if (wraps >= n1)
                    return false;
                i1 = r.second;
            }
        }

        return true;
    }

    int sanity(string &s2) {
        int i1 = 0, i2 = 0, sz2 = s2.size(), cnt = 0;
        while (true) {
            auto &indices = lookup[s2[i2] - 'a'];
            if (indices.empty())
                return -1;

            auto it = lower_bound(indices.begin(), indices.end(), i1);
            if (it != indices.end())
                i1 = *it + 1;
            else {
                break;
            }
            if (++i2 == sz2) {
                i2 = 0;
                ++cnt;
            }
        }
        return i2 == 0 ? cnt : 0;
    }

    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        lookup.assign(26, vector<int>());
        sz1 = s1.size();
        jump_table.assign(s1.size() + 1, {-1, -1});
        for (int i = 0, n = sz1; i < n; ++i) {
            lookup[s1[i] - 'a'].push_back(i);
        }

        int cnt = sanity(s2);
        if (cnt < 0)
            return 0;
        if (cnt > 0)
            return cnt * n1 / n2;
        int lo = 1, hi = sz1 * n1 / (s2.size() * n2);
        int res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(s2, n1, n2, mid)) {
                res = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    string s1, s2;
    int n1, n2;

    // Output: 2
    s1 = "acb", n1 = 4, s2 = "ab", n2 = 2;
    // cout << sol.getMaxRepetitions(s1, n1, s2, n2) << endl;

    // Output: 1
    s1 = "acb", n1 = 1, s2 = "acb", n2 = 1;
    // cout << sol.getMaxRepetitions(s1, n1, s2, n2) << endl;

    // Output: 7
    s1 = "baba";
    n1 = 11;
    s2 = "baab";
    n2 = 1;
    // cout << sol.getMaxRepetitions(s1, n1, s2, n2) << endl;

    // Output: 0
    s1 = "phqghumeay";
    n1 = 100;
    s2 = "lnl";
    n2 = 1;
    cout << sol.getMaxRepetitions(s1, n1, s2, n2) << endl;

    // Output: 10000
    s1 = "phqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozvsrtkjpre";
    n1 = 1000000;
    s2 = "pggxr";
    n2 = 100;
    cout << sol.getMaxRepetitions(s1, n1, s2, n2) << endl;

    // Output: 100
    s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    n1 = 1000000;
    s2 = "a";
    n2 = 1000000;
    cout << sol.getMaxRepetitions(s1, n1, s2, n2) << endl;

    // Output: 1
    s1 = "adasfdgdftadwfwfereredsfssas";
    n1 = 500;
    s2 = "fw";
    n2 = 555;
    cout << sol.getMaxRepetitions(s1, n1, s2, n2) << endl;

    return 0;
}
