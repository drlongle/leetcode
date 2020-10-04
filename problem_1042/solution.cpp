/*
1042. Flower Planting With No Adjacent
Easy

You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path,
they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.
The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

Example 1:
Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]

Example 2:
Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]

Example 3:
Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]

Note:
1 <= N <= 10000
0 <= paths.size <= 20000
No garden has 4 or more paths coming into or leaving it.
It is guaranteed an answer exists.
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
#include <regex>
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

    vector<int> color;
    vector<vector<int>> graph;

    void dfs(int id) {
        unordered_set<int> choices{1, 2, 3, 4};
        for (int nid: graph[id])
            if (color[nid] > 0) {
                choices.erase(color[nid]);
            }
        color[id] = *choices.begin();
        for (int nid: graph[id])
            if (color[nid] == 0)
                dfs(nid);
    }

    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        color.resize(N, 0);
        graph.resize(N);
        for (auto& path: paths) {
            graph[path[0]-1].emplace_back(path[1]-1);
            graph[path[1]-1].emplace_back(path[0]-1);
        }

        for (int i = 0; i < N; ++i)
            if (color[i] == 0)
                dfs(i);

        return color;
    }
};

int main() {
    vector<vector<int>> paths;
    vector<int> color;
    int N;

    // Output: {1,2,3}
    {
        Solution sol;
        N = 3, paths = {{1,2},{2,3},{3,1}};
        color = sol.gardenNoAdj(N, paths);
        copy(begin(color), end(color), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: {1,2,1,2}
    {
        Solution sol;
        N = 4, paths = {{1,2},{3,4}};
        color = sol.gardenNoAdj(N, paths);
        copy(begin(color), end(color), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    // Output: {1,2,3,4}
    {
        Solution sol;
        N = 4, paths = {{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}};
        color = sol.gardenNoAdj(N, paths);
        copy(begin(color), end(color), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }

    return 0;
}
