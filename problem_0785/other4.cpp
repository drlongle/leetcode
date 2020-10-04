class Solution {
    inline bool bfs(int start, const vector<vector<int>>& graph, vector<int>& colors) const noexcept {

        queue<int> q;

        colors[start] = 1;
        q.push(start);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            auto cur_color = 1 - colors[node];

            for(auto a: graph[node]) {
                if(colors[a] == -1) {
                    colors[a] = cur_color;
                    q.push(a);
                } else if(colors[a] != cur_color)
                    return false;
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), -1);

        for(int i = 0; i < graph.size(); ++i) {
            if(colors[i] == -1)
                if(!bfs(i, graph, colors))
                    return false;
        }

        return true;
    }
};
