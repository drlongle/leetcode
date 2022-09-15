class Solution {
  public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        vector<int> par(graph.size()), sz(graph.size(), 1);
        for (int i = 0; i < graph.size(); i++) {
            par[i] = i;
        }
        function<int(int)> find = [&](int x) {
            if (par[x] == x)
                return x;
            return find(par[x]);
        };
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[0].size(); j++) {
                if (graph[i][j]) {
                    int f1 = find(i);
                    int f2 = find(j);
                    if (f1 == f2)
                        continue;
                    par[f2] = f1;
                    sz[f1] += sz[f2];
                }
            }
        }
        unordered_map<int, int> mp;
        sort(initial.begin(), initial.end());
        for (int i = 0; i < initial.size(); i++) {
            int f = find(initial[i]);
            mp[f]++;
        }
        int res = initial[0];
        int mx = 0;
        for (int i = 0; i < initial.size(); i++) {
            int f = find(initial[i]);
            if (mp[f] == 1) {
                if (sz[f] > mx) {
                    mx = sz[f];
                    res = initial[i];
                }
            }
        }
        return res;
    }
};
