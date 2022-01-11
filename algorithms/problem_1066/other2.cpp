class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int visited = 0;
        unordered_map<int,unordered_map<int,int>>dp;
        return dfs(0,visited,workers,bikes,dp);
    }

    int dfs(int i, int &visited, vector<vector<int>>& workers, vector<vector<int>>& bikes,unordered_map<int,unordered_map<int,int>>&dp){
        if(i == workers.size()){
            return 0;
        }

        if(dp.count(i) && dp[i].count(visited)) return dp[i][visited];

        int res = INT_MAX;

        for(int j = 0; j < bikes.size(); ++j){
            if(visited & (1<<j)) continue;
            visited |= (1<<j);
            int diff = abs(bikes[j][0] - workers[i][0]) + fabs(bikes[j][1] - workers[i][1]);
            int cur = dfs(i+1,visited,workers,bikes,dp);
            if(cur != INT_MAX){
                res = min(res,cur+diff);
            }
            visited ^= (1<<j);
        }
        dp[i][visited] = res;
        return res;
    }
};
