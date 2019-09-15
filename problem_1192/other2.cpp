const int MAXN=100010;
const int MAXM=100010;

class Solution {

    int Head[MAXN], Next[MAXM*2], To[MAXM*2]; 
    int n,tot;
    int dfn[MAXN],low[MAXN];
    
    int numIndex,numCutedge;
    struct Edge{
        int u,v;
    } cutedge[MAXM];

    void Tarjan(int u,int pre = -1) {
        if(dfn[u] != -1) return;
        dfn[u] = low[u] = ++numIndex;
        
        for (int i = Head[u]; i != -1; i = Next[i]) {
            int v=To[i];
            if(v == pre)continue;
            Tarjan(v, u);
            
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                cutedge[numCutedge++] = {u, v};
            } 
        }
    }
    
    void solve(){
        memset(dfn,-1,sizeof(dfn));
        memset(low,-1,sizeof(low));
        numCutedge = 0;
        numIndex = 0;
        Tarjan(0);
    }
    void Outit(vector<vector<int>>& ans){
        for (int i = 0; i < numCutedge; i++){
            ans.push_back({cutedge[i].u,cutedge[i].v});
        }
    }
    void add_eage(int x, int y){
        tot++;
        Next[tot] = Head[x];
        Head[x] = tot;
        To[tot] = y;
    }
    void ReadInfo(int n, vector<vector<int>>& conn){
        memset(Head, -1, sizeof(Head));
        tot = 0;
        this->n = n;
        for(auto&v: conn){
            int x = v[0];
            int y = v[1];
            add_eage(x,y); 
            add_eage(y,x);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        ReadInfo(n, conn);
        solve();
        
        vector<vector<int>> ans;
        Outit(ans);
        return ans;
    }
};
