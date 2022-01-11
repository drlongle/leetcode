class Solution {
public:
    int dp[1001][1001];
    int rec(int a,int l,int r,int n,vector<int>& nums,vector<int>& mul){
        if(a>=mul.size()){
            return 0;
        }
        if(l>r){
            return 0;
        }
        int i=l;
        int j=n-1-r;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans1=nums[l]*mul[a]+rec(a+1,l+1,r,n,nums,mul);
        int ans2=nums[r]*mul[a]+rec(a+1,l,r-1,n,nums,mul);
        dp[i][j]=max(ans1,ans2);
        return dp[i][j];
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=-1;
            }
        }
        return rec(0,0,n-1,n,nums,mul);
    }
};
