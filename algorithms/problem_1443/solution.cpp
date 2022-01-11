/*
1443. Minimum Time to Collect All Apples in a Tree
Medium

Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend in order to collect all apples in the tree starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi] means that exists an edge connecting the vertices fromi and toi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple, otherwise, it does not have any apple.

Example 1:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

Example 2:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  

Example 3:
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0

Constraints:
1 <= n <= 10^5
edges.length == n-1
edges[i].length == 2
0 <= fromi, toi <= n-1
fromi < toi
hasApple.length == n
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

    unordered_map<int, unordered_set<int>> graph;
    vector<bool> visited;

    int dfs(int id, vector<bool>& hasApple)
    {
        if (graph[id].empty()) {
            return hasApple[id] ? 0 : -1;
        }
        
        int res = 0;
        visited[id] = true;

        for (int neigh: graph[id]) {
            if (visited[neigh])
                continue;
            int temp = dfs(neigh, hasApple);
            if (temp >= 0)
                res += 2 + temp;
        }

        return (hasApple[id] || res > 0) ? res : -1;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        visited.resize(n, false);
        for (auto& edge: edges) {
            graph[edge[0]].emplace(edge[1]);
            graph[edge[1]].emplace(edge[0]);
        }

        return max(0, dfs(0, hasApple));
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges;
    vector<bool> hasApple;
    int n;

    // Output: 8 
    n = 7, edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}}, hasApple = {false,false,true,false,true,true,false};
    //cout << sol.minTime(n, edges, hasApple) << endl;

    // Output: 6
    n = 7, edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}}, hasApple = {false,false,true,false,false,true,false};
    //cout << sol.minTime(n, edges, hasApple) << endl;

    // Output: 0
    n = 7, edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}}, hasApple = {false,false,false,false,false,false,false};
    cout << sol.minTime(n, edges, hasApple) << endl;
    
    return 0;
}
