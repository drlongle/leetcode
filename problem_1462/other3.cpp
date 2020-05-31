class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int source, int c){
        graph[source][c] = 1;

        if(!vis[c]){
            vis[c] = true;
            for(int i = 0; i < graph[c].size(); i++){
                if(graph[c][i]){
                    dfs(graph, vis, source, i);
                }
            }
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        int i, j, u, v;
        for(i = 0; i < pre.size(); i++){
            graph[pre[i][0]][pre[i][1]] = 1;
        }
        
        for(i = 0; i < n; i++){
            vector<bool> vis(n, false);
            dfs(graph, vis, i, i);
            
        }
        
        vector<bool> res(queries.size(), false);
        for(i = 0; i < queries.size(); i++){    
            res[i] = graph[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};
