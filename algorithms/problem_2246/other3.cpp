class Solution {
  public:
    int longestPath(vector<int> &parent, string s) {
        int n = parent.size();
        vector<vector<int>> t(n);

        for (int i = 0; i < n; i++) {
            if (parent[i] != -1)
                t[parent[i]].push_back(i);
        }

        int d = 0;
        recur(t, s, d, 0);
        return d;
    }

    int recur(vector<vector<int>> &t, string &str, int &d, int u) {
        int f = 0, s = 0;

        for (int v : t[u]) {
            int tmp = recur(t, str, d, v);
            if (tmp > f && str[u] != str[v]) {
                s = f;
                f = tmp;
            } else if (tmp > s && str[u] != str[v]) {
                s = tmp;
            }
        }
        d = max(d, 1 + f + s);
        return 1 + f;
    }
};
