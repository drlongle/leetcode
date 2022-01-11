class Solution {
public:
    void dfs(vector< vector<int> >graph, vector<int> &visited,int src,bool &flag, int clr,int parent )
    {
        visited[src]=clr;
        for(auto node:graph[src])
        {
            if(!visited[node])
                dfs(graph,visited,node,flag,3-clr,src);
            else if(node!=parent)
            {
                if(visited[node]==clr){ flag=false; return ;}
            }
        }

    }

    bool isBipartite(vector<vector<int>>& graph) {
        bool flag=true;
        vector<int> visited(graph.size(),0);
        for(int x=0;x<graph.size();x++)
        {   if(!visited[x])
            {
                dfs(graph,visited,x,flag,1, x);
                if(flag==false) return false;
            }
        }
        return true;
    }
};