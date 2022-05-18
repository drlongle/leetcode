class dsu {
    vector<int> parent;

  public:
    dsu(int n) {
        for (int i = 0; i < n + 1; i++)
            parent.push_back(i);
    }
    int findPar(int n) {
        int p = n;
        while (parent[p] != p) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    bool unionRank(int n, int m) {
        int p1 = findPar(n);
        int p2 = findPar(m);
        if (p1 == p2)
            return false;
        parent[p2] = p1;
        return true;
    }
};
class Solution {
  public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        int a = -1, b = -1;
        dsu d(n);
        vector<int> ans;
        vector<int> indegre(n + 1, -1);
        for (int i = 0; i < n; i++) {
            if (indegre[edges[i][1]] != -1) {
                b = indegre[edges[i][1]];
                a = i;
                break;
            }
            indegre[edges[i][1]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (i == a)
                continue;
            if (d.unionRank(edges[i][0], edges[i][1]) == false) {
                if (a == -1) {
                    ans.push_back(edges[i][0]);
                    ans.push_back(edges[i][1]);
                    return ans;
                } else {
                    ans.push_back(edges[b][0]);
                    ans.push_back(edges[b][1]);
                    return ans;
                }
            }
        }
        ans.push_back(edges[a][0]);
        ans.push_back(edges[a][1]);
        return ans;
    }
};
