class Solution {
public:
    unordered_map<int, int> root;

    int get_root(int n) {
        root.emplace(n, n);
        while (true) {
            int r = root[n];
            if (r == n)
                break;
            n = r;
        }
        return n;
    }

    void join_root(int n, int r) {
        while (true) {
            int& p = root[n];
            if (p == r)
                break;
            n = p;
            p = r;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        for (auto& edge: edges) {
            int a = edge[0], b = edge[1];
            int ra = get_root(a), rb = get_root(b);
            if (ra == rb)
                res = edge;
            else if (ra < rb)
                join_root(b, ra);
            else
                join_root(a, rb);
        }

        return res;
    }
};