/*
The main idea is it can be proven that at most 2 mids exist in tree for minimum height now the solution can be reduced
to finding longest path in tree and returning its mid if length of path is odd or return mid two if length is even.
First find farthest node from any arbitrary node via dfs (that may not give longest path). In order to get longest path,
again do dfs from the farthest node to search most farthest node and that will be the solution for longest path. Hence,
return the mids of that path.
*/

class Solution {
public:
    int mxlen;
    int mx,mxel1,mxel2;
    vector<int> res;
    vector<int>cpath;
    void dfs(int cur, int dist, vector<int>graph[],bool vis[]){
        vis[cur]=1;
        if(dist>mx){
            mx=dist;
            mxel1=cur;
        }
        for(auto i:graph[cur]){
            if(vis[i]==false)
                dfs(i,dist+1,graph,vis);
        }
    }
    void dfs2(int cur, int dist, vector<int>graph[],bool vis[]){
        vis[cur]=1;
        if(dist>mx){
            mx=dist;
            mxel2=cur;
        }
        for(auto i:graph[cur]){
            if(vis[i]==false)
                dfs2(i,dist+1,graph,vis);
        }
    }
    void findp(int cn, int ed, vector<int> cur,bool vis[],vector<int>graph[]){
        if(cn==ed){
            cur.push_back(ed);
            cpath=cur;
            return;
        }
        vis[cn]=true;
        cur.push_back(cn);
        for(auto i:graph[cn]){
            if(vis[i]==false)
                findp(i,ed,cur,vis,graph);
        }
        cur.pop_back();
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        res.clear();
        vector<int> graph[n];
        mxel1=-1;
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        mxlen=0;
        mx=0;
        if(n==0)
            return res;
        if(n==1) {
            res.push_back(0);
            return res;
        }
        if(n==2){
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        bool vis[n];
        memset(vis,0,sizeof(vis));
        dfs(0,0,graph,vis);

        memset(vis,0,sizeof(vis));
        dfs2(mxel1,0,graph,vis);

        vector<int>cur;
        memset(vis,0,sizeof(vis));
        findp(mxel1,mxel2,cur,vis,graph);
        int csz=cpath.size();
        if(csz%2==0){
            res.push_back(cpath[csz/2]);
            res.push_back(cpath[csz/2 -1]);
        }else{
            res.push_back(cpath[csz/2]);
        }
        return res;
    }
};
