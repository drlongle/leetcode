class Solution {
public:
    int count=0; //globally declared count
    int minReorder(int n, vector<vector<int>>& con) {
        vector<int> adj[n]; //for simplicity creating a adjacency list
        for (auto i : con)
            adj[i[0]].push_back(i[1]);
        vector<bool> visited(n+1,0); //to keep track of visited nodes
        for(int i=0;i<n;i++){
            if (!visited[i]) //only visiting nodes not already visited.
                dfs(adj,visited,i);
        }
        return count;
    }

    void dfs(vector<int> adj[],vector<bool>& visited,int u){
        visited[u]=true; //marking unvisited node as visited but not increasing count as it might lead us to a path
        for (int v : adj[u]){
            if (!visited[v]){// if we encounter it's neighbour not leading us to path then we have to flip it
                count++; 
                dfs(adj,visited,v); //recursively calling for each 
            }
        }
    }
};
