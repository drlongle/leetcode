class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);

        for (const auto& c : connections) {
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }

        vector<int> minDepth(n);

        dfs(g, minDepth, 0, -1, 1);

        return ans;
    }

    void dfs(vector<vector<int>>& g, vector<int>& minDepth, int cur, int prev, int depth) {
        minDepth[cur] = depth;

        for (auto n : g[cur]) {
            if (minDepth[n] == 0) {
                dfs(g, minDepth, n, cur, depth + 1);
            }

            if (n != prev) {
                minDepth[cur] = min(minDepth[cur], minDepth[n]);
            }
        }

        if (prev != -1 && minDepth[cur] == depth) {
            ans.push_back({cur, prev});
        }
    }
};
