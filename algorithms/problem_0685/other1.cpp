class Solution {
  public:
    map<int, set<int>> adj;
    set<int> s, st;
    map<int, int> indegree;

    bool dfs(int node, int parent) {
        s.insert(node);
        st.insert(node);

        for (auto it : adj[node]) {
            if (s.count(it) == 0) {
                if (dfs(it, node)) {
                    return true;
                }
            } else if (st.count(it)) {
                return true;
            }
        }
        st.erase(node);
        return false;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int i, j;
        int n = edges.size();
        vector<int> v;
        vector<pair<int, int>> temp;

        for (i = 0; i < n; i++) {
            adj[edges[i][0]].insert(edges[i][1]);
            indegree[edges[i][1]]++;
        }

        // storing those edges those having nodes with indegree>1

        for (i = 0; i < n; i++) {
            if (indegree[edges[i][1]] > 1) {
                temp.push_back({edges[i][0], edges[i][1]});
            }
        }

        // checking for those nodes having indegree >1

        for (i = temp.size() - 1; i >= 0; i--) {
            int x = temp[i].first;
            int y = temp[i].second;

            adj[x].erase(y);

            bool flag = true;

            for (j = 1; j <= n; j++) {
                if (s.count(j) == 0) {
                    if (dfs(j, -1)) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                v.push_back(x);
                v.push_back(y);
                return v;
            }

            adj[x].insert(y);

            s.clear();
            st.clear();
        }

        // checking for rest if no node is having indegree >1

        for (i = n - 1; i >= 0; i--) {
            int x = edges[i][0];
            int y = edges[i][1];

            adj[x].erase(y);

            bool flag = true;

            for (j = 1; j <= n; j++) {
                if (s.count(j) == 0) {
                    if (dfs(j, -1)) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                v.push_back(x);
                v.push_back(y);
                return v;
            }

            adj[x].insert(y);

            s.clear();
            st.clear();
        }

        return v;
    }
};
