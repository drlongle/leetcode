
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> current, seen(graph.size());
        vector<vector<int>> result;
        
        function<void(int)> dfs = [&](int idx){
            if (seen[idx]) return;
            current.push_back(idx);
            seen[idx] = 1;
            if (idx == graph.size()-1) 
                result.push_back(current);
            else 
                for_each(graph[idx].begin(), graph[idx].end(), dfs);
            current.pop_back();
            seen[idx] = 0;
        };
        
        dfs(0);
        return result;
    }
};
