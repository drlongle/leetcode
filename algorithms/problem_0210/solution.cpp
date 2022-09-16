class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {

        vector<set<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<int> res;

        for (auto &p : prerequisites) {
            graph[p[1]].insert(p[0]);
            ++indegree[p[0]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : graph[i]) {
                if (--indegree[j] == 0) {
                    q.push(j);
                    res.push_back(j);
                }
            }
        }

        return res.size() == n ? res : vector<int>();
    }
};
