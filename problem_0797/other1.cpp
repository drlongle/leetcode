class Solution {
public:
    void doDFS(unordered_map<int , unordered_set<int>>&graph
               ,vector<vector<int>>* paths
               ,vector<int>& tempPath
               ,int vertex
               ,int dest )
    {
        if(vertex == dest)
        {
            paths->emplace_back(tempPath);
            return;
        }
    
        for(int neighbourVertex : graph[vertex])
        {
            {
                tempPath.push_back(neighbourVertex);
                doDFS(graph , paths ,tempPath, neighbourVertex , dest );
                tempPath.pop_back();
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int , unordered_set<int>> map_graph;
        for(int i = 0 ; i < graph.size() ; i++)
        {
            for(auto vertex: graph[i])
                map_graph[i].emplace(vertex);
        }
    
        vector<vector<int>> paths;
        vector<int> temp;
        temp.push_back(0);
        doDFS(map_graph , &paths , temp , 0, graph.size() -1 );
        return paths;
    }
};
