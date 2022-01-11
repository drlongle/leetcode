/*
743. Network Delay Time
Medium

There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
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

namespace std {
    template <> struct hash<pair<int, int>> {
        size_t operator() (const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, unordered_set<pair<int, int>>> graph;
        for (auto& edge: times) {
            graph[edge[0]].emplace(edge[1], edge[2]);
        }

        vector<int> visited(N+1, numeric_limits<int>::max());
        queue<pair<int, int>> q;
        q.emplace(K, 0);
        int res = 0;
        while (!q.empty()) {
            auto [id, delay] = q.front();
            q.pop();
            if (visited[id] <= delay)
                continue;
            visited[id] = delay;
            res = max(res, delay);
            for (auto& edge: graph[id]) {
                if (delay + edge.second < visited[edge.first])
                    q.emplace(edge.first, delay + edge.second);
            }

        }
        int cnt = std::count(visited.begin()+1, visited.end(), numeric_limits<int>::max());
        return cnt != 0 ? -1 : *max_element(visited.begin()+1, visited.end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> times;
    int N, K;

    times = {{1,2,1},{2,3,2},{1,3,4}};
    N = 3, K = 1;
    cout << sol.networkDelayTime(times, N, K) << endl;
    
    return 0;
}
