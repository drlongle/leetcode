/*
1168. Optimize Water Distribution in a Village
Difficulty: Hard

There are n houses in a village. We want to supply water for all the houses by building wells
and laying pipes. For each house i, we can either build a well inside it directly with cost wells[i],
or pipe in water from another well to it. The costs to lay pipes between houses are given by the
array pipes, where each pipes[i] = [house1, house2, cost] represents the cost to connect
house1 and house2 together using a pipe. Connections are bidirectional.

Find the minimum total cost to supply water to all houses.

Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation:
The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses
to it with cost 2 so the total cost is 3.
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

struct Edge {
    Edge(int i_, int j_, int c): i(i_), j(j_), cost(c) {}
    bool operator<(const Edge& other) const {
        return cost > other.cost;
    }
    int i, j, cost;
};

class Solution {
public:
    int get_root(int x) {
        while (x != roots[x])
            x = roots[x];
        return x;
    }

    void join_root(int new_root, int x) {
        while (roots[x] != new_root) {
            int temp = roots[x];
            roots[x] = new_root;
            x = temp;
        }
    }

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        priority_queue<Edge> pq;

        for (int i = 0; i < n; ++i) {
            pq.emplace(i, n, wells[i]);
            roots[i] = i;
        }
        roots[n] = n;

        for (auto& pipe: pipes)
            pq.emplace(pipe[0]-1, pipe[1]-1, pipe[2]);

        int res = 0;
        while (!pq.empty()) {
            auto& edge = pq.top();
            //cout << "Edge: " << edge.i << " -> " << edge.j << ", cost: " << edge.cost << endl;
            int root_i = get_root(edge.i);
            int root_j = get_root(edge.j);
            if (root_i == root_j) {
                pq.pop();
                continue;
            }
            res += edge.cost;
            if (root_j > root_i)
                join_root(root_i, edge.j);
            else
                join_root(root_j, edge.i);
            pq.pop();
        }

        return res;
    }
    map<int, int> roots;
};

int main() {
    Solution sol;
    
    int n;
    vector<int> wells;
    vector<vector<int>> pipes;

    // Output: 3
    n = 3, wells = {1,2,2}, pipes = {{1,2,1},{2,3,1}};

    // Expected: 131704
    //n = 5, wells = {46012,72474,64965,751,33304}, pipes = {{2,1,6719},{3,2,75312},{5,3,44918}};

    cout << "Result: " << sol.minCostToSupplyWater(n, wells, pipes) << endl;

    return 0;
}
