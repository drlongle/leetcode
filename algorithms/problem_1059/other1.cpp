class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int> visited(n, -1);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
        }
        return dfs(graph, visited, source, destination);
    }

    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int i, int dest){
        if(graph[i].size() == 0) return i == dest;
        if(visited[i] != -1) return visited[i];
        visited[i] = 0;
        for(auto next : graph[i]){
            if(!dfs(graph, visited, next, dest)) return false;
        }
        visited[i] = 1;
        return true;
    }
};
