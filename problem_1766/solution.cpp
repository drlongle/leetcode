/*
1766. Tree of Coprimes
Hard

There is a tree (i.e., a connected, undirected graph that has no cycles) consisting of n nodes
numbered from 0 to n - 1 and exactly n - 1 edges. Each node has a value associated with it, and
the root of the tree is node 0.

To represent this tree, you are given an integer array nums and a 2D array edges. Each nums[i]
represents the ith node's value, and each edges[j] = [uj, vj] represents an edge between nodes
uj and vj in the tree.

Two values x and y are coprime if gcd(x, y) == 1 where gcd(x, y) is the greatest common divisor of x and y.

An ancestor of a node i is any other node on the shortest path from node i to the root.
A node is not considered an ancestor of itself.

Return an array ans of size n, where ans[i] is the closest ancestor to node i such
that nums[i] and nums[ans[i]] are coprime, or -1 if there is no such ancestor.

Example 1:
Input: nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
Output: [-1,0,0,1]
Explanation: In the above figure, each node's value is in parentheses.
- Node 0 has no coprime ancestors.
- Node 1 has only one ancestor, node 0. Their values are coprime (gcd(2,3) == 1).
- Node 2 has two ancestors, nodes 1 and 0. Node 1's value is not coprime (gcd(3,3) == 3), but node 0's
  value is (gcd(2,3) == 1), so node 0 is the closest valid ancestor.
- Node 3 has two ancestors, nodes 1 and 0. It is coprime with node 1 (gcd(3,2) == 1), so node 1 is its
  closest valid ancestor.

Example 2:
Input: nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
Output: [-1,0,-1,0,0,0,-1]

Constraints:
nums.length == n
1 <= nums[i] <= 50
1 <= n <= 105
edges.length == n - 1
edges[j].length == 2
0 <= uj, vj < n
uj != vj
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

    vector<vector<int>> graph;
    vector<int> path, res;
    vector<bool> seen;
    unordered_map<int, vector<int>> path_map;

    int gcd(int a, int b){
        while(b){
            int temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }

    void DFS(vector<int>& nums, int i) {
        seen[i] = 1;
        int pos = -1;
        int n = nums[i];
        for (auto& [k, v]: path_map) {
            if (v.empty() || gcd(n, k) != 1)
                continue;
            pos = max(pos, v.back());
        }
        if (pos >= 0)
            res[i] = path[pos];

        path.push_back(i);
        path_map[n].push_back(path.size()-1);
        for (int j: graph[i]) {
            if (!seen[j])
                DFS(nums, j);
        }
        path_map[n].pop_back();
        path.pop_back();
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        graph.resize(n);
        res.resize(n, -1);
        seen.resize(n, false);
        graph.resize(n);

        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        DFS(nums, 0);

        return res;
    }
};

int main() {
    vector<vector<int>> edges;
    vector<int> nums;

    // Output: [-1,0,0,1]
    {
        Solution sol;
        nums = {2,3,3,2}, edges = {{0,1},{1,2},{1,3}};
        nums = sol.getCoprimes(nums, edges);
        copy(begin(nums), end(nums), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    // Output: [-1,0,-1,0,0,0,-1]
    {
        Solution sol;
        nums = {5, 6, 10, 2, 3, 6, 15}, edges = {{0, 1},
                                                 {0, 2},
                                                 {1, 3},
                                                 {1, 4},
                                                 {2, 5},
                                                 {2, 6}};
        nums = sol.getCoprimes(nums, edges);
        copy(begin(nums), end(nums), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}
