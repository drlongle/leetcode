/*
672. Bulb Switcher II
Medium

There is a room with n bulbs labeled from 1 to n that all are turned on
initially, and four buttons on the wall. Each of the four buttons has a
different functionality where:

Button 1: Flips the status of all the bulbs.
Button 2: Flips the status of all the bulbs with even labels (i.e., 2, 4, ...).
Button 3: Flips the status of all the bulbs with odd labels (i.e., 1, 3, ...).
Button 4: Flips the status of all the bulbs with a label j = 3k + 1 where k = 0,
1, 2, ... (i.e., 1, 4, 7, 10, ...). You must make exactly presses button presses
in total. For each press, you may pick any of the four buttons to press.

Given the two integers n and presses, return the number of different possible
statuses after performing all presses button presses.

Example 1:
Input: n = 1, presses = 1
Output: 2
Explanation: Status can be:
- [off] by pressing button 1
- [on] by pressing button 2

Example 2:
Input: n = 2, presses = 1
Output: 3
Explanation: Status can be:
- [off, off] by pressing button 1
- [on, off] by pressing button 2
- [off, on] by pressing button 3

Example 3:
Input: n = 3, presses = 1
Output: 4
Explanation: Status can be:
- [off, off, off] by pressing button 1
- [off, on, off] by pressing button 2
- [on, off, on] by pressing button 3
- [off, on, on] by pressing button 4

Constraints:
1 <= n <= 1000
0 <= presses <= 1000
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
    unordered_set<string> flip(unordered_set<string> &in) {
        unordered_set<string> out;
        for (auto &s : in) {
            vector<string> ns(4, s);
            for (size_t i = 0, sz = s.size(); i < sz; ++i) {
                char c = s[i];
                char nc = (c == '1') ? '0' : '1';
                ns[0][i] = nc;
                if (i % 2 == 1)
                    ns[1][i] = nc;
                if (i % 2 == 0)
                    ns[2][i] = nc;
                if (i % 3 == 0)
                    ns[3][i] = nc;
            }
            for (auto &s : ns)
                out.insert(s);
        }

        return out;
    }

    int flipLights(int n, int presses) {
        // string s(n, '1');
        string s(min(3, n), '1');
        unordered_set<string> in{s};
        for (int i = 0; i < presses; ++i) {
            in = flip(in);
        }

        return in.size();
    }
};

int main() {
    Solution sol;
    int n, presses;

    // Output: 2
    n = 1, presses = 1;
    cout << "n: " << n << ", presses: " << presses
         << ", : " << sol.flipLights(n, presses) << endl;

    // Output: 3
    n = 2, presses = 1;
    cout << "n: " << n << ", presses: " << presses
         << ", : " << sol.flipLights(n, presses) << endl;

    // Output: 4
    n = 3, presses = 1;
    cout << "n: " << n << ", presses: " << presses
         << ", : " << sol.flipLights(n, presses) << endl;

    // Output: 7
    n = 3, presses = 2;
    cout << "n: " << n << ", presses: " << presses
         << ", : " << sol.flipLights(n, presses) << endl;

    // Output: 4
    n = 4, presses = 1;
    cout << "n: " << n << ", presses: " << presses
         << ", : " << sol.flipLights(n, presses) << endl;

    // Output: 7
    n = 4, presses = 2;
    cout << "n: " << n << ", presses: " << presses
         << ", : " << sol.flipLights(n, presses) << endl;
}
