class Solution {
public:
    unordered_map<int, pair<int, vector<int>>> g;

    bool BFS(int node) {
        queue<pair<int, int>> q;
        g[node].first = 1;
        q.emplace(node, 1);
        while (q.size()) {
            auto [id, d] = q.front();
            q.pop();
            for (int nid: g[id].second) {
                if (g[nid].first == 0) {
                    g[nid].first = -d;
                    q.emplace(nid, -d);
                } else if (g[nid].first == d)
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        for (int i = 0, n = graph.size(); i < n; ++i) {
            auto& e = graph[i];
            for (int j: e) {
                g[i].second.push_back(j);
                g[j].second.push_back(i);
            }

        }

        for (auto& e: g) {
            if (e.second.first == 0) {
                if (!BFS(e.first))
                    return false;
            }
        }

        return true;
    }
};