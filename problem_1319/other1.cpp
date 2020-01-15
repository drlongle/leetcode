class UnionFind {
private:
    vector<int> rank;
    vector<int> parent;
    int count;
public:
    UnionFind(int n) : parent(n, 0), rank(n, 0) {
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int get_count() {
        return count;
    }
    
    int find(int i) {
        while (i != parent[i]) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        
        return i;
    }
    
    void join(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);
        if (rootp == rootq) return;
        if (rank[rootp] < rank[rootq]) {
            parent[rootp] = rootq;
        }
        else {
            parent[rootq] = rootp;
            if (rank[rootp] == rank[rootq]) {
                rank[rootp]++;
            }
        }
        
        count--;
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size()+1) return -1;
        UnionFind uf(n);
        for (auto c : connections) {
            uf.join(c[0], c[1]);
        }
        return uf.get_count()-1;
    }
};
