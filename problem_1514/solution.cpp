/*
1514. Path with Maximum Probability
Medium

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list
where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability
of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go
from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted
if it differs from the correct answer by at most 1e-5.

Example 1:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

Example 2:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:
Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.

Constraints:
2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.
*/

#include <algorithm>
#include <atomic>
#include <bitset>
#include <cassert>
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
#include <set>
#include <sstream>
#include <stack>
#include <string_view>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    struct Node {
        Node(): parent(-1), cost(numeric_limits<double>::max())
        {
        }
        int parent;
        double cost;
        unordered_map<int, double> edges;
    };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        int sz = edges.size();
        vector<Node> nodes(n);
        nodes[end].cost = 0.0;
        for (int i = 0; i < sz; ++i) {
            int a = edges[i][0], b = edges[i][1];
            double cost = succProb[i];
            if (cost > 0) {
                double c = log2(1/cost);
                nodes[a].edges[b] = c;
                nodes[b].edges[a] = c;
            }
        }

        auto lambda = [&] (int i, int j) {
            return nodes[i].cost <= nodes[j].cost;
        };

        set<int, decltype(lambda)> q(lambda);
        q.insert(end);
        while (q.size()) {
            auto it = q.begin();
            int i = *it;
            q.erase(it);
            double cost_i = nodes[i].cost;
            for (auto& [j, edge_cost]: nodes[i].edges) {
                double cost_j = cost_i + edge_cost;
                if (cost_j < nodes[j].cost) {
                    nodes[j].cost = cost_j;
                    nodes[j].parent = i;
                    q.erase(j);
                    q.insert(j);
                }
            }
        }

        if (nodes[start].parent < 0)
            return 0;

        return 1.0 / pow(2, nodes[start].cost);;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges;
    vector<double> succProb;
    int n, start, end;

    n = 3, edges = {{0,1},{1,2},{0,2}}, succProb = {0.5,0.5,0.2}, start = 0, end = 2;
    // Output: 0.25000
    cout << sol.maxProbability(n, edges, succProb, start, end) << endl;

    n = 3, edges = {{0,1},{1,2},{0,2}}, succProb = {0.5,0.5,0.3}, start = 0, end = 2;
    cout << sol.maxProbability(n, edges, succProb, start, end) << endl;

    n = 3, edges = {{0,1}}, succProb = {0.5}, start = 0, end = 2;
    cout << sol.maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}
