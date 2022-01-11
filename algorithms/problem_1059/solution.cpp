/*
1059. All Paths from Source Lead to Destination
Medium

Given the edges of a directed graph where edges[i] = [ai, bi] indicates there is an edge between nodes
ai and bi, and two nodes source and destination of this graph, determine whether or not all paths
starting from source eventually, end at destination, that is:

At least one path exists from the source node to the destination node
If a path exists from the source node to a node with no outgoing edges, then that node is equal to destination.
The number of possible paths from source to destination is a finite number.
Return true if and only if all roads from source lead to destination.

Example 1:
Input: n = 3, edges = [[0,1],[0,2]], source = 0, destination = 2
Output: false
Explanation: It is possible to reach and get stuck on both node 1 and node 2.

Example 2:
Input: n = 4, edges = [[0,1],[0,3],[1,2],[2,1]], source = 0, destination = 3
Output: false
Explanation: We have two possibilities: to end at node 3, or to loop over node 1 and node 2 indefinitely.

Example 3:
Input: n = 4, edges = [[0,1],[0,2],[1,3],[2,3]], source = 0, destination = 3
Output: true

Example 4:
Input: n = 3, edges = [[0,1],[1,1],[1,2]], source = 0, destination = 2
Output: false
Explanation: All paths from the source node end at the destination node, but there are an
infinite number of paths, such as 0-1-2, 0-1-1-2, 0-1-1-1-2, 0-1-1-1-1-2, and so on.

Example 5:
Input: n = 2, edges = [[0,1],[1,1]], source = 0, destination = 1
Output: false
Explanation: There is infinite self-loop at destination node.

Constraints:
1 <= n <= 10^4
0 <= edges.length <= 10^4
edges.length == 2
0 <= ai, bi <= n - 1
0 <= source <= n - 1
0 <= destination <= n - 1
The given graph may have self-loops and parallel edges.
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
#include "common/TreeNode.h"

using namespace std;

class Solution {
public:

    vector <unordered_set <int>> graph;
    vector <int> reach, state;

    bool visit(int id){
        if (state[id] == 2) return true;
        if (state[id] == 1) return false;
        state[id] = 1;
        for (int nei: graph[id]) {
            if(!visit(nei))
                return false;
            reach[id] |= reach[nei];
        }
        state[id] = 2;
        return reach[id];
    }

    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.resize(n);
        reach.resize(n,0);
        state.resize(n, 0);
        reach[destination] = true;
        for (auto & edge: edges){
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
        }

        return visit(source);
    }
};

int main() {
    Solution sol;
    int n, source, destination;
    vector<vector<int>> edges;

    // Output: false
    n = 3, edges = {{0,1},{0,2}}, source = 0, destination = 2;
    cout << boolalpha<< sol.leadsToDestination(n, edges, source, destination) << endl;

    return 0;
}
