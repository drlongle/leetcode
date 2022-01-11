class Solution {
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        vector<int> ret;
        unordered_map<int, int> inDegree;
        unordered_map<int, unordered_set<int>> graph;
        int index = 0;
        for (auto& seq : seqs){
            int n = seq.size();
            if (n == 0){
                continue;
            }
            //handles the case when there is only one node with no neighbors
            if (n == 1 && !graph.count(seq[0])){
                graph[seq[0]] = {};
            }
            for (int i = 0; i < seq.size() - 1; ++ i){
                if (!graph.count(seq[i + 1])){
                    graph[seq[i + 1]] = {};
                }
                graph[seq[i]].insert(seq[i + 1]);
            }
        }
        // number of nodes are not the same
        if (graph.size() != org.size()){
            return false;
        }
        for (auto it = graph.begin(); it != graph.end(); ++ it){
            int node = it->first;
            auto neighbors = it->second;
            for (int nei : neighbors){
                inDegree[nei] ++;
            }
        }
        queue<int> q;
        for (auto it = graph.begin(); it != graph.end(); ++it){
            int node = it->first;
            if (!inDegree.count(node)){
                if (ret.empty()){
                    if (index >= org.size() || node != org[index++]){
                        return false;
                    }
                    ret.push_back(node);
                    q.push(node);
                }
                else{
                    return false;
                }
            }
        }
        while (!q.empty()){
            int t = q.front();
            q.pop();
            int cnt = 0;
            for (int nei : graph[t]){
                if (--inDegree[nei] == 0){
                    cnt ++;
                    if (cnt > 1 || index >= org.size() || nei != org[index ++]){
                        return false;
                    }
                    ret.push_back(nei);
                    q.push(nei);
                }
            }
        }

        return ret.size() == org.size();
    }
};
