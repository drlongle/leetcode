class Solution {
  public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {

        sort(initial.begin(), initial.end());
        int ans = -1, mn = INT_MAX, n = graph.size();

        vector<vector<int>> new_graph(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][j])
                    new_graph[i].push_back(j);

        for (auto &k : initial) {
            vector<int> dsu(n, -1);
            for (int i = 0; i < n; i++)
                for (auto &j : new_graph[i])
                    if (i != k && j != k) {
                        int a = findParent(dsu, i), b = findParent(dsu, j);
                        if (a != b)
                            dsu[b] += dsu[a], dsu[a] = b;
                    }

            vector<int> infected(n, 0);
            for (auto &i : initial)
                if (i != k)
                    infected[findParent(dsu, i)]++;

            int total_infected = 0;
            for (int i = 0; i < n; i++)
                if (infected[i])
                    total_infected += abs(dsu[i]);

            if (total_infected < mn)
                mn = total_infected, ans = k;
        }

        return ans == -1 ? initial[0] : ans;
    }

    int findParent(vector<int> &dsu, int i) {
        int a = i;
        while (dsu[i] >= 0)
            i = dsu[i];

        if (i != a)
            dsu[a] = i;

        return i;
    }
};
