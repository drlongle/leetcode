/*
668. Kth Smallest Number in Multiplication Table
Hard

Nearly everyone has used the Multiplication Table. The multiplication table of
size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n
multiplication table.

Example 1:
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.

Example 2:
Input: m = 2, n = 3, k = 6
Output: 6
Explanation: The 6th smallest number is 6.

Constraints:
1 <= m, n <= 3 * 10^4
1 <= k <= m * n
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

struct Element {
    int index, diff;
    Element(int i, int d) : index(i), diff(d) {}
    int value() const { return index * diff; }
    bool operator<(const Element &other) const {
        return value() > other.value();
    }
};

class Solution {
  public:
    auto countSkips(int m, int n, int index) {
        priority_queue<Element> pq;
        int skips = 0;
        for (int64_t i = 1; i <= m; ++i) {
            int lo = 0, hi = index, v = 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (i * mid <= index) {
                    v = mid;
                    lo = mid + 1;
                } else
                    hi = mid - 1;
            }
            skips += min(v, n);
            if (v < n)
                pq.emplace(v + 1, i);
        }
        return make_pair(pq, skips);
    }

    int findKthNumber(int m, int n, int k) {
        priority_queue<Element> pq;
        int res, skips;
        int lo = 0, hi = k;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            auto t = countSkips(m, n, mid);
            if (t.second < k) {
                skips = t.second;
                pq = std::move(t.first);
                lo = mid + 1;
            } else
                hi = mid - 1;
        }

        for (int i = skips + 1; i <= k;) {
            auto elem = pq.top();
            res = elem.value();
            if (++elem.index <= n) {
                pq.emplace(elem);
            }
            pq.pop();
            if (res > 0)
                ++i;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int m, n, k;

    // Output: 3
    m = 3, n = 3, k = 5;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 6
    m = 2, n = 3, k = 6;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 40
    m = 10, n = 10, k = 70;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 48
    m = 10, n = 10, k = 77;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 90
    m = 10, n = 10, k = 99;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 6
    m = 45, n = 12, k = 11;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 6
    m = 45, n = 12, k = 12;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 6
    m = 45, n = 12, k = 14;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 7
    m = 45, n = 12, k = 16;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 312
    m = 45, n = 12, k = 471;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;

    // Output: 31666344
    m = 9895, n = 28405, k = 100787757;
    cout << "m: " << m << ", n: " << n << ", k: " << k
         << " , res:  " << sol.findKthNumber(m, n, k) << endl;
}
