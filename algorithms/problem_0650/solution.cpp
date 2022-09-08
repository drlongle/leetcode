/*
650. 2 Keys Keyboard
Medium

There is only one character 'A' on the screen of a notepad. You can perform one
of two operations on this notepad for each step: Copy All: You can copy all the
characters present on the screen (a partial copy is not allowed). Paste: You can
paste the characters which are copied last time.

Given an integer n, return the minimum number of operations to get the character
'A' exactly n times on the screen.

Example 1:
Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Example 2:
Input: n = 1
Output: 0

Constraints:
1 <= n <= 1000
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
    struct Step {
        Step(int t, int c, int s) : total(t), copied(c), steps(s) {}
        int total;
        int copied;
        int steps;
    };

    int minSteps(int n) {
        queue<Step> q;
        q.emplace(1, 0, 0);
        unordered_set<int> visited;
        while (true) {
            auto &e = q.front();
            // cout << e.total << ", " << e.copied << ", " << e.steps << endl;
            if (e.total == n)
                return e.steps;
            if (e.total < n) {
                q.emplace(e.total + e.copied, e.copied, e.steps + 1);
                if (visited.insert(e.total).second)
                    q.emplace(e.total, e.total, e.steps + 1);
            }
            q.pop();
        }
        return 0;
    }
};

int main() {
    Solution sol;
    int n;

    // Output: 3
    n = 3;
    cout << "n: " << n << " -> " << sol.minSteps(n) << endl;

    // Output: 0
    n = 1;
    cout << "n: " << n << " -> " << sol.minSteps(n) << endl;

    return 0;
}
