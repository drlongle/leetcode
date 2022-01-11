/*
1319. Number of Operations to Make Network Connected
Medium

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Example 2:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Example 3:
Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

Example 4:
Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0

Constraints:
1 <= n <= 10^5
1 <= connections.length <= min(n*(n-1)/2, 10^5)
connections[i].length == 2
0 <= connections[i][0], connections[i][1] < n
connections[i][0] != connections[i][1]
There are no repeated connections.
No two computers are connected by more than one cable.
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

    int get_root(int n) {
        while (roots[n] != n) {
            n = roots[n];
        }
        return n;
    }

    void set_root(int n, int root) {
        while (roots[n] != root) {
            int parent = roots[n];
            roots[n] = root;
            n = parent;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& conns) {
        roots.resize(n);
        iota(begin(roots), end(roots), 0);
        size_t spares = 0;
        for (auto& conn: conns) {
            int root1 = get_root(conn[0]);
            int root2 = get_root(conn[1]);
            if (root1 == root2)
                ++spares;
            else if (root1 < root2) {
                set_root(conn[1], root1);
            } else
                set_root(conn[0], root2);
        }

        set<int> uniq;
        for (int i = 0; i < n; ++i)
            uniq.emplace(get_root(i));

        size_t sz = uniq.size();

        if (sz == 1)
            return 0;
        else if (sz - 1 > spares)
            return -1;
        else
            return min(sz - 1, spares);
    }
    vector<int> roots;
};

int main() {
    Solution sol;
    vector<vector<int>> connections;
    int n;

    // Output: 1
    n = 4, connections = {{0,1},{0,2},{1,2}};

    // Output: 2
    //n = 6, connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};

    // Output: -1
    //n = 6, connections = {{0,1},{0,2},{0,3},{1,2}};

    // Output: 0
    //n = 5, connections = {{0,1},{0,2},{3,4},{2,3}};

    // Expected: 4
    n = 12;
    connections = {{1,5},{1,7},{1,2},{1,4},{3,7},{4,7},{3,5},{0,6},{0,1},{0,4},{2,6},{0,3},{0,2}};
        
    cout << "Result: " << sol.makeConnected(n, connections) << endl;
    
    return 0;
}
