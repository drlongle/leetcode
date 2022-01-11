/*
1462. Course Schedule IV
Medium

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have direct prerequisites, for example, to take course 0 you have first to take course 1, which is expressed as a pair: [1,0]

Given the total number of courses n, a list of direct prerequisite pairs and a list of queries pairs.

You should answer for each queries[i] whether the course queries[i][0] is a prerequisite of the course queries[i][1] or not.

Return a list of boolean, the answers to the given queries.

Please note that if course a is a prerequisite of course b and course b is a prerequisite of course c, then, course a is a prerequisite of course c.

Example 1:
Input: n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: course 0 is not a prerequisite of course 1 but the opposite is true.

Example 2:
Input: n = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites and each course is independent.

Example 3:
Input: n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]

Example 4:
Input: n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
Output: [false,true]

Example 5:
Input: n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
Output: [true,false,true,false]

Constraints:
2 <= n <= 100
0 <= prerequisite.length <= (n * (n - 1) / 2)
0 <= prerequisite[i][0], prerequisite[i][1] < n
prerequisite[i][0] != prerequisite[i][1]
The prerequisites graph has no cycles.
The prerequisites graph has no repeated edges.
1 <= queries.length <= 10^4
queries[i][0] != queries[i][1]
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
    struct Node {
        Node(): done(false) {}
        vector<int> neighs;
        unordered_set<int> prereqs;
        bool done;
    };

    vector<Node> nodes;

    void visit(int id) {
        if (nodes[id].done)
            return;
        for (int neigh: nodes[id].neighs) {
            nodes[id].prereqs.emplace(neigh);
            visit(neigh);
            nodes[id].prereqs.insert(nodes[neigh].prereqs.begin(), nodes[neigh].prereqs.end());
        }
        nodes[id].done = true;
    }
    
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        nodes.resize(n);
        for (auto& preq: prerequisites) {
            nodes[preq[1]].neighs.push_back(preq[0]);
        }

        for (int i = 0; i < n; ++i)
            visit(i);
        
        vector<bool> res;
        for (auto& query: queries) {
            res.push_back(nodes[query[1]].prereqs.count(query[0]));
        }
        return res;
    }
};

int main() {
    vector<vector<int>> prerequisites, queries;
    vector<bool> res;
    int n;

    {
        // Output: {false,true}
        Solution sol;
        n = 2, prerequisites = {{1,0}}, queries = {{0,1},{1,0}};
        res = sol.checkIfPrerequisite(n, prerequisites, queries);
        copy(begin(res), end(res), ostream_iterator<bool>(cout, ", "));
        cout << endl;
    }

    {
        // Output: {false,false}
        Solution sol;
        n = 2, prerequisites = {}, queries = {{1,0},{0,1}};
        res = sol.checkIfPrerequisite(n, prerequisites, queries);
        copy(begin(res), end(res), ostream_iterator<bool>(cout, ", "));
        cout << endl;
    }

    {
        // Output: {true,true}
        Solution sol;
        n = 3, prerequisites = {{1,2},{1,0},{2,0}}, queries = {{1,0},{1,2}};
        res = sol.checkIfPrerequisite(n, prerequisites, queries);
        copy(begin(res), end(res), ostream_iterator<bool>(cout, ", "));
        cout << endl;
    }

    {
        // Output: {false,true}
        Solution sol;
        n = 3, prerequisites = {{1,0},{2,0}}, queries = {{0,1},{2,0}};
        res = sol.checkIfPrerequisite(n, prerequisites, queries);
        copy(begin(res), end(res), ostream_iterator<bool>(cout, ", "));
        cout << endl;
    }

    {
        // Output: {true,false,true,false}
        Solution sol;
        n = 5, prerequisites = {{0,1},{1,2},{2,3},{3,4}}, queries = {{0,4},{4,0},{1,3},{3,0}};
        res = sol.checkIfPrerequisite(n, prerequisites, queries);
        copy(begin(res), end(res), ostream_iterator<bool>(cout, ", "));
        cout << endl;
    }
    
    return 0;
}
