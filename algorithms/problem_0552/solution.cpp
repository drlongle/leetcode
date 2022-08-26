/*
552. Student Attendance Record II
Hard

An attendance record for a student can be represented as a string where each
character signifies whether the student was absent, late, or present on that
day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the
following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n
that make a student eligible for an attendance award. The answer may be very
large, so return it modulo 10^9 + 7.


Example 1:
Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer
than 2).

Example 2:
Input: n = 1
Output: 3

Example 3:
Input: n = 10101
Output: 183236316

Constraints:
1 <= n <= 10^5

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

static constexpr int64_t MOD = 1000'000'007;

struct Record {
    Record(int l_, int ll_, int other_) : l(l_), ll(ll_), other(other_) {}

    int64_t l;     // *L
    int64_t ll;    // *LL
    int64_t other; // *P and *A

    void next() {
        auto nl = other; // The next day is a late day
        auto nll = l;    // The next day is another late day
        auto nother = (l + ll + other) % MOD; // The next day is a present day

        l = nl;
        ll = nll;
        other = nother;
    };

    int sum() { return (l + ll + other) % MOD; }
};

class Solution {
  public:
    int checkRecord(int n) {
        if (n == 1)
            return 3;
        Record na_rec(1, 1, 2); // Record for students without an absent day
        Record a_rec(1, 0, 3);  // Record for students with an absent day

        for (int i = 2; i < n; ++i) {
            int s = na_rec.sum();
            na_rec.next(), a_rec.next();
            a_rec.other = (a_rec.other + s) % MOD;
        }

        return (na_rec.sum() + a_rec.sum()) % MOD;
    }
};

int main() {
    Solution sol;
    int n;

    n = 2;
    cout << n << " -> " << sol.checkRecord(n) << endl;

    // 18
    n = 3;
    cout << n << " -> " << sol.checkRecord(n) << endl;

    // 43
    n = 4;
    cout << n << " -> " << sol.checkRecord(n) << endl;

    // 94
    n = 5;
    cout << n << " -> " << sol.checkRecord(n) << endl;

    // 3536
    n = 10;
    cout << n << " -> " << sol.checkRecord(n) << endl;

    // 2947811
    n = 20;
    cout << n << " -> " << sol.checkRecord(n) << endl;

    // 183236316
    n = 10101;
    n = 10;
    cout << n << " -> " << sol.checkRecord(n) << endl;
}
