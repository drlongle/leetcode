class TreeAncestor {
    int h;
    vector<vector<int>>store;
public:
    TreeAncestor(int n, vector<int>& parent) {
        h = (int)ceil(log2(n));
        store.resize(n+1, vector<int>(h+1, -1));
        
        for (int i = 1; i < n; i++) {
            store[i][0] = parent[i];
            for (int j = 1; j <= h; j++) {
                store[i][j] = store[store[i][j-1]][j-1];
                if (store[i][j] == -1)
                    break;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i <= h; i++) { 
            if (k & (1 << i)) {
                node = store[node][i];
                if (node == -1) 
                    break; 
            }
        }
    
        return node;
    }
};
