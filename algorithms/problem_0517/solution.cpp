/*
517. Super Washing Machines
Hard

You have n super washing machines on a line. Initially, each washing machine has
some dresses or is empty.

For each move, you could choose any m (1 <= m <= n) washing machines, and pass
one dress of each washing machine to one of its adjacent washing machines at the
same time.

Given an integer array machines representing the number of dresses in each
washing machine from left to right on the line, return the minimum number of
moves to make all the washing machines have the same number of dresses. If it is
not possible to do it, return -1.

Example 1:
Input: machines = [1,0,5]
Output: 3
Explanation:
1st move:    1     0 <-- 5    =>    1     1     4
2nd move:    1 <-- 1 <-- 4    =>    2     1     3
3rd move:    2     1 <-- 3    =>    2     2     2

Example 2:
Input: machines = [0,3,0]
Output: 2
Explanation:
1st move:    0 <-- 3     0    =>    1     2     0
2nd move:    1     2 --> 0    =>    1     1     1

Example 3:
Input: machines = [0,2,0]
Output: -1
Explanation:
It's impossible to make all three washing machines have the same number of
dresses.

Constraints:
n == machines.length
1 <= n <= 10^4
0 <= machines[i] <= 10^5
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
    int findMinMoves(vector<int> &machines) {
        int sum = std::accumulate(begin(machines), end(machines), 0);
        int sz = machines.size();
        auto [div, mod] = std::div(sum, sz);
        if (mod != 0)
            return -1;
        int res = 0;
        for (int surplus = 0; auto m : machines) {
            int diff = m - div;
            surplus += diff;
            res = max({res, abs(surplus), diff});
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> machines;

    // Output: 3
    machines = {1, 0, 5};
    cout << sol.findMinMoves(machines) << endl;

    // Output: 2
    machines = {0, 3, 0};
    cout << sol.findMinMoves(machines) << endl;

    // Output: -1
    machines = {0, 2, 0};
    cout << sol.findMinMoves(machines) << endl;

    // Output: 27
    machines = {1, 0, 5, 3, 6, 2, 5, 6, 7, 5, 3, 3, 33, 5};
    cout << sol.findMinMoves(machines) << endl;

    // Output: 2
    machines = {4, 0, 0, 4};
    cout << sol.findMinMoves(machines) << endl;

    // Output: 2
    machines = {3, 1, 0, 4};
    cout << sol.findMinMoves(machines) << endl;

    return 0;
}
