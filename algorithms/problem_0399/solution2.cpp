class Solution {
  public:
    map<string, vector<pair<double, string>>> g;

    set<string> visited;
    double res;
    void dfs(string &curr, string &dest, double val) {
        if (!visited.insert(curr).second)
            return;
        if (dest == curr) {
            res = val;
            return;
        }
        for (auto &p : g[curr]) {
            dfs(p.second, dest, p.first * val);
        }
    }

    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        int n = equations.size();
        for (int i = 0; i < n; ++i) {
            string &a = equations[i][0];
            string &b = equations[i][1];
            double val = values[i];
            g[a].emplace_back(val, b);
            g[b].emplace_back(1.0 / val, a);
        }
        vector<double> r;
        for (auto &q : queries) {
            res = -1;
            visited.clear();
            if (g.count(q[0]) == 0 || g.count(q[1]) == 0)
                r.emplace_back(-1.0);
            else if (q[0] == q[1])
                r.emplace_back(1.0);

            else {
                dfs(q[0], q[1], 1.0);
                r.emplace_back(res);
            }
        }

        return r;
    }
};
