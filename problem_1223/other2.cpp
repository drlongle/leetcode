
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int dieSimulator(int n, vector<int>& rollMax) {

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(*max_element(rollMax.begin(), rollMax.end()) + 1, vector<int>(6, -1)));
        int res = 0;
        for(int i = 0; i < 6; i ++)
            res = (res + dfs(n, 1, 1, i, rollMax, dp))% MOD;
        return res;
    }

private:
    int dfs(int n, int index, int lastfreq, int lastnum,
            const vector<int>& rollMax, vector<vector<vector<int>>>& dp){

        if(index == n) return 1;
        if(dp[index][lastfreq][lastnum] != -1) return dp[index][lastfreq][lastnum];

        int res = 0;
        for(int i = 0; i < 6; i ++)
            if(i != lastnum)
                res = (res + dfs(n, index + 1, 1, i, rollMax, dp)) % MOD;
            else if(lastfreq + 1 <= rollMax[i])
                res = (res + dfs(n, index + 1, lastfreq + 1, i, rollMax, dp)) % MOD;
        return dp[index][lastfreq][lastnum] = res;
    }
};
