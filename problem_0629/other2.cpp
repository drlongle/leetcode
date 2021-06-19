#define mod 1000000007
#define ll long long
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<ll>> dp(2,vector<ll>(k+1,0));
        dp[0][0]=1;
        int row;ll sum;
        for(int i=1;i<n;i++){
            row=i&1;sum=0;
            for(int j=0;j<=k;j++){
                //we can only do i inversions with the current i
                sum= (sum + dp[1-row][j] - (j>i?dp[1-row][j-i-1]:0))%mod;
                if(sum<0)sum+=mod;
                dp[row][j] = sum;
            }
        }
        return dp[row][k];
    }
};
