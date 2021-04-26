class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        std::vector<std::vector<int>> adj(n);
        std::vector<bool> visited(n, false);
        for(const auto &e: edges) adj[e[0]].emplace_back(e[1]);
        if(!adj[destination].empty()) return false;
        return dfs(adj, visited, source, destination);
    }

    bool dfs(std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int cur, int dest) {
        if(cur == dest) return true;
        if(adj[cur].empty() || visited[cur]) return false;
        visited[cur] = true;
        for(const auto &n: adj[cur]) {
            if(!dfs(adj, visited, n, dest)) return false;
        }
        visited[cur] = false;
        return true;
    }
};
