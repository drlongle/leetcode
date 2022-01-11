/*
Let deg[i] be the degree of node i. For node u and v, the answer is deg[u] + deg[v] if they are not connected,
and deg[u] + dev[v] - 1 otherwise.

Let first be the greatest degree, second be the second greatest degree (first and second can be the same
if there are multiple nodes with the largest degree). We just need to consider the cities with first and
second degrees because:

The result of selecting from such nodes is at least first + second - 1 (when they are connected).
If we select a city with degree x < second, then the result is at best first + x < first + second,
i.e. first + x <= first + second - 1, which is no better than selecting from first and second
So, selecting from first and second must be optimal.

Let x be the number of cities with first degree. So there are  ${x \choose 2 } = \frac{x(x-1)}{2}$ pairs
among these cities. Let m be the number of roads.

- If x = 1, then we must pick a city from the cities with second degree. Enumerating such cities takes O(n) time.
- If x > 1 and ${x\choose 2} > m$, then the roads don't cover all the possible connections between those first
  degree cities, so there must be a pair of first degree cities unconnected. Picking them results in first * 2.
- IF x > 1 and ${x\choose 2} <= m$, then we don't need to consider second degree city because its result
  first + second must be no better than the result of picking two first degree cities, first + first - 1.
  We just need to enumerate all the city pairs among first degree cities, which takes O(x * (x-1) / 2) = O(m) time.
 */

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& A) {
        if (A.empty()) return 0;
        vector<unordered_set<int>> G(n);
        vector<int> deg(n), firstNodes, secondNodes;
        for (auto &e : A) {
            int u = e[0], v = e[1];
            G[u].insert(v);
            G[v].insert(u);
            deg[u]++;
            deg[v]++;
        }
        int first, second, m = A.size();
        for (int d : deg) {
            if (d > first) {
                second = first;
                first = d;
            } else if (d > second) second = d;
        }
        for (int i = 0; i < n; ++i) {
            if (deg[i] == first) firstNodes.push_back(i);
            else if (deg[i] == second) secondNodes.push_back(i);
        }
        if (firstNodes.size() == 1) {
            int u = firstNodes[0];
            for (int v : secondNodes) {
                if (G[u].count(v) == 0) return first + second;
            }
            return first + second - 1;
        } else {
            if (firstNodes.size() * (firstNodes.size() - 1) / 2 > m) return first * 2;
            for (int i = 0; i < firstNodes.size(); ++i) {
                for (int j = i + 1; j < firstNodes.size(); ++j) {
                    if (G[firstNodes[i]].count(firstNodes[j]) == 0) return first * 2;
                }
            }
            return first * 2 - 1;
        }
    }
};
