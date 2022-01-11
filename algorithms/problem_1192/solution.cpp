/*
1192. Critical Connections in a Network
Hard

There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some server unable to reach some other server.

Return all critical connections in the network in any order.
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

enum class Color {
    White, Gray, Black
};

struct Node {
    void reset(int id_) {
        neighs.clear();
        id = id_;
        pred = -1;
        color = Color::White;
    }
    set<int> neighs;
    int id;
    int pred;
    Color color;
};

class Solution {
public:
    Solution(): nodes(100000) {}

void DFS(int i, int prev, set<int>& visited) {
        if (nodes[i].color == Color::Gray) {
            edges.erase(pair<int, int> (min(i, prev), max(i, prev)));
            visited.emplace(i);
            i = prev;
            while (i >= 0 && visited.count(i) == 0) {
                int prev = nodes[i].pred;
                edges.erase(pair<int, int>(min(i, prev), max(i, prev)));
                visited.emplace(i);
                i = prev;
            }

            return;
        }

        nodes[i].color = Color::Gray;
        nodes[i].pred = prev;
        for (int neigh: nodes[i].neighs) {
            if (neigh != prev && nodes[neigh].color != Color::Black)
                DFS(neigh, i, visited);
        }
        nodes[i].color = Color::Black;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        edges.clear();
        for (int i = 0; i < n; ++i) {
            nodes[i].reset(i);
        }

        for (auto& conn: connections) {
            int i = conn[0];
            int j = conn[1];
            nodes[i].neighs.emplace(j);
            nodes[j].neighs.emplace(i);
            edges.emplace(min(i, j), max(i, j));
        }

        for (int i = 0; i < n; ++i) {
            set<int> visited;
            if (nodes[i].color == Color::White)
                DFS(i, -1, visited);
        }

        vector<vector<int>> res;
        for (auto& edge: edges) {
            vector<int> conn{edge.first, edge.second};
            res.emplace_back(conn);
        }
        return res;
    }

    vector<Node> nodes;
    set<pair<int, int>> edges;
};

int main() {
    Solution sol;
    return 0;
}
