/*
1466. Reorder Routes to Make All Paths Lead to the City Zero
Medium

There are n cities numbered from 0 to n-1 and n-1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [a, b] represents a road from city a to b.
This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.
It's guaranteed that each city can reach the city 0 after reorder.

Example 1:
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 2:
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

Example 3:
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0

Constraints:
2 <= n <= 5 * 10^4
connections.length == n-1
connections[i].length == 2
0 <= connections[i][0], connections[i][1] <= n-1
connections[i][0] != connections[i][1]
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

#define ll long long
#define ull unsigned long long

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, unordered_set<int>> graph, reversed_graph;
        for (auto& conn: connections) {
            int fr = conn[0], to = conn[1];
            graph[fr].emplace(to);
            reversed_graph[to].emplace(fr);
        }
        queue<int> visit;
        visit.push(0);
        int res = 0;
        while (!visit.empty()) {
            int id = visit.front();
            visit.pop();
            for (int nid: graph[id]) {
                visit.push(nid);
                ++res;
                reversed_graph[nid].erase(id);
            }
            for (int nid: reversed_graph[id]) {
                visit.push(nid);
                graph[nid].erase(id);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> connections;
    int n;

    n = 6, connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << sol.minReorder(n, connections) << endl;
    
    n = 5, connections = {{1,0},{1,2},{3,2},{3,4}};
    cout << sol.minReorder(n, connections) << endl;
    
    n = 3, connections = {{1,0},{2,0}};
    cout << sol.minReorder(n, connections) << endl;
    
    return 0;
}
