/*
753. Cracking the Safe
Hard

https://leetcode.com/problems/cracking-the-safe/

There is a safe protected by a password. The password is a sequence of n digits
where each digit can be in the range [0, k - 1].

The safe has a peculiar way of checking the password. When you enter in a
sequence, it checks the most recent n digits that were entered each time you
type a digit.

For example, the correct password is "345" and you enter in "012345":
After typing 0, the most recent 3 digits is "0", which is incorrect.
After typing 1, the most recent 3 digits is "01", which is incorrect.
After typing 2, the most recent 3 digits is "012", which is incorrect.
After typing 3, the most recent 3 digits is "123", which is incorrect.
After typing 4, the most recent 3 digits is "234", which is incorrect.
After typing 5, the most recent 3 digits is "345", which is correct and the safe
unlocks. Return any string of minimum length that will unlock the safe at some
point of entering it.

Example 1:
Input: n = 1, k = 2
Output: "10"
Explanation: The password is a single digit, so enter each digit. "01" would
also unlock the safe.

Example 2:
Input: n = 2, k = 2
Output: "01100"
Explanation: For each possible password:
- "00" is typed in starting from the 4th digit.
- "01" is typed in starting from the 1st digit.
- "10" is typed in starting from the 3rd digit.
- "11" is typed in starting from the 2nd digit.
Thus "01100" will unlock the safe. "10011", and "11001" would also unlock the
safe.

Constraints:
1 <= n <= 4
1 <= k <= 10
1 <= k^n <= 4096
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
    string res;

    void solve(string &curr, size_t n, size_t k, unordered_set<string> &seen) {
        if (!res.empty())
            return;
        if (seen.size() == pow(k, n)) {
            if (res.empty() || res.size() > curr.size())
                res = curr;
            return;
        }

        string s;
        if (curr.size() >= n - 1) {
            s = curr.substr(curr.size() - n + 1, n - 1);
        }
        s.push_back('0');
        curr.push_back('0');
        for (size_t i = 0; i < k; ++i) {
            s.back() = '0' + i;
            if (s.size() == n && !seen.insert(s).second)
                continue;

            curr.back() = '0' + i;
            solve(curr, n, k, seen);
            seen.erase(s);
        }
        curr.pop_back();
        s.pop_back();
    }

    string crackSafe(int n, int k) {
        unordered_set<string> seen;
        string s;
        solve(s, n, k, seen);
        return res;
    }
};

int main() {
    Solution sol;
    int n, k;

    n = 1, k = 2;
    // cout << sol.crackSafe(n, k) << endl;

    n = 2, k = 2;
    // cout << sol.crackSafe(n, k) << endl;

    n = 1, k = 10;
    cout << sol.crackSafe(n, k) << endl;

    return 0;
}
