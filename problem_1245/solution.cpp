/*
1245. Tree Diameter
Medium

Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.

The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v.  Each node has labels in the set {0, 1, ..., edges.length}.

Example 1:
Input: edges = [[0,1],[0,2]]
Output: 2
Explanation: 
A longest path of the tree is the path 1 - 0 - 2.

Example 2:
Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation: 
A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long
#define ull unsigned long long

class Solution {
public:
    struct Node {
        Node(): id(-1), prev(-1), dist(0) {}
        int id, prev, dist;
        set<int> neighs;
    };
    static constexpr int N = 10000;
    
    int treeDiameter(vector<vector<int>>& edges) {
        vector<Node> nodes(N);
        int n = 0;

        for (auto& edge: edges) {
            int i = edge[0], j = edge[1];
            n = max(n, max(i, j));
            nodes[i].neighs.emplace(j);
            nodes[i].id = i;
            nodes[j].neighs.emplace(i);
            nodes[j].id = j;
        }

        queue<int> q;
        for (int i = 0; i <= n; ++i) {
            if (nodes[i].neighs.size() == 1)
                q.emplace(i);
        }

        array<int, 2> dist{0, 0};
        while (!q.empty()) {
            Node& node = nodes[q.front()];
            q.pop();
            dist[1] = dist[0];
            dist[0] = node.dist;
            int n_id = *node.neighs.begin();
            nodes[n_id].neighs.erase(node.id);
            if (nodes[n_id].neighs.size() > 0) {
                node.prev = n_id;
                nodes[n_id].dist = max(nodes[n_id].dist, node.dist + 1);
            }
            if (nodes[n_id].neighs.size() == 1 && nodes[n_id].prev < 0)
                q.emplace(n_id);
        }
        
        return dist[0] + dist[1] + 1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges;

    // Output: 2
    edges = {{0,1},{0,2}};

    // Output: 4
    //edges = {{0,1},{1,2},{2,3},{1,4},{4,5}};

    // Output: 5
    //edges = {{0,1},{1,2},{0,3},{3,4},{2,5},{3,6}};

    // Output: 5
    //edges = {{0,1},{1,2},{2,3},{2,4},{0,5},{1,6},{2,7},{6,8},{8,9}};
    
    cout << "Result: " << sol.treeDiameter(edges) << endl;
    
    return 0;
}
