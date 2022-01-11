class Solution {
    bool wrongPath = false;
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        for (vector<int>& e : edges) {
            adjList[e[0]].push_back(e[1]);
        }
        if (adjList[destination].size() != 0) return false;
        unordered_set<int> pathvisited;
        dfs(pathvisited, source, destination, adjList, visited);
        return !wrongPath;
    }

    void dfs(unordered_set<int>& pathvisited, int start, int dest, vector<vector<int>>& adjList, vector<bool>& visited) {
        if (start == dest || wrongPath) return;
        if (adjList[start].size() == 0 && start != dest) {
            wrongPath = true; // get stuck at another sinking node
            return;
        }
        for (int next : adjList[start]) {
            if (pathvisited.find(next) != pathvisited.end()) {
                wrongPath = true; // cycle detected
                return;
            }
            if (visited[next] == false) {
                pathvisited.insert(next);
                dfs(pathvisited, next, dest, adjList, visited);
                pathvisited.erase(next);
                visited[next] = true;
            }
        }
    }
};
