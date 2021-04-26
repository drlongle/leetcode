class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> mp(n);
        for (auto& x : edges) {
            mp[x[0]].push_back(x[1]);
        }

        vector<int> seen(n, 0);
        return dfs(s, d, mp, seen);
    }

private:
    bool dfs(int cur, int des, vector<vector<int>>& mp, vector<int>& seen) {
        if (seen[cur] != 0) {
            return seen[cur] == 2;
        }
        if (mp[cur].empty() && cur != des) {
            return false;
        }

        seen[cur] = 1;

        for (auto& next : mp[cur]) {
            if (!dfs(next, des, mp, seen)) return false;
        }

        seen[cur] = 2;

        return true;
    }
};
