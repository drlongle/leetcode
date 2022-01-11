class Solution {
public:
    int numTeams(vector<int>& r) {
        int N = r.size();
        vector<vector<int>> dp(N, vector<int>(2, 0));
        
        for(int i = 0; i < r.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(r[j] < r[i]) {
                    dp[i][0]++;
                }
                if(r[j] > r[i]) {
                    dp[i][1]++;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < r.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(r[j] < r[i]) {
                    res += dp[j][0];
                }
                if(r[j] > r[i]) {
                    res += dp[j][1];
                }
            }
        }
        return res;
    }
};
