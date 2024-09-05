class Solution {
    vector<vector<int>> adj;
    vector<int> ans;
    vector<bool> vis;
    vector<int> numNodes;
    int n;

    pair<int, int> dfs1(int u) {
        vis[u] = true;

        pair<int, int> ret = make_pair(0, 1);
        for (int v : adj[u]) {
            if (!vis[v]) {
                auto [sumDist, numOfNodes] = dfs1(v);
                ret.first += (sumDist + numOfNodes);
                ret.second += numOfNodes;
            }
        }

        numNodes[u] = ret.second;
        return ret;
    }

    void dfs2(int u, int sumParent) {
        vis[u] = true;

        if (u != 0)
            ans[u] = sumParent - numNodes[u] + (n - numNodes[u]);
        else
            ans[u] = sumParent;

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs2(v, ans[u]);
            }
        }
    }

  public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        adj.resize(n, vector<int>());
        this->n = n;
        for (auto v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vis.resize(n, false);
        numNodes.resize(n, -1);
        auto [sumDist, numOfNodes] = dfs1(0);

        ans.resize(n, -1);
        vis.clear();
        vis.resize(n, false);
        dfs2(0, sumDist);

        return ans;
    }
};
