/*
886. Possible Bipartition
Medium

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.

Example 1:
Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]

Example 2:
Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false

Note:
1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].
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

    unordered_map<int, unordered_set<int>> neighs;
    vector<int> visited;

    bool visit(int id, int bit) {
        if (visited[id] != 0)
            return visited[id] == 1 << bit;
        visited[id] = 1 << bit;
        for (int nid: neighs[id]) {
            if (!visit(nid, 1 - bit))
                return false;
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        visited.resize(N+1, 0);
        for (auto& dislike: dislikes) {
            int i = dislike[0], j = dislike[1];
            neighs[i].emplace(j);
            neighs[j].emplace(i);
        }

        for (int id = 1; id <= N; ++id) {
            if (visited[id] == 0 && !visit(id, 0))
                return false;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> dislikes;
    int N;

    // Output: true
    {
        Solution sol;
        N = 4, dislikes = {{1,2},{1,3},{2,4}};
        cout << boolalpha << sol.possibleBipartition(N, dislikes) << endl;
    }
    
    // Output: false
    {
        Solution sol;
        N = 3, dislikes = {{1,2},{1,3},{2,3}};
        cout << boolalpha << sol.possibleBipartition(N, dislikes) << endl;
    }
    
    // Output: false
    {
        Solution sol;
        N = 5, dislikes = {{1,2},{2,3},{3,4},{4,5},{1,5}};
        cout << boolalpha << sol.possibleBipartition(N, dislikes) << endl;
    }
    
    return 0;
}
