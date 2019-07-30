/*
1135. Connecting Cities With Minimum Cost
Difficulty: Medium

There are N cities numbered from 1 to N.
You are given connections, where each connections[i] = [city1, city2, cost] represents
the cost to connect city1 and city2 together. (A connection is bidirectional:
connecting city1 and city2 is the same as connecting city2 and city1.)

Return the minimum cost so that for every pair of cities, there exists a path of
connections (possibly of length 1) that connects those two cities together. The
cost is the sum of the connection costs used. If the task is impossible, return -1.

Example 1:
Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: 
Choosing any 2 edges will connect all cities so we choose the minimum 2.

Example 2:
Input: N = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: 
There is no way to connect all cities even if all edges are used.
*/

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <sstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define ll long long
#define ull unsigned long long

using namespace std;

struct Edge {
    Edge(int f, int t, int c): from(f), to(t), cost(c) {}
    bool operator<(const Edge& other) const {
        return cost > other.cost;
    }
    int from, to, cost;
};

vector<int> roots;

int get_root(int x) {
    while (x != roots[x])
        x = roots[x];
    return x;
}

void set_root(int x, int new_root) {
    while (roots[x] != new_root) {
        int t = roots[x];
        roots[x] = new_root;
        x = t;
    }
}

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        roots.resize(N+1);
        for (int i = 1; i <= N; ++i)
            roots[i] = i;
        priority_queue<Edge, vector<Edge>> edges;
        for (auto& conn: connections)
            edges.emplace(conn[0], conn[1], conn[2]);
        int cost = 0, count = 0;
        while (!edges.empty()) {
            Edge e = edges.top();
            edges.pop();
            int root_a = get_root(e.from);
            int root_b = get_root(e.to);
            if (root_a == root_b)
                continue;
            ++count;
            cost += e.cost;
            if (root_a < root_b)
                set_root(e.to, root_a);
            else
                set_root(e.from, root_b);
        }
        
        return (count == N-1) ? cost : -1;
    }
};

int main()
{
    Solution sol;
    int N;
    vector<vector<int>> connections;

    // Expected: 6
    N = 3, connections = {{1,2,5},{1,3,6},{2,3,1}};
    
    // Expected: -1
    //N = 4, connections = {{1,2,3},{3,4,4}};

    cout << "Result: " << sol.minimumCost(N, connections) << endl;
    
    return 0;
}

