class Solution {
  public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        int n = graph.size();
        unordered_map<int, vector<int>> count;
        vector<bool> is_infected(n);
        for (int &u : initial)
            is_infected[u] = 1;
        for (int &u : initial) {
            vector<bool> visited(n);
            queue<int> q;
            q.push(u);
            while (q.size()) {
                int v = q.front();
                q.pop();
                for (int i = 0; i < n; i++) {
                    if (graph[v][i] == 0 or visited[i] or is_infected[i])
                        continue;
                    visited[i] = 1;
                    count[i].push_back(u);
                    q.push(i);
                }
            }
        }
        vector<int> ans(n);
        for (auto &[u, arr] : count) {
            if (arr.size() == 1)
                ans[arr.front()]++;
        }
        int mxm = *max_element(ans.begin(), ans.end());
        if (mxm == 0) {
            return *min_element(initial.begin(), initial.end());
        }
        return find(ans.begin(), ans.end(), mxm) - ans.begin();
    }
};
