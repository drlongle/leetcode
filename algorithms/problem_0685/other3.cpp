class Disjoint_Sets {
  private:
    int V;
    vector<int> parent;
    vector<int> rank;

  public:
    Disjoint_Sets(int V) {
        this->V = V;
        parent.resize(V);
        rank.resize(V);
        for (int i = 1; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = findParent(parent[v]);
    }
    bool merge(int u, int v) {
        int parent_u = findParent(u);
        int parent_v = findParent(v);
        if (parent_u == parent_v) {
            return true;
        }
        if (rank[parent_u] == rank[parent_v]) {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        } else if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        } else if (rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        }
        return false;
    }
};

class Solution {
  public:
    vector<int> isCycle(vector<vector<int>> &edges,
                        vector<int> edgeDoNotConsider) {
        int V = edges.size();
        Disjoint_Sets ds(V + 1);
        for (auto edge : edges) {
            if (edge[0] == edgeDoNotConsider[0] &&
                edge[1] == edgeDoNotConsider[1]) {
                continue;
            }
            if (ds.merge(edge[0], edge[1]) ==
                true) { // cycle found while merging edge[0] and edge[1]
                return {edge[0], edge[1]};
            }
        }
        return {-1, -1};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int V = edges.size();
        vector<int> inDegree(V + 1, 0);
        int TwoParentNode = -1;
        for (auto edge : edges) {
            inDegree[edge[1]]++;
            if (inDegree[edge[1]] == 2) {
                TwoParentNode = edge[1];
            }
        }
        if (TwoParentNode == -1) { // if there is no two parent Node, start
                                   // finding cycle from root
            return isCycle(edges, {-1, -1}); // find from root
        }

        vector<int> res;
        for (auto edge : edges) {
            if (edge[1] == TwoParentNode) {
                vector<int> temp = isCycle(edges, edge);
                if (temp[0] == -1 &&
                    temp[1] ==
                        -1) { // no cycles were found when we avoided this edge
                    res = edge;
                }
            }
        }
        return res;
    }
};
