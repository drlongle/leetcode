/*
598. Range Addition II
Easy

You are given an m x n matrix M initialized with all 0's and an array of operations ops, where
ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.

Example 2:
Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4

Example 3:
Input: m = 3, n = 3, ops = []
Output: 9

Constraints:
1 <= m, n <= 4 * 10^4
1 <= ops.length <= 10^4
ops[i].length == 2
1 <= ai <= m
1 <= bi <= n
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

#define for_loop(n) for(int i = 0; i < n; ++i)

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minx = INT_MAX, miny = INT_MAX;
        for (auto& op: ops) {
            minx = min(minx, op[0]);
            miny = min(miny, op[1]);
        }
        return ops.empty() ? m * n : minx * miny;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> ops;
    int m, n;

    // Output: 4
    m = 3, n = 3, ops = {{2,2},{3,3}};
    cout << sol.maxCount(m, n, ops) << endl;

    // Output: 4
    m = 3, n = 3, ops = {{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3}};
    cout << sol.maxCount(m, n, ops) << endl;

    // Output: 9
    m = 3, n = 3, ops = {};
    cout << sol.maxCount(m, n, ops) << endl;

    return 0;
}
