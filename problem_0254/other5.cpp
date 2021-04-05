class Solution {
    void dfs(vector<int>&v, vector<vector<int>>&res, int n, int start) {
        if (n <= 1 && v.size() > 1) {
            res.push_back(v);
            return;
        }

        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                v.push_back(i);
                dfs(v, res, n/i, i);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> getFactors(int n) {
        vector<int>v;
        vector<vector<int>>res;
        dfs(v, res, n, 2);
        return res;
    }
};
