class Solution {
public:
    int makeArrayIncreasing(vector<int>& a1, vector<int>& a2) {
        int n = a1.size();
        sort(a2.begin(),a2.end());
        a2.erase( unique(a2.begin(),a2.end() ),a2.end());
        int m = a2.size();
        int dp[n][m+1];
        for(int i=0;i<n;i++)for(int j=0;j<=m;j++)dp[i][j] = 1000000007;
        for(int i=0;i<=m;i++){
            if(i==0)dp[0][i] = 0;
            else dp[0][i] = 1;
        }
        for(int i=1;i<n;i++){
            vector<int> mini(m,1000000007);
            int curr = 1000000007;
            for(int j=0;j<m;j++){
                curr = min(curr,dp[i-1][j+1]);
                mini[j] = curr;
            }
            for(int j=0;j<=m;j++){
                if(j==0){
                    if(a1[i]>a2[0]){
                        int k = lower_bound(a2.begin(),a2.end(),a1[i]) - a2.begin();
                        dp[i][j] = mini[k-1];
                    }
                    if(a1[i]>a1[i-1])dp[i][j] = min(dp[i][j],dp[i-1][j]);
                }
                else{
                    if(j>1)dp[i][j] = mini[j-2]+1;
                    if(a2[j-1]>a1[i-1])dp[i][j] = min(dp[i][j],dp[i-1][0]+1);
                }
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<=m;i++){
            if(dp[n-1][i]<1000000007)ans = min(ans,dp[n-1][i]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
