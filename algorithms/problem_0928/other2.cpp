class Solution {
  public:
    vector<vector<int>> adj;
    int infectedCnt;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int src, vector<int> &visited) {
        visited[src] = true;

        infectedCnt++;

        for (auto &nbr : adj[src]) {
            if (visited[nbr] == false) {
                dfs(nbr, visited);
            }
        }
    }

    int ans = -1, minInfected = INT_MAX;
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        int v = graph.size();
        adj.resize(v);
        sort(initial.begin(), initial.end());

        // adj matrix to adj list
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[0].size(); j++) {
                if (graph[i][j] == 1) {
                    addEdge(i, j);
                }
            }
        }
        // now dfs
        for (auto &x : initial) {
            // picking infectedes one by one
            vector<int> visited(v, 0);
            int currInfected = x;
            //! trick part
            // pre marking curr infected as true to virtually remove its edges.
            visited[currInfected] = true;
            infectedCnt = 0;

            for (auto &x : initial) {
                // calling dfs for rest of infecteds and counting how many safe
                // can get infected by them.
                if (visited[x] == false) {
                    dfs(x, visited);
                }
            }
            if (infectedCnt < minInfected) {
                ans = x;
                minInfected = infectedCnt;
            }
        }

        return ans;
    }
};
