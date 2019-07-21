/*
1129. Shortest Path with Alternating Colors
Medium

Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph,
each edge is either red or blue, and there could be self-edges or parallel edges.

Each [i, j] in red_edges denotes a red directed edge from node i to node j. Similarly,
each [i, j] in blue_edges denotes a blue directed edge from node i to node j.

Return an array answer of length n, where each answer[X] is the length of the
shortest path from node 0 to node X such that the edge colors alternate along
the path (or -1 if such a path doesn't exist). 

Example 1:
Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
Output: [0,1,-1]

Example 2:
Input: n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
Output: [0,1,-1]

Example 3:
Input: n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
Output: [0,-1,-1]

Example 4:
Input: n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
Output: [0,1,2]
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
#include <condition_variable>
#include <cmath>
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

struct Node {
    Node(int id_): id(id_), edges(2) {}
    int id;
    vector<vector<int>> edges;
    bitset<2> done;
};

struct Entry {
    int id;
    int dist; // distance
    int color; // we reached a node with this color
};

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> res(n, -1);
        vector<Node> nodes;
        for (int i = 0; i < n; ++i)
            nodes.emplace_back(i);
        for (auto& edge: red_edges) {
            nodes[edge[0]].edges[0].emplace_back(edge[1]);
        }
        for (auto& edge: blue_edges) {
            nodes[edge[0]].edges[1].emplace_back(edge[1]);
        }

        queue<Entry> q;
        q.push({0, 0, -1});
        while (!q.empty()) {
            Entry e = q.front();
            q.pop();
            if (res[e.id] < 0)
                res[e.id] = e.dist;
            Node& n =  nodes[e.id];
            if (e.color < 0) {
                n.done.set(0);
                n.done.set(1);
                for (int color = 0; color <= 1; ++color) {
                    for (int neigh_id: n.edges[color]) {
                        if (!nodes[neigh_id].done.test(color))
                            q.push({neigh_id, e.dist+1, color});
                    }
                }
            } else {
                n.done.set(e.color);
                for (int neigh_id: n.edges[1-e.color]) {
                    if (!nodes[neigh_id].done.test(1-e.color))
                        q.push({neigh_id, e.dist+1, 1-e.color});
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> red_edges, blue_edges;
    vector<int> res;
    int n;

    // Expected: [0,1,-1]
    n = 3, red_edges = {{0,1},{1,2}}, blue_edges = {};

    // Expected: [0,1,-1]
    n = 3, red_edges = {{0,1}}, blue_edges = {{2,1}};

    // Expected: [0,-1,-1]
    n = 3, red_edges = {{1,0}}, blue_edges = {{2,1}};

    // Expected: [0,1,2]
    n = 3, red_edges = {{0,1}}, blue_edges = {{1,2}};

    // 4 / 90 test cases passed.
    n = 3, red_edges = {{0,1},{0,2}}, blue_edges = {{1,0}};

    n = 5, red_edges = {{2,2},{0,1},{0,3},{0,0},{0,4},{2,1},{2,0},{1,4},{3,4}};
    blue_edges = {{1,3},{0,0},{0,3},{4,2},{1,0}};

    // 44 / 90 test cases passed.
    // Expected: [0,1,2,3,7]
    // n = 5, red_edges = {{0,1},{1,2},{2,3},{3,4}}, blue_edges= {{1,2},{2,3},{3,1}};

    res = sol.shortestAlternatingPaths(n, red_edges, blue_edges);
    copy(begin(res), end(res), ostream_iterator<int>(cout, ", "));

    return 0;
}

