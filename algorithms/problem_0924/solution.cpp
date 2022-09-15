/*
924. Minimize Malware Spread
Hard

You are given a network of n nodes represented as an n x n adjacency matrix
graph, where the ith node is directly connected to the jth node if graph[i][j]
== 1.

Some nodes initial are initially infected by malware. Whenever two nodes are
directly connected, and at least one of those two nodes is infected by malware,
both nodes will be infected by malware. This spread of malware will continue
until no more nodes can be infected in this manner.

Suppose M(initial) is the final number of nodes infected with malware in the
entire network after the spread of malware stops. We will remove exactly one
node from initial.

Return the node that, if removed, would minimize M(initial). If multiple nodes
could be removed to minimize M(initial), return such a node with the smallest
index.

Note that if a node was removed from the initial list of infected nodes, it
might still be infected later due to the malware spread.

Example 1:
Input: graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
Output: 0

Example 2:
Input: graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
Output: 0

Example 3:
Input: graph = [[1,1,1],[1,1,1],[1,1,1]], initial = [1,2]
Output: 1

Constraints:
n == graph.length
n == graph[i].length
2 <= n <= 300
graph[i][j] is 0 or 1.
graph[i][j] == graph[j][i]
graph[i][i] == 1
1 <= initial.length <= n
0 <= initial[i] <= n - 1
All the integers in initial are unique
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
    int n;
    vector<vector<int>> g;
    int minMalwareSpread(vector<int> &initial, int blocked) {
        queue<int> q;
        unordered_set<int> visited;
        int count = 0;

        for (int id : initial) {
            if (id != blocked) {
                q.push(id);
                visited.insert(id);
            }
        }

        while (!q.empty()) {
            ++count;
            int id = q.front();
            q.pop();
            for (int j : g[id]) {
                if (visited.count(j) == 0) {
                    q.push(j);
                    visited.insert(j);
                }
            }
        }

        return count;
    }

    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        n = graph.size();
        g.resize(n);
        int id, count = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && graph[i][j]) {
                    g[i].push_back(j);
                }
            }
        }

        for (int blocked : initial) {
            auto t = minMalwareSpread(initial, blocked);
            if (t < count || (t == count && blocked < id)) {
                count = t;
                id = blocked;
            }
        }
        return id;
    }
};

int main() {
    Solution sol;

    return 0;
}
