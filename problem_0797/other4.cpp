class Solution {
public:
    int n;
    vector<vector<int>> res;
    void visit(int id, vector<vector<int>>& graph, vector<int> &path) {
        path.push_back(id);
        if (id == n-1)
            res.emplace_back(path);
        for (int nid: graph[id]) {
            visit(nid, graph, path);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> path;
        visit(0, graph, path);
        return res;
    }
};