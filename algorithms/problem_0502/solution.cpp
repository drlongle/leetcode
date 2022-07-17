/*
502. IPO
Hard

Suppose LeetCode will start its IPO soon. In order to sell a good price of its
shares to Venture Capital, LeetCode would like to work on some projects to
increase its capital before the IPO. Since it has limited resources, it can only
finish at most k distinct projects before the IPO. Help LeetCode design the best
way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and
a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its
pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your
final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

Example 1:
Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project
indexed 0. After finishing it you will obtain profit 1 and your capital
becomes 1. With capital 1, you can either start the project indexed 1 or the
project indexed 2. Since you can choose at most 2 projects, you need to finish
the project indexed 2 to get the maximum capital. Therefore, output the final
maximized capital, which is 0 + 1 + 3 = 4.

Example 2:
Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6

Constraints:
1 <= k <= 10^5
0 <= w <= 10^9
n == profits.length
n == capital.length
1 <= n <= 10^5
0 <= profits[i] <= 10^4
0 <= capital[i] <= 10^9
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

struct Project {
    Project(int p, int c) : profit(p), capital(c) {}
    int profit, capital;
};

class Solution {
  public:
    int findMaximizedCapital(int k, int w, vector<int> &profits,
                             vector<int> &capital) {
        vector<Project> projects;
        for (int i = 0, sz = profits.size(); i < sz; ++i) {
            projects.emplace_back(profits[i], capital[i]);
        }
        sort(begin(projects), end(projects), [](const auto &a, const auto &b) {
            return a.capital < b.capital;
        });

        priority_queue<int> pq;
        for (int cur = 0, index = 0, sz = projects.size(); cur < k; ++cur) {
            while (index < sz && projects[index].capital <= w) {
                pq.emplace(projects[index++].profit);
            }
            if (pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};

int main() {
    Solution sol;
    vector<int> profits, capital;
    int k, w;

    // Expected: 4
    k = 2, w = 0, profits = {1, 2, 3}, capital = {0, 1, 1};
    cout << "Result: " << sol.findMaximizedCapital(k, w, profits, capital)
         << endl;

    // Expected: 6
    k = 3, w = 0, profits = {1, 2, 3}, capital = {0, 1, 2};
    cout << "Result: " << sol.findMaximizedCapital(k, w, profits, capital)
         << endl;

    return 0;
}
