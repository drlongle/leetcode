/*
2246. Longest Path With Different Adjacent Characters
Hard

You are given a tree (i.e. a connected, undirected graph that has no cycles)
rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is
represented by a 0-indexed array parent of size n, where parent[i] is the parent
of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned
to node i.

Return the length of the longest path in the tree such that no pair of adjacent
nodes on the path have the same character assigned to them.

Example 1:
Input: parent = [-1,0,0,1,1,2], s = "abacbe"
Output: 3
Explanation: The longest path where each two adjacent nodes have different
characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3,
so 3 is returned. It can be proven that there is no longer path that satisfies
the conditions.

Example 2:
Input: parent = [-1,0,0,0], s = "aabc"
Output: 3
Explanation: The longest path where each two adjacent nodes have different
characters is the path: 2 -> 0 -> 3. The length of this path is 3, so 3 is
returned.

Constraints:
n == parent.length == s.length
1 <= n <= 10^5
0 <= parent[i] <= n - 1 for all i >= 1
parent[0] == -1
parent represents a valid tree.
s consists of only lowercase English letters.
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
    unordered_map<int, vector<int>> graph;
    size_t res = 0;
    size_t visit(int node, const string &s) {
        char ch = s[node];
        size_t r = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int c : graph[node]) {
            auto t = visit(c, s);
            if (s[c] != ch) {
                r = max(r, t + 1);
                pq.push(t);
                if (pq.size() > 2)
                    pq.pop();
            }
        }

        if (pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            res = max(res, size_t(a + b + 1));
        }

        res = max(res, r);
        return r;
    }

    int longestPath(vector<int> &parent, const string &s) {
        int root = 0;
        for (int i = 0, n = parent.size(); i < n; ++i) {
            if (parent[i] < 0)
                root = i;
            else
                graph[parent[i]].push_back(i);
        }
        visit(root, s);

        return res;
    }
};

int main() {

    vector<int> parent;
    string s;

    // Output: 3
    {
        Solution sol;
        parent = {-1, 0, 0, 1, 1, 2}, s = "abacbe";
        cout << sol.longestPath(parent, s) << endl;
    }

    // Output: 3
    {
        Solution sol;
        parent = {-1, 0, 0, 0}, s = "aabc";
        cout << sol.longestPath(parent, s) << endl;
    }
    return 0;
}
