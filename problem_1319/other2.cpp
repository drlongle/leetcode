class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size()+1) return -1;
        //build graph
        vector<vector<int>> graph(n);
        for (auto &c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        vector<int> seen(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (seen[i] == 0) {
                seen[i]++;
                dfs(i, graph, seen);
                count++;
            }
        }
        
        return count-1;
    }
    
    void dfs(int i, vector<vector<int>>& graph, vector<int>& seen) {
        for (auto &adj : graph[i]) {
            if (seen[adj] == 0) {
                seen[adj]++;
                dfs(adj, graph, seen);
            }
        }
    }
};
