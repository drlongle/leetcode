class Solution {
  private:
    vector<int> root;

    int find(int x) {
        if (root[x] == x)
            return x;
        root[x] = find(root[x]);
        return root[x];
    }

    void un(int x, int y) {
        int rx = find(x), ry = find(y);
        root[rx] = ry;
    }

  public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        int n = graph.size();
        root.resize(n, 0);
        for (int i = 0; i < n; ++i)
            root[i] = i;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (graph[i][j]) {
                    un(i, j);
                }
            }
        }

        // for each "root", count how many nodes are connected to this root.
        unordered_map<int, int> group;
        for (int i = 0; i < n; ++i) {
            int r = find(i);
            group[r]++;
        }

        unordered_map<int, vector<int>> mp;
        for (auto &a : initial) {
            int r = find(a);
            mp[r].push_back(a);
        }

        // 2 scenarios to consider:
        // 1) There are more than 1 nodes in "initial" that are connected to the
        // same node, removing them won't change the result. 2) There is only 1
        // node in "initial" that are connected to the root.
        int red = n, nored = n, mx = 0;
        for (auto &[k, v] : mp) {
            if (v.size() > 1) {
                for (auto &b : v)
                    nored = min(nored, b);
            } else {
                if (group[k] > mx || (group[k] == mx && v[0] < red)) {
                    red = v[0];
                    mx = group[k];
                }
            }
        }

        return mx > 0 ? red : nored;
    }
};
