class Solution {
  public:
    vector<set<int>> graph;
    vector<int> indegree;
    bool canFinish(int n, vector<vector<int>> &prerequisites) {
        graph.resize(n);
        indegree.resize(n, 0);
        for (auto &p : prerequisites) {
            graph[p[1]].insert(p[0]);
            ++indegree[p[0]];
        }

        int courses = 0;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
                ++courses;
            }
        }

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : graph[i]) {
                if (--indegree[j] == 0) {
                    ++courses;
                    q.push(j);
                }
            }
        }

        return courses == n;
    }
};
