class Solution {
public:

    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> indegree(n, 0);
        unordered_set<int> candidates, next_candidates;
        vector<vector<int>> graph(n);
        int remain = n, rounds = 0;
        for (int i = 0; i < n; ++i)
            candidates.emplace(i);
        for (auto& rel: relations) {
            int u = rel[0]-1, v = rel[1]-1;
            graph[u].push_back(v);
            ++indegree[v];
            candidates.erase(v);
        }

        while (remain > 0) {
            ++rounds;
            if (candidates.empty())
                return -1;
            for (int cand: candidates) {
                for (int v: graph[cand]) {
                    if (--indegree[v] == 0) {
                        next_candidates.insert(v);
                    }
                }
                --remain;
            }
            candidates.clear();
            swap(candidates, next_candidates);
        }

        return rounds;
    }
};