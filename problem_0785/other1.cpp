class Solution {
public:

    bool dfs(int node,vector<int> &vis,int parent,int color,vector<vector<int>>& graph){
        //coloring the unvisited nodes
        if(!vis[node]) vis[node]=color;
        for(auto x:graph[node]){
            if(!vis[x]){
                dfs(x,vis,node,3-color,graph);

                //check whether a neighbouring node 'x' is visited ,not a parent of node and have the same color as node
            }else if(x!=parent and vis[x]==vis[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> vis(n,0);
        bool ans=1;
        for(int i=0;i<n;i++){
            ans=ans&dfs(i,vis,-1,1,graph);
        }
        return ans;
    }
};
